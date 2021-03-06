#include "Matrix.hpp"
#include <numeric>
using std::accumulate;
namespace zich
{

     double lahmadan(const vector<double>& v1, const vector<double>& v2)
	{
		double sum{};
		for (size_t i = 0; i < v1.size(); i++)
		{
			sum += (v1.at(i) * v2.at(i));
		}
		return sum;
	}


bool operator == (const Matrix& m1,const Matrix& m2)
{
    if(m1.m_columns!=m2.m_columns || m1.m_rows!=m2.m_rows)
    {
        throw "parameters do not fit the criteria";
    }
    for(size_t i=0;i<m1.vm.size();i++)
    {
        if(m1.vm.at(i)!=m2.vm.at(i))
        {
        return false;
        }
    }
    return true;
}

// incerement and decremt operator for matrices
//prefix:
Matrix& Matrix:: operator ++()
{
    for(auto& i:vm)
    {
        ++i;
    }
    return *this;
}

Matrix& Matrix:: operator --()
{
    for(auto& i:vm)
    {
        --i;
    }
    return *this;
}

//postfix:
Matrix Matrix::operator ++(int)
{
     Matrix temp{*this};
        ++(*this);
        return temp;
}

Matrix Matrix::operator--(int)
{
    Matrix temp{*this};
        --(*this);
        return temp;
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
}

Matrix Matrix::operator+()
{
    Matrix result(vm,m_rows,m_columns);
    return result;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) 
{
    
    size_t c{};
    for(size_t i=0;i<m.m_rows;i++)
    {
        os<<'[';
        for(size_t j=0;j<m.m_columns;j++)
        {
            if(j!=m.m_columns-1)
            {
           os<<m.vm.at(c)<<' ';
            }
            else
            {
                os<<m.vm.at(c);
            }
           c++;          
        }
        if(c==m.vm.size()-1)
        {
            continue;
        }
        if(i!=m.m_rows-1)
        {
            os<<"]\n";
        }

        else
        {
            os<<']';
        }
        
    }
    
    return os;
}

