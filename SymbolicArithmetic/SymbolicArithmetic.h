/*
    Author: Joey Cluett

    File Type: header, SymbolicArithmetic

    Date Created: 1/5/2016

    Date Last Modified: 1/26/2016

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
        SymNum* add(     SymNum* augend,       SymNum* addend);     //returns a pointer as a result
        SymNum* subtract(SymNum* minuend,      SymNum* subtrahend); // --
        SymNum* multiply(SymNum* multiplicand, SymNum* multiplier); // --
        SymNum* divide(  SymNum* dividend,     SymNum* divisor);    // --

        /* This function is used to multiply a full symbolic number
            by a single digit. useful in larger multiplications */
        SymNum* multiply_single_digit(SymNum* main_operand, int constant_int);

    private:
        void align_decimal(SymNum* operand_1, SymNum* operand_2);
        int convert_char(char digit);
        char convert_int(int digit);
};

#endif //SYMBOLICARITHMETIC_H
