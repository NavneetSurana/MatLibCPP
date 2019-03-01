#ifndef __MATRIX_H
#define __MATRIX_H
#include <vector>
template<typename T>
class matrix{
public:
//CONSTRUCTORS
	matrix();
	matrix(const int&,const T&);
	matrix(const int&,const int&,const T&);
	matrix(const std:: vector< std ::vector<T> > & );
	matrix(const std:: initializer_list< std:: initializer_list<T> > & );
//DESTURCTOR
	~matrix();
//OPERATOR OVERLOADING
	inline T& operator () (const int& ,const int& );
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
	matrix<T> exp(F,long long int MOD=-1);
private:
	std::vector<std::vector<T>> __array;
	int size_x;
	int size_y;
	long long int __mod;
};
#endif //MATRIX_H