#include "matrix.h"

namespace mdcore {

    Matrix::Matrix()
    {
        arr = new std::vector<std::vector<double>*>();
        size = std::pair(0, 0);
    };
    Matrix::~Matrix()
    {
        std::vector<std::vector<double>*> arr2 = *arr;
        for (int i = 0; i < arr->size(); i++)
        {
            delete arr2[i];
        }
        delete arr;
    };
    Matrix::Matrix(const Matrix& m)
    {
        arr = new std::vector<std::vector<double>>();
        //TODO
        throw - 1;
    };
    Matrix::Matrix(std::vector<double> vec, std::pair<int, int> size)
    {
        arr = new std::vector<std::vector<double>*>();
        this->size = size;
        std::vector<std::vector<double>*> arr2 = *arr;
        //Size is in rows/cols format
        for (int i = 0; i < size.first; i++)
        {
            //Allocate a new array to put into the master array
            std::vector<double>* tmp = new (std::nothrow) std::vector<double>();
            for (int j = (i * size.second); j < (i*size.second + size.second); j++)
            {
                tmp->push_back(vec[j]);
            }
            arr2[i] = tmp;
        }
    };
    const std::pair<int, int> Matrix::getSize()
    {
        return size;
    };
    Matrix operator*(Matrix m1, Matrix m2)
    {

    };
    Matrix operator*(double d, Matrix m)
    {
        std::vector<double> tmp = std::vector<double>();
        for(int i = 0; i < m.getSize().first; i++)
        {
            for (int j = 0; j < m.getSize().second; j++)
            {
                tmp.push_back(d * m.valueAt(i, j));
            }
        }
        return Matrix(tmp, m.getSize());
    };
    Matrix operator*(Matrix m, double d)
    {
        std::vector<double> tmp = std::vector<double>();
        for (int i = 0; i < m.getSize().first; i++)
        {
            for (int j = 0; j < m.getSize().second; j++)
            {
                tmp.push_back(d * m.valueAt(i, j));
            }
        }
        return Matrix(tmp, m.getSize());
    };
}