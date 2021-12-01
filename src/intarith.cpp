#include <Rcpp.h>
using namespace Rcpp;

bool zero(NumericVector x)
{
	return (x[1] == 0.0 && x[2] == 0.0) ;
}

// [[Rcpp::export(.iplus)]]
List plus(NumericVector x, NumericVector y)
{
	double l = x[0] + y[0] ;
	double u = x[1] + y[1] ;
	
	NumericVector r = NumericVector::create(l, u) ;
	return List::create(r) ;
}

// [[Rcpp::export(.iminus)]]
List minus(NumericVector x, NumericVector y)
{
	double l = x[0] - y[1] ;
	double u = x[1] - y[0] ;
	
	NumericVector r = NumericVector::create(l, u) ;
	return List::create(r) ;
}

// [[Rcpp::export(.imult)]]
List mult(NumericVector x, NumericVector y)
{
	if(x.size() != 2)
		throw std::invalid_argument("rcpp_mult: x must be a vector of length 2.") ;
	
	if(y.size() != 2)
		throw std::invalid_argument("rcpp_mult: y must be a vector of length 2.") ;

	double l, u ;

	// Z * Z
	// interval(A ... B * C ... D, Res) :-
	// once(zero(A, B); zero(C, D)),
	// !,
	// Res = 0.0 ... 0.0.
	if(zero(x) || zero(y))
	{
		l = 0 ;
		u = 0 ;
		NumericVector r = NumericVector::create(l, u) ;
		return List::create(r) ;
	}
		
		// % P * P
		// interval(A ... B * C ... D, Res) :-
		// positive(A, B),
		// positive(C, D),
		// !,
		// L is A * C,
		// U is B * D,
		// Res = L ... U.
		// 
		// % P * M
		// interval(A ... B * C ... D, Res) :-
		// positive(A, B),
		// mixed(C, D),
		// !,
		// L is B * C,
		// U is B * D,
		// Res = L ... U.
		// 
		// % P * N
		// interval(A ... B * C ... D, Res) :-
		// positive(A, B),
		// negative(C, D),
		// !,
		// L is B * C,
		// U is A * D,
		// Res = L ... U.
		// 
		// % M * P
		// interval(A ... B * C ... D, Res) :-
		// mixed(A, B),
		// positive(C, D),
		// !,
		// L is A * D,
		// U is B * D,
		// Res = L ... U.
		// 
		// % M * M
		// interval(A ... B * C ... D, Res) :-
		// mixed(A, B),
		// mixed(C, D),
		// !,
		// L is min(A * D, B * C),
		// U is max(A * C, B * D),
		// Res = L ... U.
		// 
		// % M * N
		// interval(A ... B * C ... D, Res) :-
		// mixed(A, B),
		// negative(C, D),
		// !,
		// L is B * C,
		// U is A * C,
		// Res = L ... U.
		// 
		// % N * P
		// interval(A ... B * C ... D, Res) :-
		// negative(A, B),
		// positive(C, D),
		// !,
		// L is A * D,
		// U is B * C,
		// Res = L ... U.
		// 
		// % N * M
		// interval(A ... B * C ... D, Res) :-
		// negative(A, B),
		// mixed(C, D),
		// !,
		// L is A * D,
		// U is A * C,
		// Res = L ... U.
		// 
		// % N * N
		// interval(A ... B * C ... D, Res) :-
		// negative(A, B),
		// negative(C, D),
		// !,
		// L is B * D,
		// U is A * C,
		// Res = L ... U.

	throw std::invalid_argument("mult: unhandled case.") ;
}
