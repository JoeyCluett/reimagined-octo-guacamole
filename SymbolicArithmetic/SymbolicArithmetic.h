/*
    Author: Joey Cluett

    File Type: header, SymbolicArithmetic

    Date Created: 1/5/2016

    Date Last Modified: 1/5/2016

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
        SymNum* add(SymNum* augend, SymNum* addend);                //returns a pointer as a result
        SymNum* subtract(SymNum* minuend, SymNum* subtrahend);      // --
        SymNum* multiply(SymNum* multiplicand, SymNum* multiplier); // --
        SymNum* divide(SymNum* dividend, SymNum* divisor);          // --

    private:
        void align_decimal(SymNum* operand_1, SymNum* operand_2);
        int convert_char(char digit);
        char convert_int(int digit);
};

#endif //SYMBOLICARITHMETIC_H
