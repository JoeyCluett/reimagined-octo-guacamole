/*
    Author: Joey Cluett

    Date Created: 1/4/2016

    Date Last Modified: 1/27/2016

    Purpose:
        This program demonsrates usage of the SymbolicNumber/SymbolicArithmetic libraries

    Misc. Notes:
        Problem discovered 1/27/2016-
            It appears that each SymbolicArithmetic object can only perform a single complex
            arithmetic operation in its life. Dont know what is causing this but a fix is
            in the works. Solution to follow soon, hopefully
*/

#include <iostream>
#include "SymbolicArithmetic.h"

using namespace std;

int main(int argc, char* argv[]) {

    SymNum operand_1("999999999999999999999999999999999999999999999999999999.99999999999999999999999999999999999999999999999999999999999");
    SymNum operand_2(                                                      ".00000000000000000000000000000000000000000000000000000000001");
    SymNum operand_test("22000.22222");
    SymNum operand_test_2("11111.11123");

    SymbolicArithmetic* math_engine = new SymbolicArithmetic;
    SymNum* operand_3 = math_engine->add(&operand_1, &operand_2); //function automatically truncates and re-aligns both operands if needed

    operand_1.PrintSymNum();
    operand_2.PrintSymNum();
    operand_3->PrintSymNum();

    delete operand_3;

    cout << endl << endl << endl;
    cout << "Performing single digit multiplication" << endl << " ";

    operand_test.PrintSymNum();

    cout << "x          9" << endl;
    cout << "------------" << endl;

    SymNum* operand_4 = math_engine->multiply_single_digit(&operand_test, 9);
    operand_4->PrintSymNum();

    cout << endl << endl << "Multiple digit floating-point multiplication" << endl;
    operand_test . PrintSymNum();
    operand_test_2.PrintSymNum();

    SymNum* operand_5 = math_engine->multiply(&operand_test, &operand_test_2); cout << endl;
    operand_5->PrintSymNum();

    cout << endl << "Multiple digit integer multiplication" << endl;
    SymNum op_6("1111");
    SymNum op_7("1111");

    SymNum* op_8 = math_engine->multiply(&op_6, &op_6); cout << endl;
    op_8->PrintSymNum();

    return 0;
}

//beware of bugs in the above code, i have only proved it correct not tested it
