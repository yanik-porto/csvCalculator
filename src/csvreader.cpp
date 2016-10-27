#include "csvreader.h"

csvReader::csvReader()
{
}

vector<string> csvReader::read_csv(const string &filename)
{
    // Open a stream to the file
    ifstream file (filename.c_str());
    string op;
    vector <string> list_op;

    // Check if it is open
    if (!file.is_open()) {cerr <<"ERROR while opening " <<filename<<endl; return list_op;}

    // read a string until next comma and push it to the vector
    while (getline (file, op, ','))
    {
        list_op.push_back (op);
    }

    return list_op;
}

void csvReader::write_csv(const string &filename, const float &value)
{
    // Open a stream to the file
    ofstream file (filename.c_str());

    // Check if it is open
    if (!file.is_open()) {cerr <<"ERROR while opening " <<filename<<endl;}

    string str_val;
    ostringstream buff;
    buff << value;
    str_val = buff.str();

    file << str_val.c_str();
}
