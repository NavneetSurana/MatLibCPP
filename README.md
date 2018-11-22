# MatLibCPP
A MATRIX library for C++ users

# Features
Following are the features of **MatLibCpp**
## Matrix Initialization

* **matrix \<typename> a(row_size,column_size, const initial_value)**
	
	Eg:	
		
		matrix <int> a(2,2,4);
	
		Matrix a will be:
		4 4 
		4 4
		
* **matrix \<typename> a(row_size,column_size)**
	
	Eg:
		
		matrix <int> a(2,2);
		
		Matrix a will be:
		0 0
		0 0
		
* **matrix \<typename> a;**
	
	Eg:
		
		matrix <int> a;
	
## Accessing the element of ith row and jth column:
* **a(i,j) will give the required element**
## Matrix Addition
* **matrix \<typename> :: matrix \<typename> operator + or += (matrix \<typename> & val)**
	
	Eg:
		
		matrix <int> a(2, 2, 5),b(2, 2, 5);
		a+=b;
		auto c=a+b;
		
		Matrix a and c will become:
		10 10
		10 10
## Matrix Substration
* **matrix \<typename> :: matrix \<typename> operator - or -= (matrix \<typename> & val)**
	
	Eg:
		
		matrix <int> a(2, 2, 5),b(2, 2, 4);
		a+=b;
		auto c=a+b;
		
		Matrix a and c will become:
		1 1
		1 1
## Matrix Multiplication
* **matrix \<typename> :: matrix \<typename> operator \* or \*= (matrix \<typename> & val)**
	
	Eg:
		
		matrix <int> a(2, 2, 1),b(2, 2, 2);
		a*=b;
		auto c=a*b;
		
		Matrix a and c will become:
		4 4
		4 4

## Matrix Multiplication with scalar
* **matrix \<typename> :: void operator \* or \*= (const typename& val)**
	
	Eg:
		
		matrix <int> a(2, 2, 1);
		a*=4.0;
		auto c=a*4.0;
		
		Matrix a is:
		4 4
		4 4
		
		Matric c:
		4.0 4.0
		4.0 4.0
## Matrix Division with scalar
* **matrix \<typename> :: void operator / or /= (const typename& val)**
	
	Eg:
		
		matrix <int> a(2, 2, 1);
		a/=2.0;
		auto c=a/2.0;
		
		Matrix a is:
		0 0
		0 0
		
		Matric c is:
		0.5 0.5
		0.5 0.5
## Matrix Mudulo with scalar
* **matrix \<typename> :: void operator % or %= (const typename& val)**
	
	Eg:
        	
		matrix <int> a(2, 2, 10);
		a%=4;
		auto c=a%4;
		
		Matrix a and c will be:
		2 2
		2 2
## Matrix Exponentiation
* **matrix \<typename> :: matrix \<typename> exp(exponent)**
	
	Eg:
		
		matrix <int> a(2,2,2);
		auto c = a.exp(2);
		
		Matrix c is:
		8 8
		8 8
## Matrix Modular_Exponentiation
* **matrix \<typename> :: matrix \<typename> mod_exp(exponent,MOD)**
	
	Eg:
		
		matrix <int> a(2,2,2);
		int MOD=3;
		auto c = a.mod_exp(2,MOD);
		
		Matrix c is:
		2 2
		2 2
 # To Do's
   * Matrix transpose
   * Matrix inverse
   * Currently thinking of more
