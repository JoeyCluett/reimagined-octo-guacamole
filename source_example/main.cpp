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

    SymbolicArithmetic math_engine;

    SymNum* operand_3 = math_engine.add(&operand_1, &operand_2); //function automatically truncates and re-aligns both operands if needed

    operand_1.PrintSymNum();
    operand_2.PrintSymNum();
    operand_3->PrintSymNum();

    return 0;
}

//beware of bugs in the above code, i have only proved it correct not tested it
