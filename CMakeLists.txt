cmake_minimum_required(VERSION 3.20)
project(sklearn_c__)

set(CMAKE_CXX_STANDARD 17)

add_executable(sklearn_c__
        include/sklearn/joblib.h
        include/sklearn/Base/BaseEstimator.h
        include/sklearn/LinearModels/LinearRegression.h
        include/utils/Matrix.h
        src/LinearModels/LinearRegression.cpp
        src/utils/Matrix.cpp
        src/main.cpp
        src/joblib.cpp
        )