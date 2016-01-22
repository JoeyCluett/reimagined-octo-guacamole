/*
    Author: Joey Cluett

    File Type: header, SymbolicNumber

    Date Created: 1/4/2016

    Date Last Modified: 1/5/2016

    Purpose:
        This library makes the creation of symbolic numbers much easier. Note that
        this library will not perform arithmetic on symbolic numbers. That is the
        job of SymbolicArithmetic.
*/

#ifndef SYMBOLICNUMBER_H
#define SYMBOLICNUMBER_H

#define SYMNUM_POSITIVE true
#define symnum_positive true
#define SYMNUM_NEGATIVE false
#define symnum_negative false

#define SymNum SymbolicNumber

#include <vector>

using namespace std;

class SymbolicNumber {

    protected:


    public:
        SymbolicNumber(void); //default constructor
        SymbolicNumber(char num[]); //array does not decay to ptr in sizeof

        /* Misc. Functions, no math performed here */
        void SetNum(char num[]); //if default constructor is used, recommend using this to initialize vector
        void SetSign(bool sign);

        void TruncateLeadingZeroes(void);  //ex.: 000012.340000 becomes 12.340000
        void TruncateTrailingZeroes(void); //ex.: 000012.340000 becomes 000012.34
        void TruncateDecimal(void);        //ex.: 000012.340000 becomes 000012

        void AppendLeadingZeroes(int num_zeroes);  //add arbitrary number of zeroes to beginning of symnum
        void AppendTrailingZeroes(int num_zeroes); //add arbitrary number of zeroes to end of symnum

        void ShowDecimal(bool show); //determine if decimal is shown when printing symbolic number
        void PrintSymNum(void); //prints the symbolic number with (hopefully) correct placement of decimal and sign (+/-)

        //various getter/setter methods
        unsigned int get_digits_right(void);
        unsigned int get_digits_left(void);
        void set_digits_right(unsigned int new_num);
        void set_digits_left(unsigned int new_num);
        bool get_sign(void);

        //vector manipulation methods
        int get_vector_size(void);
        char at_vector_index(int index);
        void clear_vector(void);
        void insert_at_begin(char digit);
        void insert_at_end(char digit);

    private:
        vector<char> symnum; //structure that holds actual digits

        bool is_negative;
        bool is_positive;
        bool show_point; //set/reset with ShowDecimal()

        unsigned int digits_right; //number of digits to the right of the decimal point
        unsigned int digits_left;  //number of digits to the left of the decimal point


};

#endif // SYMBOLICNUMBER_H
