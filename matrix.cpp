#include "matrix.h"
#include <iostream>

template <typename T>
void matrix<T>::print(){
	for(int i=0;i<size_x;i++){
		for(int j=0;j<size_y;j++){
			std::cout<<__array[i][j]<<' ';
		}
		std::cout<<std::endl;
	}
}


			//CONSTRUCTORS
//----------------------------------//
template <typename T>
matrix<T>:: matrix(){
	this->size_x=0;
	this->size_y=0;
	this->__array=NULL;
}
template <typename T>
matrix<T>:: matrix(const int& n,const int& m): __array(new T*[n]),size_x(n),size_y(m){
	for(int i=0;i<n;i++){
		__array[i]=new T[m];
		for(int j=0;j<m;j++){
			__array[i][j]=0;
		}
	}
}
template <typename T>
matrix<T>:: matrix(const int& n,const int& m,const int& val): __array(new T*[n]),size_x(n),size_y(m){
	for(int i=0;i<n;i++){
		__array[i]=new T[m];
		for(int j=0;j<m;j++){
			__array[i][j]=val;
		}
	}
}
//---------------------------------//

	//DESTURCTOR
//------------------//
template <typename T>
matrix<T>:: ~matrix(){
	//std::cout<<"DESTURCTOR"<<std::endl;
	/*for(int i=0;i<size_x;i++){
		delete[] this->__array[i];
	}
	delete[] this->__array;*/
}
//-----------------//


	//OPERATOR OVERLOADING
//---------------------------//
//OPERATOR ()
template<typename T>
inline T& matrix<T>::operator ()(int& i,int& j){
	return  this->__array[i][j];
}

//OPERATOR *
template<typename T>
template<typename F>
matrix<T> matrix<T>::operator * (matrix<F>& other){
	if(this->size_y!=other.dim().first){
		throw "Dimensions are not valid";
	}
	else{

		int p=this->size_x,q=this->size_y,r=other.dim().second;
		matrix<T> temp(p,q);
		for(int i=0;i<p;i++){
			for(int j=0;j<r;j++){
				for(int k=0;k<q;k++){
					temp(i,j)+=this->__array[i][k]*other(k,j);
				}
			}
		}
		return temp;
	}
}
//OPERATOR * for consts
template<typename T>
template<typename F>
matrix<T> matrix<T>::operator * (const F& val){
	int p=this->size_x,q=this->size_y;
	matrix<T> temp(p,q);
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++){
			temp(i,j)=this->__array[i][j]*val;
		}
	}
	return temp;
}
//OPERATOR / for consts
template<typename T>
template<typename F>
matrix<T> matrix<T>::operator / (const F& val){
	if(val==0){
		std::cerr<<"In File "<<__FILE__<<"\nDivision by zero in / operation in Line "<<__LINE__<<std::endl;
		throw val;
	}
	int p=this->size_x,q=this->size_y;
	matrix<T> temp(p,q);
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++){
			temp(i,j)=this->__array[i][j]/val;
		}
	}
	return temp;
}
//OPERATOR +
template<typename T>
/*template<typename F>*/
matrix<T> matrix<T>::operator + (matrix<T>& other){
	if(this->size_x!=other.dim().first && this->size_y!=other.dim().second){
		throw "Dimensions are not valid";
	}
	else{
		int p=this->size_x,q=this->size_y;
		matrix<T> temp(p,q);
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				temp(i,j)=this->__array[i][j]+other(i,j);
			}
		}
		return temp;
	}
}
//OPERATOR -
template<typename T>
template<typename F>
matrix<T> matrix<T>::operator - (matrix<F>& other){
	if(this->size_x!=other.dim().first && this->size_y!=other.dim().second){
		throw "Dimensions are not valid";
	}
	else{
		int p=this->size_x,q=this->size_y;
		matrix<T> temp(p,q);
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				temp(i,j)=this->__array[i][j]-other(i,j);
			}
		}
		return temp;
	}
}
//OPERATOR %
template<typename T>
template<typename F>
matrix<T> matrix<T>::operator % (const F& val){
	if(val==0){
		std::cerr<<"In File "<<__FILE__<<"\nDivision by zero in % operation in Line "<<__LINE__<<std::endl;
		throw val;
	}
	int p=this->size_x,q=this->size_y;
	matrix<T> temp(p,q);
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++){
			temp(i,j)=this->__array[i][j]%val;
		}
	}
	return temp;
}


