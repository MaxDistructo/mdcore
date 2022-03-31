#include "matrix.h"
#ifdef MDCORE_MATRIX_DEBUG
#include <cstdio>
#endif

namespace mdcore {

    Matrix::Matrix()
    {
        #ifdef MDCORE_MATRIX_DEBUG
        printf("Initializing new empty Matrix");
        #endif
        arr = new std::vector<std::vector<double>*>();
        size = std::pair(0, 0);
    };
    Matrix::~Matrix()
    {
        #ifdef MDCORE_MATRIX_DEBUG
        printf("Matrix Destructor called");
        #endif
        gc();
        std::vector<std::vector<double>*> arr2 = *arr;
        for (int i = 0; i < arr->size(); i++)
        {
            delete arr2[i];
        }
        delete arr;
    };
    Matrix::Matrix(const Matrix& m)
    {
        #ifdef MDCORE_MATRIX_DEBUG
        printf("Calling Matrix Copy Constructor");
        #endif
        arr = new std::vector<std::vector<double>>();
        size = m.getSize();
        //Init the backing store, still need to figure this out
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
    void Matrix::gc()
    {
        //This is definitely not the best way to do this and can easily lead to use after free.
        //Use only if you are absolutely certain that all pointers you created are cleared.
        if(col_entries.size() > 0)
        {
            for(auto ele : col_entries)
            {
                delete ele;
            }
        }
    }
    std::vector<double>* Matrix::get_row(int row)
    {
        if(row > size.first)
        {
            return nullptr;
        }
        return arr[row-1];
    };
    //We keep track of these calls internally so we can clean them up
    std::vector<double>* Matrix::get_col(int col)
    {
        //Sanity check the caller before we even do any calculations
        if(col > size.second)
        {
            return nullptr;
        }
         //Take the first value in each row and form it into a vector for the caller
         std::vector<double>* tmp = new std::vector<double>();
         std::vector<std::vector<double>*> arr2 = *arr;
         for(int i = 0; i < size.first; i++)
         {

             tmp->push_back(*arr2[i][col]);
         }
         return tmp;
    };
    const std::pair<int, int> Matrix::getSize()
    {
        return size;
    };
    Matrix* operator*(Matrix m1, Matrix m2)
    {
        if (m1.getSize() != m2.getSize()){
            return nullptr;
        }
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