#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
using namespace std;

class calculator
{
public:
    calculator();

    /**
     * @brief get_result - solve the operation taking care of the precedence levels
     * @param operation - list of numbers and operations
     * @return - return the result with a floating point number
     */
    float get_result(const vector <string> &operation);


private:
    /**
     * @brief shunting_yard - Reorder an operation with the shunting yard algorithm
     *(gives Reverse Polish Notation (RPN)
     * @param list_op - list of numbers and operations
     * @return - return the RPN
     */
    queue<string> shunting_yard(const vector <string> &list_op);

    /**
     * @brief read_rpn - read and solve an operation written with the RPN
     * @param rpn_op - list of numbers and operations in the RPN order
     * @return - return the result of the operation
     */
    float read_rpn(queue<string> rpn_op);

    /**
     * @brief compute - Solve a simple operation with 2 numbers and a symbol
     * @param num1 - First operand
     * @param num2 - Second operand
     * @param symbol - Operation symbol
     * @return - return the result
     */
    float compute(const float &num1, const float &num2, const string &symbol);

    /**
     * @brief is_number - Check if a string is a number
     * @param s - string number or symbol
     * @return - 1 if number, 0 if not
     */
    bool is_number(const std::string& s);

    /**
     * @brief get_precedence_level - gives the precedence level of an operation symbol
     * @param s - operation symbol
     * @return - 4 if highest, 3 if high, 2 if low
     */
    short get_precedence_level(const std::string& s);

};

#endif // CALCULATOR_H
