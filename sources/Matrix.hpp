#pragma once
#include <vector>
#include <iostream>
using std::vector;
namespace zich
{
class Matrix
{
    public:
    Matrix(vector<double>v,int rows, int columns):vm{v},m_rows{rows},m_columns{columns}{}//constructor

    //unary opeator on single matrix
    Matrix operator -();
    Matrix operator +();
    ///////////////////

    ////// output stream of class matrix
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    //scalar multiplication(implemented as class memeber and at global section)
    Matrix& operator* (double number);
    friend Matrix operator*(double number, const Matrix &m);
    Matrix& operator*= (double number);
    /////////////////////////////
    
    

    //incerement and decrement operators for matrices

    //prefix increment and decrement operators
    Matrix& operator ++();
    Matrix& operator --();

    //using dummy variable for postfix operators
    Matrix operator ++(int);
    Matrix operator --(int);

    /////////////////////////////////////////////////

    //comparison operators
    bool operator== (const Matrix& mat) const;//neccasary for tests
    bool operator!= (const Matrix& mat) const;//neccasary for tests
    bool operator<(const Matrix& mat)const;
    bool operator>(const Matrix& mat)const;
    bool operator<=(const Matrix& mat)const;
    bool operator>=(const Matrix& mat)const;
    ////////////////////////////////////////

    //arithmetic functional operators on 2 matrices(implemented at global scope and as class member):
    // return later friend Matrix operator +(const Matrix&,const Matrix&);
    //return later friend Matrix operator -(const Matrix&,const Matrix&);

    Matrix& operator+ (const Matrix& m);
    Matrix& operator- (const Matrix& m);
    /////////////////////////////////////

    friend Matrix operator *(const Matrix&,const Matrix&);//matrix multiplication. see steps down below:
    //steps:
    //1) check for dimensionality conditions
    //2) inner product for 2 vectors
    //3) repeat step 2 order of O(n^3)  times

    private:
    int m_rows{};
    int m_columns{};
    vector<double>vm;

    //functions for inner class functionlity
    
};
}