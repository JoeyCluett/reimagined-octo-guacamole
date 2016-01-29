/*
    SymbolicNumber, for use with SymbolicArithmetic
    Copyright (C) 2016  Joseph Cluett

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Author(s):
        Joseph Cluett (main author)

    File Type: implementation, SymbolicNumber

    Date Created: 1/4/2016

    Date Last Modified: 1/29/2016

    Purpose:
        This library makes the creation of symbolic numbers much easier. Note that
        this library will not perform arithmetic on symbolic numbers. That is the
        job of SymbolicArithmetic.
*/

#include "SymbolicNumber.h"
#include <iostream>

    /*Standard functions for setting up symbolic number(s)*/

SymbolicNumber::SymbolicNumber(void) {
    is_positive = true;
    is_negative = false;
    show_point = true;
}

SymbolicNumber::SymbolicNumber(char num[]) {
    //call member function to complete initialization
    SetNum(num);
}

void SymbolicNumber::SetNum(char num[]) {

    //set the appropiate sign flag
    if(num[0] == '-') {
        is_negative = true;
        is_positive = false;
    } else {
        is_negative = false;
        is_positive = true;
    }

    show_point = true;

    symnum.clear();
    bool dec_point = false;

    digits_left = 0;
    digits_right = 0;

    int size_symnum = 0;

    for(int i = 0; num[i] != 0; i++)
        size_symnum++;

    //put data in num into symnum vector
    for(int i = is_negative; i < size_symnum; i++) {
        if(num[i] == '.') {
            dec_point = true;
        } else if(!dec_point && num[i] != ',') {
            digits_left++;
            symnum.push_back(num[i]);
        } else if(dec_point && num[i] != ',') {
            digits_right++;
            symnum.push_back(num[i]);
        }
    }

    if(digits_right == 0)
        show_point = false;
}

void SymbolicNumber::SetSign(bool sign) {
    is_positive = sign;
    is_negative = !sign;
}

void SymbolicNumber::TruncateLeadingZeroes(void) {
    /* new method of truncating leading zeroes:
            1.) Count ALL leading zeroes before deleting them
            2.) Delete leading zeroes, if any
    */
    // 3 \t
    bool hit_zero = false; //set when first zero is encountered
    int num_zero = 0;
    for(int i = 0; i < digits_left; i++) {
        if((symnum.at(i) == '0') && !hit_zero) {
            num_zero++;
        } else {
            hit_zero = true;
        }
    }
    //finished counting zeroes
/*
    //delete correct amount of zeroes
    for(int i = 0; i < num_zero; i++) {
        symnum.erase(symnum.begin());
    }
*/
}

void SymbolicNumber::TruncateTrailingZeroes(void) {
    if(digits_right > 0) {
        int temp_dig = digits_right;
        for(int i = 0; (symnum.at(digits_left + temp_dig - i - 1) == '0') && (i < temp_dig); i++) {
            symnum.pop_back();
            digits_right--;
        }

        if(digits_right == 0)
            show_point = false;
    }
}

void SymbolicNumber::TruncateDecimal(void) {
    for(int i = 0; i < digits_right; i++) {
        symnum.pop_back();
    }
    digits_right = 0;
    show_point = false;
}

void SymbolicNumber::AppendLeadingZeroes(int num_zeroes) {
    if(num_zeroes < 0)
        return;

    for(int i = 0; i < num_zeroes; i++) {
        symnum.insert(symnum.begin(), '0');
    }
    digits_left += num_zeroes;
}

void SymbolicNumber::AppendTrailingZeroes(int num_zeroes) {
    for(int i = 0; i < num_zeroes; i++) {
        symnum.push_back('0');
    }
    digits_right += num_zeroes;
    show_point = true;
}

void SymbolicNumber::ShowDecimal(bool show) {
    show_point = show;
}

void SymbolicNumber::PrintSymNum(void) {
    if(is_negative)
        cout << '-';

    for(int i = 0; i < digits_left; i++) {
        cout << symnum.at(i);
    }

    if(show_point)
        cout << '.';

    for(int i = digits_left; i < symnum.size(); i++) {
        cout << symnum.at(i);
    }

    cout << endl;

    //cout << "Digits to the left of decimal point: " << digits_left << endl;
    //cout << "Digits to the right of decimal point: " << digits_right << endl << endl;
}

    /* Various getter and setter method implementations */

unsigned int SymbolicNumber::get_digits_left(void) {
    return digits_left;
}

unsigned int SymbolicNumber::get_digits_right(void) {
    return digits_right;
}

void SymbolicNumber::set_digits_left(unsigned int new_num) {
    digits_left = new_num;
}

void SymbolicNumber::set_digits_right(unsigned int new_num) {
    digits_right = new_num;
}

bool SymbolicNumber::get_sign(void) {
    return is_positive;
}

    /* Vector manipulation methods */

int SymbolicNumber::get_vector_size(void) {
    return symnum.size();
}

char SymbolicNumber::at_vector_index(int index) {
    return symnum.at(index);
}

void SymbolicNumber::clear_vector(void) {
    symnum.clear();
}

void SymbolicNumber::insert_at_begin(char digit) {
    symnum.insert(symnum.begin(), digit);
}

void SymbolicNumber::insert_at_end(char digit) {
    symnum.push_back(digit);
}

//beware of bugs in the above code, i have only proved it correct not tested it
