//
// Created by Мичил Егоров on 02.01.2022.
//


#include <iostream>
#include "../../include/utils/CsvReader.h"

CsvReader::CsvReader(const std::string& filePath) : filePath(filePath){}

Matrix CsvReader::read() {
    std::ifstream file(filePath);

    std::vector<std::vector<double>> data;
    double number;
    char del;

    if(file) {
        while(file) {
            file >> number;
            if(!data.empty() && file.peek() == ',') {
                file >> del;
                data.back().push_back(number);
            }else{
                if(!data.empty()) {
                    data.back().push_back(number);
                    data.emplace_back();
                }
                if(data.empty()) {
                    file >> del;
                    data.emplace_back(1, number);
                }
            }
        }
    }else {
        file.close();
        throw std::invalid_argument("Cannot find the " + filePath + " file");
    }
    file.close();

    data.pop_back(); data.pop_back();

    return Matrix(data);
}