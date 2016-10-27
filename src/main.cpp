#include "csvreader.h"
#include "calculator.h"
#include <QCoreApplication>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Convert string written in csv file to vector of strings
    // Delimitate with commas
    vector <string> list;
    csvReader reader;
    list = reader.read_csv ("input.csv");

    if(list.empty())
        cout << "Operation is empty" << endl;
    else
    {
        // Compute the result of the operation from the vector
        calculator calc;
        float result;
        result = calc.get_result (list);

        // Write the result in a new csv file
        reader.write_csv ("output.csv", result);

        cout << "Result written inside output.csv" << endl;
    }

    return a.exec();
}
