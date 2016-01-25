/*
    Author: Joey Cluett

    Date Created: 1/4/2016

    Date Last Modified: 1/5/2016

    Purpose:
        This program demonsrates usage of the SymbolicNumber/SymbolicArithmetic libraries

    Misc. Notes
*/

#include <iostream>
#include "SymbolicArithmetic.h"

using namespace std;

int main(int argc, char* argv[]) {

    SymNum operand_1("999999999999999999999999999999999999999999999999999999.99999999999999999999999999999999999999999999999999999999999");
    SymNum operand_2(                                                      ".00000000000000000000000000000000000000000000000000000000001");
    SymNum operand_test("22222.22222");

    SymbolicArithmetic math_engine;

    SymNum* operand_3 = math_engine.add(&operand_1, &operand_2); //function automatically truncates and re-aligns both operands if needed

    operand_1.PrintSymNum();
    operand_2.PrintSymNum();
    operand_3->PrintSymNum();

    cout << endl << endl << endl;

    cout << "Performing single digit multiplication" << endl << " ";
    operand_test.PrintSymNum();

    cout << "x          9" << endl;
    cout << "------------" << endl;

    SymNum* operand_4 = math_engine.multiply_single_digit(&operand_test, 9);

    operand_4->PrintSymNum();

    return 0;
}

//beware of bugs in the above code, i have only proved it correct not tested it
