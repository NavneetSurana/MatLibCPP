#include "matrix.h"
#include <iostream>

template <typename T>
void matrix<T>::print(){
	for(int i=0;i<size_x;i++){
		for(int j=0;j<size_y;j++){
			std::cout<<array[i][j]<<' ';
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
	this->array=NULL;
}
template <typename T>
matrix<T>:: matrix(const int& n,const int& m): array(new T*[n]),size_x(n),size_y(m){
	for(int i=0;i<n;i++){
		array[i]=new T[m];
		for(int j=0;j<m;j++){
			array[i][j]=0;
		}
	}
}
template <typename T>
matrix<T>:: matrix(const int& n,const int& m,const int& val): array(new T*[n]),size_x(n),size_y(m){
	for(int i=0;i<n;i++){
		array[i]=new T[m];
		for(int j=0;j<m;j++){
			array[i][j]=val;
		}
	}
}
//---------------------------------//

	//DESTURCTOR
//------------------//
template <typename T>
matrix<T>:: ~matrix(){
	for(int i=0;i<size_x;i++){
		delete[] array[i];
	}
	delete[] array;
	array=NULL;
}
//-----------------//


	//OPERATOR OVERLOADING
//---------------------------//
//OPERATOR ()
template<typename T>
inline T& matrix<T>::operator ()(int& i,int& j){
	return  this->array[i][j];
}

//OPERATOR *
template<typename T>
matrix<T> matrix<T>::operator * (matrix<T>& other){
	if(this->size_y!=other.dim().first){
		throw "Dimensions are not valid";
	}
	else{

		int p=this->size_x,q=this->size_y,r=other.dim().second;
		matrix<T> temp(p,q);
		for(int i=0;i<p;i++){
			for(int j=0;j<r;j++){
				for(int k=0;k<q;k++){
					temp(i,j)+=this->array[i][k]*other(k,j);
				}
			}
		}
		return temp;
	}
}
//OPERATOR * for consts
template<typename T>
matrix<T> matrix<T>::operator * (const T& val){
	int p=this->size_x,q=this->size_y;
	matrix<T> temp(p,q);
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++){
			temp(i,j)=this->array[i][j]*val;
		}
	}
	return temp;
}
//OPERATOR +
template<typename T>
matrix<T> matrix<T>::operator + (matrix<T>& other){
	if(this->size_x!=other.dim().first && this->size_y!=other.dim().second){
		throw "Dimensions are not valid";
	}
	else{
		int p=this->size_x,q=this->size_y;
		matrix<T> temp(p,q);
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				temp(i,j)=this->array[i][j]+other(i,j);
			}
		}
		return temp;
	}
}
//OPERATOR -
template<typename T>
matrix<T> matrix<T>::operator - (matrix<T>& other){
	if(this->size_x!=other.dim().first && this->size_y!=other.dim().second){
		throw "Dimensions are not valid";
	}
	else{
		int p=this->size_x,q=this->size_y;
		matrix<T> temp(p,q);
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				temp(i,j)=this->array[i][j]-other(i,j);
			}
		}
		return temp;
	}
}
//OPERATOR %
template<typename T>
matrix<T> matrix<T>::operator % (const T& val){
	int p=this->size_x,q=this->size_y;
	matrix<T> temp(p,q);
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++){
			temp(i,j)=this->array[i][j]%val;
		}
	}
	return temp;
}


//OPERATOR *=
template<typename T>
void matrix<T>::operator *= (matrix<T>& other){
	*this=*this*other;
}
//OPERATOR *= for consts
template<typename T>
void matrix<T>::operator *= (const T& val){
	*this=*this*val;
}
//OPERATOR +=
template<typename T>
void matrix<T>::operator += (matrix<T>& other){
	*this=*this+other;
}
//OPERATOR -=
template<typename T>
void matrix<T>::operator -= (matrix<T>& other){
	*this=*this-other;
}
//OPERATOR %=
template<typename T>
void matrix<T>::operator %= (const T& val){
	*this=*this%val;
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
matrix<T> matrix<T>::exp(T n){
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
matrix<T> matrix<T>::mod_exp(T n,T MOD){
	matrix<T> ans(this->size_x,this->size_y);
	matrix<T> temp=*this;
	for(int i=0;i<this->size_x;i++){
		ans(i,i)=1LL;
	}

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