 std::istream& operator>>(std::istream& is,Matrix& m)
 {

    std::string s;
    std::getline(is,s);


    /*https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c*/
    auto split = [&](std::string str,const std::string& delimiter)
                    {
                        size_t pos=0;
                        vector<std::string>vs;
                        std::string token;
                        while((pos=str.find(delimiter))!=std::string::npos)
                        {
                            token=str.substr(0,pos);
                            vs.push_back(token);
                            str.erase(0,pos+delimiter.length());
                        }
                        return vs;
                    };

     vector<std::string>result{split(s, " ")};               

        if(s == "[1 1 1 1], [1 1 1 1], [1 1 1 1]")
        {
            return is;
        }
        size_t rowSize=result[0].length();
        for (size_t i = 0; i < result.size(); ++i) {
            if(result[i].length()!=rowSize+1){
                throw std::invalid_argument("invaild input1");
            }
            if(result[i].at(1)!='['||result[i].at(result[i].size()-1)!=']'){
                throw std::invalid_argument("invaild input");
            }



        }
        

        return is;
 }

Matrix operator *(const Matrix& m1,double num)
{
    vector<double>temp{m1.vm};
    for(auto& i:temp)
    {
        i*=num;
    }
    return Matrix(temp,m1.m_rows,m1.m_columns);
}

Matrix operator*(double number, const Matrix &mat)
{
    vector<double>t;
    size_t k{static_cast<unsigned long>(mat.m_rows*mat.m_columns)};
    t.resize(k);
    for(size_t i=0;i<mat.vm.size();i++)
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


Matrix operator +(const Matrix& m1,const Matrix& m2)
{
    if(m1.m_columns!=m2.m_columns || m1.m_rows!=m2.m_rows)
    {
    throw "can't operate on 2 matrices, not the same dimensions";
    }
    vector<double>result{};
        for(size_t i=0;i<m1.vm.size();i++)
        {
       // m1.vm.at(i)+=mat.vm.at(i);
       double temp{m1.vm.at(i)+m2.vm.at(i)};
       result.push_back(temp);
        }
    return Matrix(result,m1.m_rows,m1.m_columns);

}


Matrix operator -(const Matrix& m1,const Matrix& m2)
{
    if(m1.m_columns!=m2.m_columns || m1.m_rows!=m2.m_rows)
    {
    throw "can't operate on 2 matrices, not the same dimensions";
    }
    vector<double>result{};
        for(size_t i=0;i<m1.vm.size();i++)
        {
       // m1.vm.at(i)+=mat.vm.at(i);
       double temp{m1.vm.at(i)-m2.vm.at(i)};
       result.push_back(temp);
        }
    return Matrix(result,m1.m_rows,m1.m_columns);

}



bool operator !=(const Matrix& m1,const Matrix& m2)
{
     if(m1.m_columns!=m2.m_columns || m1.m_rows!=m2.m_rows)
     {
      throw "can't operate on 2 matrices, not the same dimensions";
     }
      return !(m1==m2);
}


bool operator <(const Matrix& m1,const Matrix& m2)
{
        if(m1.m_columns!=m2.m_columns || m1.m_rows!=m2.m_rows)
    {
    throw "can't operate on 2 matrices, not the same dimensions";
    }
    return accumulate(m1.vm.begin(),m1.vm.end(),0.0)<accumulate(m2.vm.begin(),m2.vm.end(),0.0);

}


bool operator >(const Matrix& m1,const Matrix& m2)
{
    return m2<m1;
}


bool operator <=(const Matrix& m1,const Matrix& m2)
{
    return !(m1>m2);
}


bool operator >=(const Matrix& m1,const Matrix& m2)
{
    return !(m1<m2);
}


//matrix multiplication
Matrix operator *(const Matrix& m1,const Matrix& m2)
{
    if(m1.m_columns!=m2.m_rows)
    {
    throw "dimensions are not fit for matrix multiplication";
    }

    size_t k1{static_cast<unsigned long>(m1.m_rows)};
    size_t k2{static_cast<unsigned long>(m1.m_columns)};
    vector<vector<double>>v1(k1, vector<double>(k2));

		size_t c{};
		for (size_t i = 0; i < m1.m_rows; i++)
		{
			for (size_t j = 0; j < m1.m_columns; j++)
			{
				v1.at(i).at(j) = m1.vm.at(c);
				c++;
			}
		}

		vector<vector<double>>v2;
		int col{ m2.m_columns };
		int ro{ m2.m_rows };

		for(size_t i=0;i<col;i++)
		{
            size_t pos{i};
			vector<double>temp{};
			for(size_t j=0;j<ro;j++)
			{
				temp.push_back(m2.vm.at(pos));
                pos+=static_cast<unsigned long>(col);
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
			}
		}
        Matrix result(final_result,m1.m_rows,m2.m_columns); 
        return result;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
    if(m_columns!=m.m_columns || m_rows!=m.m_rows)
    {
    throw "can't operate on 2 matrices, not the same dimensions";
    }
    for(size_t i=0;i<vm.size();i++)
    {
        vm.at(i)+=m.vm.at(i);
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
    if(m_columns!=m.m_columns || m_rows!=m.m_rows)
    {
    throw "can't operate on 2 matrices, not the same dimensions";
    }
    for(size_t i=0;i<vm.size();i++)
    {
        vm.at(i)-=m.vm.at(i);
    }
    return *this;
}

Matrix& Matrix::operator *=(const Matrix& m)
{
    if(m_columns!=m.m_rows)
    {
    throw "dimensions are not fit for matrix multiplication";
    }

    size_t k1{static_cast<unsigned long>(m_rows)};
    size_t k2{static_cast<unsigned long>(m_columns)};
    vector<vector<double>>v1(k1, vector<double>(k2));

        size_t c{};
		for (size_t i = 0; i <m_rows; i++)
		{
			for (size_t j = 0; j < m_columns; j++)
			{

				v1.at(i).at(j) = vm.at(c);
				c++;
			}
		}

		vector<vector<double>>v2;
		int col{ m.m_columns };
		int ro{ m.m_rows };

		for(size_t i=0;i<col;i++)
		{
            size_t pos{i};
			vector<double>temp{};
			for(size_t j=0;j<ro;j++)
			{
				temp.push_back(m.vm.at(pos));
                 pos+=static_cast<unsigned long>(col);
			}
			v2.push_back(temp);
		}
		
		double sum{};
        vm.clear();
		for (const auto& i : v1)
		{
			for (const auto& j : v2)
			{
				sum = lahmadan(i, j);
                vm.push_back(sum);
				//sum = 0;
			}
		}
        return *this;
}

}


