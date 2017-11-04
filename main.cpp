#include <iostream>
#include <iomanip>
#include "CSVReader.h"

void print(const std::vector<std::string> &names, const std::vector<std::vector<double>> &numbers) {
    for (const auto &name : names) {
        std::cout << name;
        std::cout << "\t";
    }
    std::cout << std::endl;
    for (const auto &number : numbers) {
        for (double j : number) {
            std::cout << std::setw(10);
            std::cout << j;
        }
        std::cout << std::endl;

    }
    std::cout << std::endl;
}

int main() {
    std::ifstream file("baseEEBB.csv");
    //    std::ifstream file("baseEEBBbroken.csv");
    CSVReader csvReader;
    try {
        csvReader.read(file);
        const std::vector<std::string> &colNames = csvReader.getColNames();
        const std::vector<std::vector<double>> &content = csvReader.getCSVcontent();
        print(colNames, content);
    }
    catch (std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

}