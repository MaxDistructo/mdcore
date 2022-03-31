#pragma once
#include <vector>
#include <utility>

namespace mdcore {
    class Matrix {
        private:
            Matrix();
            std::pair<int, int> size;
            std::vector<std::vector<double>*>* arr;
            std::vector<std::vector<double>*> col_entries = std::vector<std::vector<double>*>();
        public:
            ~Matrix();
            //Copy Constructor
            Matrix(const Matrix&);
            //Primary Constructor, a list/vector of all elements for this Matrix
            Matrix(std::vector<double>, std::pair<int, int>);
            const std::pair<int, int> getSize();
            double valueAt(int x, int y);
            std::vector<double>* get_row(int);
            std::vector<double>* get_col(int);
            void gc();
            Matrix* operator*(Matrix);
            Matrix operator*(double);
            Matrix operator+(Matrix);
            Matrix operator-(Matrix);
            bool operator==(Matrix);
    };
}