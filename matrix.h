#ifndef __MATRIX_H
#define __MATRIX_H
#include <utility>
template<typename T>
class matrix{
public:
//CONSTRUCTORS
    matrix();
    matrix(const int&,const int&);
    matrix(const int&,const int&,const int&);
//DESTURCTOR
    ~matrix();
//OPERATOR OVERLOADING
    inline T& operator () (int& ,int& );
    //void operator = (matrix<T>&);
    matrix<T> operator + (matrix<T>&);
    matrix<T> operator - (matrix<T>&);
    matrix<T> operator * (matrix<T>&);
    matrix<T> operator * (const auto&);
    matrix<T> operator % (const auto&);
    void operator += (matrix<T>&);
    void operator -= (matrix<T>&);
    void operator *= (matrix<T>&);
    void operator *= (const auto&);
    void operator %= (const auto&);
//INPUT/OUTPUT
    void print();
//OTHERS
    const std::pair<int,int> dim();
    matrix<T> exp(T);
    matrix<T> mod_exp(T ,T);
private:
    T** array;
    int size_x;
    int size_y;
};
#endif