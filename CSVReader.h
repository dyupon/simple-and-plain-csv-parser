//
// Created by User on 10/28/2017.
//

#ifndef CSV_PARSER_CSVREADER_H
#define CSV_PARSER_CSVREADER_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVReader {
public:
    std::istream &read(std::ifstream &f);

    const std::vector<std::string> &getColNames() const;

    const std::vector<std::vector<double>> &getCSVcontent() const;

private:
    std::vector<std::vector<double>> CSVcontent;
    std::vector<std::string> colNames;
};


#endif //CSV_PARSER_CSVREADER_H
