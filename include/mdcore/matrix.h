#pragma once
#include <vector>
#include <utility>

namespace mdcore {
    class Matrix {
        private:
            Matrix();
            std::pair<int, int> size;
            std::vector<std::vector<double>*>* arr;
        public:
            ~Matrix();
            //Copy Constructor
            Matrix(const Matrix&);
            //Primary Constructor, a list/vector of all elements for this Matrix
            Matrix(std::vector<double>, std::pair<int, int>);
            const std::pair<int, int> getSize();
            double valueAt(int x, int y);
            Matrix operator*(Matrix);
            Matrix operator*(double);
            Matrix operator+(Matrix);
            Matrix operator-(Matrix);
            bool operator==(Matrix);
    };
}