//OPERATOR *=
template<typename T>
template<typename F>
void matrix<T>::operator *= (matrix<F>& other){
	*this=*this*other;
}
//OPERATOR *= for constsṭ
template<typename T>
template<typename F>
void matrix<T>::operator *= (const F& val){
	for(int i=0;i<this->size_x;i++){
		for (int j = 0; j <this->size_y; j++)
		{
			this->__array[i][j]*=val;
		}
	}
}
//OPERATOR *= for consts
template<typename T>
template<typename F>
void matrix<T>::operator /= (const F& val){
	if(val==0){
		std::cerr<<"In File "<<__FILE__<<"\nDivision by zero in /= operation in Line "<<__LINE__<<std::endl;
		throw val;
	}
	for(int i=0;i<this->size_x;i++){
		for (int j = 0; j <this->size_y; j++)
		{
			this->__array[i][j]/=val;
		}
	}
}
//OPERATOR +=
template<typename T>
template<typename F>
void matrix<T>::operator += (matrix<F>& other){
	if(this->size_x!=other.dim().first && this->size_y!=other.dim().second){
		throw "Dimensions are not valid";
	}
	else{
		int p=this->size_x,q=this->size_y;
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				this->__array[i][j]+=other(i,j);
			}
		}
	}
}
//OPERATOR -=
template<typename T>
template<typename F>
void matrix<T>::operator -= (matrix<F>& other){
	if(this->size_x!=other.dim().first && this->size_y!=other.dim().second){
		throw "Dimensions are not valid";
	}
	else{
		int p=this->size_x,q=this->size_y;
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				this->__array[i][j]-=other(i,j);
			}
		}
	}
}
//OPERATOR %=
template<typename T>
template<typename F>
void matrix<T>::operator %= (const F& val){
	if(val==0){
		std::cerr<<"In File "<<__FILE__<<"\nDivision by zero in %= operation in Line "<<__LINE__<<std::endl;
		throw val;
	}
	for(int i=0;i<this->size_x;i++){
		for (int j = 0; j <this->size_y; j++)
		{
			this->__array[i][j]%=val;
		}
	}
}
//--------------------------//


	//OTHER FUNCTIONS//
//--------------------------//

//FUNCTION FOR GETTING DIMENSIONS
template<typename T>
const std::pair<int,int> matrix<T>::dim(){
	return std::make_pair(size_x,size_y);
	//
}
//EXPONENTIATION
template<typename T>
template<typename F>
matrix<T> matrix<T>::exp(F n){
	matrix<T> ans(this->size_x,this->size_y);
	matrix<T> temp=*this;
	for(int i=0;i<this->size_x;i++){
		ans(i,i)=1LL;
	}

	while(n){
		if(n&1) ans*=temp;
		temp*=temp;
		n/=2.0;
	}
	return ans;
}

template<typename T>
template<typename F1,typename F2>
matrix<F2> matrix<T>::mod_exp(F1 n,F2 MOD){
	if(MOD==0) throw "Division by zero";
	matrix<F2> ans(this->size_x,this->size_y);
	matrix<F2> temp(this->size_x,this->size_y);
	for(int i=0;i<this->size_x;i++){
		ans(i,i)=1LL;
		for(int j=0;j<this->size_y;j++){
			temp(i,j)=this->__array[i][j];
		}
	}
	ans.print();
	while(n){
		if(n&1){
			ans*=temp;
			ans%=MOD;
		}
		temp*=temp;
		temp%=MOD;
		n/=2.0;
	}

	return ans;
}

int main(){
	matrix<long> a(2,2,4);
	auto b=a+a;
	b.print();
}