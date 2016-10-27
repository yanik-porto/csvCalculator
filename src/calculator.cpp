#include "calculator.h"

calculator::calculator()
{
}

float calculator::get_result(const vector<string> &operation)
{

    //Reorganize the order in the operation to have a reverse polish notation
    queue<string> output = shunting_yard(operation);

    //Read this notation and return the result
    return read_rpn(output);

}

bool calculator::is_number(const std::string& s)
{
    //Iterate over the string to check if all characters are digits
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

short calculator::get_precedence_level(const std::string& s)
{
    //Compare the string in parameter with different operation symbols
    if (!s.compare("^"))
        return 4;
    else if (!s.compare("*") || !s.compare("/"))
        return 3;
    else if (!s.compare("+") || !s.compare("-"))
        return 2;
    else
        return 0;
}

queue<string> calculator::shunting_yard(const vector<string> &list_op)
{
    //Instantiate a queue for the output and a stack for the operators
    queue<string> output;
    stack<string> operat;

    //Iterate over the vector
    typedef vector <string>::const_iterator itvec_type;
    for ( itvec_type iter = list_op.begin(); iter != list_op.end(); iter++)
    {
        //If string is a number, push to the output
        if (is_number(*iter))
            output.push (*iter);

        // If the operator has higher level than the one in top of the stack
        // Push it to the stack
        // Otherwise pop the top of the stack and push it to the output,
        //before pushing this operator to the stack
        else
        {
            if (operat.empty())
                operat.push (*iter);

            else if (get_precedence_level (operat.top()) > get_precedence_level(*iter))
            {
                output.push (operat.top());
                operat.pop();
                operat.push (*iter);
            }

            else
                operat.push (*iter);
        }
    }

    //Once the input is totally read, pop all the operator stack to the output
    while(!operat.empty())
    {
        output.push (operat.top());
        operat.pop ();
    }

    return output;
}

float calculator::compute(const float &num1, const float &num2, const string &symbol)
{
    //Perform the operation related to the symbol
    if (!symbol.compare("+"))
        return num1 + num2;
    else if (!symbol.compare("-"))
        return num1 - num2;
    else if (!symbol.compare("*"))
        return num1 * num2;
    else if (!symbol.compare("/"))
        return num1 / num2;
    else return 0;
}

float calculator::read_rpn(queue<string> rpn_op)
{
    //Instantiate a calcul stack to write the results of operations
    stack<float> calcul;
    float num1, num2;
    string symbol;

    //Read the rpn input
    while(!rpn_op.empty())
    {
        //If input is number, convert to float and push to the stack
        if(is_number (rpn_op.front()))
        {
            calcul.push (atof (rpn_op.front().c_str()));
            rpn_op.pop();
        }

        //Otherwise get the two last numbers in the stack and perform the operation
        else
        {
            symbol = rpn_op.front();
            rpn_op.pop();

            num2 = calcul.top();
            calcul.pop();
            num1 = calcul.top();
            calcul.pop();

            calcul.push (compute(num1, num2, symbol));
        }
    }

    //Output the only number in the stack
    return calcul.top();
}
