cmake_minimum_required(VERSION 3.20)
project(sklearn_c__)

set(CMAKE_CXX_STANDARD 17)

add_executable(sklearn_c__
        include/sklearn/joblib.h

        include/sklearn/Base/BaseEstimator.h
        include/sklearn/Base/BaseMetric.h

        include/sklearn/LinearModels/LinearRegression.h
        include/sklearn/LinearModels/LogisticRegression.h

        include/sklearn/Metrics/AccuracyScore.h
        include/sklearn/Metrics/MeanSquaredError.h

        include/utils/Matrix.h
        include/utils/CsvReader.h

        src/LinearModels/LinearRegression.cpp
        src/LinearModels/LogisticRegression.cpp

        src/Metrics/AccuracyScore.cpp
        src/Metrics/MeanSquaredError.cpp

        src/utils/Matrix.cpp
        src/utils/CsvReader.cpp

        src/main.cpp
        )