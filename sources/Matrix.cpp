#include "Matrix.hpp"
namespace zich
{


Matrix& Matrix::operator-()
{
    for(auto i:vm)
    {
        i*=-1;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Matrix &m) 
{
    return os;
}
Matrix& Matrix::operator* (double num1)
{
        return *this;
}
Matrix operator*(double number, const Matrix &mat)
{
    return mat;
}
Matrix& Matrix::operator*= (double a)
{
    return *this;
}
Matrix& Matrix::operator+ (const Matrix& mat)
{
    return *this;
}
Matrix& Matrix::operator- (const Matrix& mat)
{
    return *this;
}
bool Matrix::operator== (const Matrix &mat) const
{
        return true;
}
bool Matrix::operator!= (const Matrix &mat) const
{
        return false;
}
}