#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;

class csvReader
{
public:
    csvReader();

    /**
     * @brief read_csv - gives a list of strings from the text
     *separated by commas and written in the cvs file
     * @param filename - name of the csv file
     * @return
     */
    vector<string> read_csv (const string &filename);

    /**
     * @brief write_csv - write values inside a cvs file
     * @param filename - name of output file
     * @param value - value to include inside the file
     */
    void write_csv (const string &filename, const float &value);
};

#endif // CSVREADER_H
