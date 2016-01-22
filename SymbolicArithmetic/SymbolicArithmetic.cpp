/*
    Author: Joey Cluett

    File Type: implementation, SymbolicArithmetic

    Date Created: 1/5/2016

    Date Last Modified: 1/5/2016

    Purpose:

    Note:

*/

#include <iostream>
#include "SymbolicNumber.h"
#include "SymbolicArithmetic.h"

using namespace std;

SymNum* SymbolicArithmetic::add(SymNum* augend, SymNum* addend) {
    SymNum* result = new SymNum;
    //add appropiate number of zeroes to numbers
    align_decimal(augend, addend);

    result->clear_vector();

    //augend->PrintSymNum();
    //addend->PrintSymNum();
    int carry_over = 0;
    int temp_result = 0;

    //actual addition operation
    if(augend->get_sign() && addend->get_sign()) {
        for(int i = augend->get_vector_size() - 1; i >= 0; i--) {
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

    return result;

}

SymNum* SymbolicArithmetic::subtract(SymNum* minuend, SymNum* subtrahend) {
    ;
}

SymNum* SymbolicArithmetic::multiply(SymNum* multiplicand, SymNum* multiplier) {
    SymNum* result = new SymNum;
    align_decimal(multiplicand, multiplier);
    result->clear_vector();
}

SymNum* SymbolicArithmetic::divide(SymNum* dividend, SymNum* divisor) {
    ;
}

void SymbolicArithmetic::align_decimal(SymNum* operand_1, SymNum* operand_2) {
    //truncate both numbers
    operand_1->TruncateLeadingZeroes();
    operand_1->TruncateTrailingZeroes();

    operand_2->TruncateLeadingZeroes();
    operand_2->TruncateTrailingZeroes();

    unsigned int op_1 = operand_1->get_digits_left(),
                 op_2 = operand_2->get_digits_left();

    //test leading zeroes first
    if(op_1 > op_2) {
        //operand_1 extends further to the left than operand_2
        operand_2->AppendLeadingZeroes(op_1 - op_2);
    } else if(op_2 > op_1) {
        //operand_2 extends further to the right than operand_1
        operand_1->AppendLeadingZeroes(op_2 - op_1);
    }

    op_1 = operand_1->get_digits_right();
    op_2 = operand_2->get_digits_right();

    //test trailing zeroes
    if(op_1 > op_2) {
        //operand_1 extends further to the right than operand_2
        operand_2->AppendTrailingZeroes(op_1 - op_2);
    } else if(op_2 > op_1) {
        //operand_2 extends further to the right than operand_1
        operand_1->AppendTrailingZeroes(op_2 - op_1);
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




















