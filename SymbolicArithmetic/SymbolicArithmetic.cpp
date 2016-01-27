/*
    Author: Joey Cluett

    File Type: implementation, SymbolicArithmetic

    Date Created: 1/5/2016

    Date Last Modified: 1/27/2016

    Purpose:
        To perform arbitrary precision arithmetic on two symbolic numbers

    Note:
        This library requires quite a bit of memory. The larger the number you want to
        use, the more memory you will need. The actual symbolic number digits are stored
        in std::vector 's.
*/

#include <iostream>
#include "SymbolicNumber.h"
#include "SymbolicArithmetic.h"

using namespace std;

SymNum* SymbolicArithmetic::add(SymNum* augend, SymNum* addend) {
    cout << "\tStarting add..." << endl;
    SymNum* result = new SymNum;
    //add appropiate number of zeroes to numbers
    cout << "\tAligning numbers..." << endl;
    align_decimal(augend, addend);

    result->clear_vector();

    //augend->PrintSymNum();
    //addend->PrintSymNum();
    int carry_over = 0;
    int temp_result = 0;

    cout << "\tPreparing for addition operation..." << endl << endl;
    //actual addition operation
    if(augend->get_sign() && addend->get_sign()) {
        for(int i = augend->get_vector_size() - 1; i >= 0; i--) {
            //cout << "\t\tIn add, iterating over vector: " << (int) i << endl;
            temp_result = convert_char(augend->at_vector_index(i)) + convert_char(addend->at_vector_index(i));
            temp_result += carry_over;
            //cout << "Decimal " << temp_result << endl; //for debugging

            //test for carry
            if(temp_result >= 10) {
                carry_over = 1;
                temp_result -= 10;
            } else {
                carry_over = 0;
            }

            char c = convert_int(temp_result);
            //cout << "Character " << c << endl; //for debugging
            result->insert_at_begin(c);
        }
    }

    result->set_digits_right(augend->get_digits_right());
    result->set_digits_left(augend->get_digits_left());

    //test to see if we have a carry at the front of the digits
    if(carry_over) {
        result->set_digits_left(result->get_digits_left() + 1); //increment digits_left if needed
        result->insert_at_begin('1');
    }

    //result->PrintSymNum();
    //result->SetSign(SYMNUM_POSITIVE);

    cout << "\tEnding add..." << endl;

    return result;

}

SymNum* SymbolicArithmetic::subtract(SymNum* minuend, SymNum* subtrahend) {
    ;
}

SymNum* SymbolicArithmetic::multiply(SymNum* multiplicand, SymNum* multiplier) {
    SymNum* result = new SymNum;
    SymNum* temp_result = new SymNum;
    SymNum* temp_result_2 = new SymNum;

    align_decimal(multiplicand, multiplier);

    //multiplicand_vector_size
    int mvs = multiplicand->get_vector_size();

    //multiply and add all whole numbers, then shift at the end
    for(int i = multiplier->get_vector_size()-1; i >= 0; i--) {
        cout << endl << "Index of multiplier: " << (int) i << endl;
        //ensure that we are not allocating excessive memory
        delete temp_result;

        cout << endl << "Multiplying by single digit..." << endl;
        //retrieve result of single digit muliplication
        temp_result = multiply_single_digit(multiplicand, convert_char(multiplier->at_vector_index(i)));

        cout << "Print after multiply: ";
        temp_result->PrintSymNum();

        cout << "Shifting left..." << endl;
        //shift temp result left appropiate number of places
        temp_result->AppendTrailingZeroes(mvs - i - 1);
        temp_result->set_digits_right(temp_result->get_digits_right() - (mvs - i - 1));
        temp_result->set_digits_left(temp_result->get_vector_size() - temp_result->get_digits_right());

        cout << "Print after left-shift: ";
        temp_result->PrintSymNum();

        cout << "Deallocating memory..." << endl;
        //memory cleanup (must be done after every iteration or memory will quickly fill up
        temp_result_2 = add(result, temp_result);
        result= temp_result_2;
        temp_result_2 = 0;

        cout << "Result after iteration: ";
        result->PrintSymNum();
    }

    delete temp_result; //last memory deallocation

    //final left shift
    result->set_digits_right(multiplicand->get_digits_right() + multiplier->get_digits_right());
    result->set_digits_left(result->get_vector_size() - result->get_digits_right());

    cout << "Result after final left-shift: ";
    result->PrintSymNum();

    return result;
}

SymNum* SymbolicArithmetic::divide(SymNum* dividend, SymNum* divisor) {
    ;
}

void SymbolicArithmetic::align_decimal(SymNum* operand_1, SymNum* operand_2) {
    cout << "\t\tIn align_decimal function..." << endl; //debug

    cout << "\t\tTruncating first operand..." << endl; //debug
    //truncate both numbers
    operand_1->TruncateLeadingZeroes();
    operand_1->TruncateTrailingZeroes();

    cout << "\t\tTruncating second operand..." << endl; //debug
    operand_2->TruncateLeadingZeroes();
    operand_2->TruncateTrailingZeroes();

    unsigned int op_1 = operand_1->get_digits_left(),
                 op_2 = operand_2->get_digits_left();

    cout << "\t\tTesting digits_left..." << endl; //debug
    //test leading zeroes first
    if(op_1 != op_2) {
        if(op_1 > op_2) {
            //operand_1 extends further to the left than operand_2
            operand_2->AppendLeadingZeroes(op_1 - op_2);
        } else if(op_2 > op_1) {
            //operand_2 extends further to the right than operand_1
            operand_1->AppendLeadingZeroes(op_2 - op_1);
        }
    }

    op_1 = operand_1->get_digits_right();
    op_2 = operand_2->get_digits_right();

    cout << "\t\tTesting digits_right..." << endl; //debug
    //test trailing zeroes
    if(op_1 != op_2) {
        if(op_1 > op_2) {
            //operand_1 extends further to the right than operand_2
            operand_2->AppendTrailingZeroes(op_1 - op_2);
        } else if(op_2 > op_1) {
            //operand_2 extends further to the right than operand_1
            operand_1->AppendTrailingZeroes(op_2 - op_1);
        }
    }
}

int SymbolicArithmetic::convert_char(char digit) { //char-to-decimal
    return (int)digit - 48;
}

char SymbolicArithmetic::convert_int(int digit) {  //decimal-to-char
    switch(digit) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            return 'x';
    }
}

SymNum* SymbolicArithmetic::multiply_single_digit(SymNum* main_operand, int constant_int) {

    cout << "In MSD function..." << endl;
    //test if constant_int is in valid range
    if(constant_int < 0 || constant_int > 9)
        return 0;

    SymNum* result = new SymNum;
    result->clear_vector();

    int carry_over = 0;
    int temp_result = 0, ones_ph = 0;

    //iterate through main_operand, multiplying each digit by multiplier
    for(int i = main_operand->get_vector_size() - 1; i >= 0; i--) {
        temp_result = convert_char(main_operand->at_vector_index(i)) * constant_int;
        temp_result += carry_over;
        ones_ph = temp_result % 10;
        result->insert_at_begin(convert_int(ones_ph));
        carry_over = (temp_result - ones_ph) / 10; //base ten right shift
    }

    if(carry_over)
        result->insert_at_begin(convert_int(carry_over));

    //set variables controlling where decimal point appears
    result->set_digits_right(main_operand->get_digits_right());
    result->set_digits_left(result->get_vector_size() - main_operand->get_digits_right());
    return result;
}


















