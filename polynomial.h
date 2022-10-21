#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
const int MAX_SIZE = 1000000;

class polynomial{
	private:
		int degree;
		double coeff[100000];
	public:

		
		/**@brief
		*	A class constructor
		*@param[out] coeff[]
		*	An array of polynomial factors
		*@param degree
		*	Degree of polynomial 
		*/
		polynomial(int degree, double arr[]);
		/**@brief
		*	Default constructor
		*/
		polynomial();
		/**@brief
		*	Equality operator check are two polinomal equal 
		*@param k
		*	A polynomial whcich will be compared with 
		*@retval TRUE two polynomials are equal
		*@retval FALSE two polynomials are not equal
		*/
		bool operator==(const polynomial & k);
		/**@brief
		*	Addition operator add two polynomials
		*@param k
			Polynomial which will be added to the first one
		*@retval
		*	Result of addition
		*/
		polynomial operator+(const polynomial & k);
		/**@brief
		*	Substraction operator substract two polynomials
		*@param k
		*	Polynomial which will be substracted from the first one
		*@retval
		*	Result of substracion
		*/
		polynomial operator-(const polynomial & k);
		/**@brief
			Multiplication operator multiply two polynomials
		*@param k
		*	Polynomial which will be multiply by the first one
		*@retval
		*	Result of multiplication
		*/
		polynomial operator*(const polynomial & k);
		/**@brief
			Assignment operator assign value
		*@param k
		*	Polynomial which will be assign to first polynomial
		*@retval
		*	Result of assignment
		*/
		void operator=(const polynomial & k);
		/**@brief
		*	Operation of calculating value of polynomial 
		*@param x
		*	Point of calculating value
		*@retval
		*	Value of poliynomial
		*/
		double calculate(double x);
		/**@brief
		*	Displaying polynomial on the screen in user friendly way
		*/
		void display();
};
#endif // POLYNOMIAL_h
