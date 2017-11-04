//
// Created by User on 10/28/2017.
//

#include "CSVReader.h"


std::istream &CSVReader::read(std::ifstream &f) {
    std::string str, s;
    int countCells = 0, count = 0;
    std::stringstream row;
    getline(f, str);
    row << str;
    while (getline(row, s, ',')) {
        if (!s.empty()) {
            ++countCells;
            colNames.push_back(s);
        }
    }
    std::vector<double> temp;
    while (getline(f, str)) {
        count = 0;
        row.clear();
        row << str;
        while (getline(row, s, ',')) {
            if (!s.empty()) {
                try {
                    temp.push_back(stod(s));
                }
                catch (const std::invalid_argument &ia) {
                    throw std::invalid_argument("Invalid argument exception");
                }
                ++count;
            }
        }
        if (count != countCells) throw std::length_error("Parse process exception");
        CSVcontent.push_back(temp);
        temp.clear();
    }

}

const std::vector<std::string> &CSVReader::getColNames() const {
    return colNames;
}

const std::vector<std::vector<double>> &CSVReader::getCSVcontent() const {
    return CSVcontent;
}

