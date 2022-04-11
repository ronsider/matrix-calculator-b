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
    Matrix& operator -();
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    Matrix& operator* (double a);
    friend Matrix operator*(double a, const Matrix &m);
    Matrix& operator*= (double a);
    Matrix& operator+ (const Matrix& m);
    Matrix& operator- (const Matrix& m);

    //comparison operators
    bool operator== (const Matrix& mat) const;//neccasary for tests
    bool operator!= (const Matrix& mat) const;//neccasary for tests
    bool operator<(const Matrix& mat)const;
    bool operator>(const Matrix& mat)const;
    bool operator<=(const Matrix& mat)const;
    bool operator>=(const Matrix& mat)const;

    private:
    int m_rows{};
    int m_columns{};
    vector<double>vm;

};
}