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
	template<typename F>
	matrix<T> operator + (matrix<F>&);
	template<typename F>
	matrix<T> operator - (matrix<F>&);
	template<typename F>
	matrix<T> operator * (matrix<F>&);
	template<typename F>
	matrix<T> operator / (const F&);
	template<typename F>
	matrix<T> operator * (const F&);
	template<typename F>
	matrix<T> operator % (const F&);
	template<typename F>
	void operator += (matrix<F>&);
	template<typename F>
	void operator -= (matrix<F>&);
	template<typename F>
	void operator *= (matrix<F>&);
	template<typename F>
	void operator *= (const F&);
	template<typename F>
	void operator /= (const F&);
	template<typename F>
	void operator %= (const F&);
//INPUT/OUTPUT
	void print();
//OTHERS
	const std::pair<int,int> dim();
	template<typename F>
	matrix<T> exp(F);
	template<typename F1,typename F2>
	matrix<F2> mod_exp(F1 ,F2); //
private:
	T** __array;
	int size_x;
	int size_y;
};
#endif