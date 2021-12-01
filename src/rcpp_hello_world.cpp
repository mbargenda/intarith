#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List rcpp_hello_world() {

    CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
    NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
    List z            = List::create( x, y ) ;

    return z ;
}

// [[Rcpp::export(.iplus)]]
List rcpp_plus(NumericVector x, NumericVector y)
{
	if(x.size() != 2)
		throw std::invalid_argument("rcpp_plus: x must be a vector of length 2.") ;

	if(y.size() != 2)
		throw std::invalid_argument("rcpp_plus: y must be a vector of length 2.") ;
	
	double l = x[0] + y[0] ;
	double u = x[1] + y[1] ;
	
	NumericVector r = NumericVector::create(l, u) ;
	return List::create(r) ;
}

// [[Rcpp::export(.iminus)]]
List rcpp_minus(NumericVector x, NumericVector y)
{
	if(x.size() != 2)
		throw std::invalid_argument("rcpp_plus: x must be a vector of length 2.") ;
	
	if(y.size() != 2)
		throw std::invalid_argument("rcpp_plus: y must be a vector of length 2.") ;
	
	double l = x[0] - y[1] ;
	double u = x[1] - y[0] ;
	
	NumericVector r = NumericVector::create(l, u) ;
	return List::create(r) ;
}
