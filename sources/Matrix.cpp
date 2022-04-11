#include "Matrix.hpp"
#include <numeric>
using std::accumulate;
namespace zich
{



// incerement and decremt operator for matrices
//prefix:
Matrix& Matrix:: operator ++()
{
    for(auto i:vm)
    {
        ++i;
    }
    return *this;
}

Matrix& Matrix:: operator --()
{
    for(auto i:vm)
    {
        --i;
    }
    return *this;
}

//postfix:
Matrix Matrix::operator++(int)
{
    for(auto i:vm)
    {
        i++;
    }
    return *this;

}

Matrix Matrix::operator--(int)
{
    for(auto i:vm)
    {
        i--;
    }
    return *this;

}
///////////////////////////////////////////////
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
    for(int i=0;i<m.m_rows;i++)
    {
        os<<'[';
        for(int j=0;j<m.m_columns;j++)
        {
           os<<' '<<m.vm.at(j); 
        }
        os<<"]\n";
    }
    return os;
}
Matrix& Matrix::operator* (double num1)
{
    for(auto i:vm)
    {
        i*=num1;
    }
    return *this;
}
Matrix operator*(double number, const Matrix &mat)
{
    vector<double>t;
    t.resize(mat.m_rows*mat.m_columns);
    for(int i=0;i<mat.vm.size();i++)
    {
        t.at(i)=mat.vm.at(i)*number;
    }
    Matrix m{t,mat.m_rows,mat.m_columns};
    return m;
}
Matrix& Matrix::operator*= (double a)
{
    for(auto i:this->vm)
    {
        i*=a;
    }
    return *this;
}
Matrix& Matrix::operator+ (const Matrix& mat)
{
    if(m_columns!=mat.m_columns || m_rows!=mat.m_rows)
    throw "can't operate on 2 matrices, not the same dimensions";

    for(int i=0;i<mat.vm.size();i++)
    {
        vm.at(i)+=mat.vm.at(i);
    }
    return *this;
}
Matrix& Matrix::operator- (const Matrix& mat)
{
   if(m_columns!=mat.m_columns || m_rows!=mat.m_rows)
    throw "can't operate on 2 matrices, not the same dimensions";

    for(int i=0;i<mat.vm.size();i++)
    {
        vm.at(i)-=mat.vm.at(i);
    }
    return *this;
}



//Required comparison operators
bool Matrix::operator== (const Matrix &mat) const
{
        if(m_columns!=mat.m_columns || m_rows!=mat.m_rows)
    throw "can't operate on 2 matrices, not the same dimensions";

    for(int i=0;i<mat.vm.size();i++)
    {
        if(vm.at(i)!=mat.vm.at(i))
        return false;
    }
    return true;
}

//implementing != using operator !(operator ==)
bool Matrix::operator!= (const Matrix &mat) const
{
    // if(m_columns!=mat.m_columns || m_rows!=mat.m_rows)
    // throw "can't operate on 2 matrices, not the same dimensions";
    //  for(int i=0;i<mat.vm.size();i++)
    // {
    //     if(vm.at(i)==mat.vm.at(i))
    //     return false;
    // }
    // return true;   
    return !(*this==mat);
}

bool Matrix:: operator<(const Matrix& mat)const
{
    if(m_columns!=mat.m_columns || m_rows!=mat.m_rows)
    throw "can't operate on 2 matrices, not the same dimensions";

    return accumulate(vm.begin(),vm.end(),0)<accumulate(vm.begin(),vm.end(),0);
}

//implementing > using operator < with parametrs flipped
bool Matrix:: operator>(const Matrix& mat)const
{
    return mat<*this;
}

//this operator can be implemented as !(operator<)
bool Matrix:: operator<=(const Matrix& mat)const
{
    return !(*this<mat);
}

//this operator can be implemented as !(operator>)
bool Matrix:: operator >=(const Matrix& mat)const
{
    return !(*this>mat);
}


}


