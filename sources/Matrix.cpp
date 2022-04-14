#include "Matrix.hpp"
#include <numeric>
using std::accumulate;
namespace zich
{

     double lahmadan(const vector<double>& v1, const vector<double>& v2)
	{
		double sum{};
		for (int i = 0; i < v1.size(); i++)
		{
			sum += (v1[i] * v2[i]);
		}
		return sum;
	}



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
Matrix Matrix::operator-()
{
    vector<double>temp;
    for(auto i:vm)
    {
        i*=-1;
        temp.push_back(i);
    }
    Matrix result(temp,m_rows,m_columns);
    return result;
    //return *this;
}

Matrix Matrix::operator+()
{
    // for(auto i:vm)
    // {
    //     i*=-1;
    // }
    Matrix result(vm,m_rows,m_columns);
    //return *this;
    return result;
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

Matrix& Matrix::operator* (double number)
{
    for(auto& i:vm)
    {
        i*=number;
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

Matrix& Matrix::operator*= (double number)
{
    for(auto& i:vm)
    {
        i*=number;
    }
    return *this;
}

Matrix& Matrix::operator+ (const Matrix& mat)
{
    if(m_columns!=mat.m_columns || m_rows!=mat.m_rows)
    {
    throw "can't operate on 2 matrices, not the same dimensions";
    }

    for(int i=0;i<mat.vm.size();i++)
    {
        vm.at(i)+=mat.vm.at(i);
    }
    return *this;
}

Matrix& Matrix::operator- (const Matrix& mat)
{
   if(m_columns!=mat.m_columns || m_rows!=mat.m_rows)
   {
    throw "can't operate on 2 matrices, not the same dimensions";
   }

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
        {
    throw "can't operate on 2 matrices, not the same dimensions";
        }

    for(int i=0;i<mat.vm.size();i++)
    {
        if(vm.at(i)!=mat.vm.at(i))
        {
        return false;
        }
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
    {
    throw "can't operate on 2 matrices, not the same dimensions";
    }

    return accumulate(vm.begin(),vm.end(),0.0)<accumulate(vm.begin(),vm.end(),0.0);
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


//matrix multiplication
Matrix operator *(const Matrix& m1,const Matrix& m2)
{
    if(m1.m_columns!=m2.m_rows)
    {
    throw "dimensions are not fit for matrix multiplication";
    }

    vector<vector<double>>v1(m1.m_rows, vector<double>(m1.m_columns));

		int c{};
		for (int i = 0; i < m1.m_rows; i++)
		{
			for (int j = 0; j < m1.m_columns; j++)
			{

				v1.at(i).at(j) = m1.vm.at(c);
				c++;
			}
		}

		vector<vector<double>>v2;
		int col{ m2.m_columns };
		int ro{ m2.m_rows };

		for(int i=0;i<col;i++)
		{
			int pos{ i };
			vector<double>temp{};
			for(int j=0;j<ro;j++)
			{
				temp.push_back(m2.vm.at(pos));
				pos += col;
			}
			v2.push_back(temp);
		}
		
		vector<double>final_result{};
		double sum{};
		for (const auto& i : v1)
		{
			for (const auto& j : v2)
			{
				sum = lahmadan(i, j);
				final_result.push_back(sum);
				//sum = 0;
			}
		}
		//prt_mat(final_result);  
        Matrix result(final_result,m1.m_rows,m2.m_columns); 
        return result;
}


}


