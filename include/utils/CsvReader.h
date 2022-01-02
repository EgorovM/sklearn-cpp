//
// Created by Мичил Егоров on 02.01.2022.
//

#ifndef SKLEARN_C___CSVREADER_H
#define SKLEARN_C___CSVREADER_H

#include <string>
#include <fstream>
#include "Matrix.h"

class CsvReader {
public:
    CsvReader(const std::string&);
    ~CsvReader() = default;
    Matrix read();
private:
    std::string filePath;
};
#endif //SKLEARN_C___CSVREADER_H
