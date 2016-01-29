/*
    SymbolicArithetic, arbitrary preision symbolic arithmetic
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

    File Type: header, SymbolicArithmetic

    Date Created: 1/5/2016

    Date Last Modified: 1/29/2016

    Purpose:
        This library uses the SymbolicNumber library to perform symbolic
        calculations on arbitrarily large numbers
*/

#ifndef SYMBOLICARITHMETIC_H
#define SYMBOLICARITHMETIC_H

#include "SymbolicNumber.h"

class SymbolicArithmetic : private SymbolicNumber {

    public:
        //different basic math operations
        SymNum* add     (SymNum* augend,       SymNum* addend);     //returns a pointer as a result
        SymNum* subtract(SymNum* minuend,      SymNum* subtrahend); // --
        SymNum* multiply(SymNum* multiplicand, SymNum* multiplier); // --
        SymNum* divide  (SymNum* dividend,     SymNum* divisor);    // --

        /* This function is used to multiply a full symbolic number
            by a single digit. useful in larger multiplications */
        SymNum* multiply_single_digit(SymNum* main_operand, int constant_int);

    private:
        void align_decimal(SymNum* operand_1, SymNum* operand_2);
        int convert_char(char digit);
        char convert_int(int digit);
};

#endif //SYMBOLICARITHMETIC_H
