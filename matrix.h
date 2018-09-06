#ifndef __MATRIX_H
#define __MATRIX_H
#include <utility>
#include <vector>
template<typename T>
class matrix{
public:
//CONSTRUCTORS
	matrix();
	matrix(const int&,const T&);
	matrix(const int&,const int&,const T&);
//DESTURCTOR
	~matrix();
//OPERATOR OVERLOADING
	inline T& operator () (const int& ,const int& );
	//matrix<T>& operator = (matrix<T>&);
	template<typename F>
	decltype(auto) operator + (matrix<F>&);
	template<typename F>
	decltype(auto) operator - (matrix<F>&);
	template<typename F>
	decltype(auto) operator * (matrix<F>&);
	template<typename F>
	decltype(auto) operator / (const F&);
	template<typename F>
	decltype(auto) operator * (const F& val);
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
	matrix<T> mod_exp(F1 ,F2); //
private:
	std::vector<std::vector<T>> __array;
	int size_x;
	int size_y;
};
#endif //MATRIX_H