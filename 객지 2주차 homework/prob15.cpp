#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("table.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open())
    {
        cerr << "Unable to open input file!" << endl;
        return 1;
    }

    if (!outputFile.is_open())
    {
        cerr << "Unable to create output file!" << endl;
        return 1;
    }

    string line;
    int rows, cols;

    if (getline(inputFile, line))
    {
        istringstream iss(line);
        iss >> rows >> cols;
    }
    else
    {
        cerr << "Invalid input file format!" << endl;
        return 1;
    }

    for (int i = 0; i < rows; ++i)
    {
        if (!getline(inputFile, line))
        {
            cerr << "Invalid input file format!" << endl;
            return 1;
        }

        istringstream rowStream(line);
        vector<string> rowData;

        for (int j = 0; j < cols; ++j)
        {
            string cell;
            if (!getline(rowStream, cell, '&'))
            {
                cerr << "Invalid input file format!" << endl;
                return 1;
            }

            cell.erase(0, cell.find_first_not_of(" \t\r\n"));
            cell.erase(cell.find_last_not_of(" \t\r\n") + 1);
            rowData.push_back(cell);
        }

        for (const auto& cell : rowData) {
            outputFile << cell << " ";
        }
        outputFile << endl;
    }

    cout << "Output has been written to output.txt" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}

