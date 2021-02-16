/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:05:37 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/16 22:34:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <exception>
#include <stdexcept>

class Conversion
{
private:
	double _inputDbl;
	int _inputInt;
	bool _inputFromDouble;

	bool _isNan;
	
	bool _fail;

	char _char;
	int _int;
	float _float;
	double _double;

	Conversion();
	Conversion(const Conversion &);
	Conversion & operator=(const Conversion &);
	
	template<typename T>
	void _castAll(T n){
		_char = static_cast<char>(n);
		_int = static_cast<int>(n);
		_float = static_cast<float>(n);
		_double = static_cast<double>(n);
	}
	
public:
	Conversion(const std::string &);
	~Conversion();

	char 	getChar(void) const;
	int	 	getInt(void) const;
	float 	getFloat(void) const;
	double 	getDouble(void) const;

	bool 	isNan(void) const;
	bool 	fail(void) const;

};

std::ostream& operator<<(std::ostream &os, const Conversion &);

#endif

// #include "Conversion.hpp"

Conversion::Conversion(const std::string &input)
: _inputFromDouble(0), _isNan(0), _fail(0), _char(0), _int(0), _float(0), _double(0)
{
	std::istringstream ist(input);
	// Char
	if (input.size() == 1 && !isdigit(input[0]))
		_inputInt = input.c_str()[0];
	// double
	else if (input.find('.') != std::string::npos
		|| !input.compare("-inff") || !input.compare("-inf") || !input.compare("+inff")
		|| !input.compare("+inf")  || !input.compare("nanf")  || !input.compare("nan"))
	{
		_isNan = true;
		if (!input.compare("-inff") || !input.compare("-inf"))
			_inputDbl = -INFINITY;
		else if (!input.compare("+inff") || !input.compare("+inf"))
			_inputDbl = INFINITY;
		else if (!input.compare("nanf") || !input.compare("nan"))
			_inputDbl = NAN;
		else
		{
			ist >> _inputDbl;
			_isNan = false;
		}
		if (!ist)
			_fail = true;
		_inputFromDouble = 1;
		_castAll(_inputDbl);
		return ;
	}
	else // Integer
	{
		ist >> _inputInt;
		if (!ist)
			_fail = true;
	}
	_castAll(_inputInt);
}

Conversion::~Conversion(){}

char Conversion::getChar(void)		const {
	if (getInt() < CHAR_MIN || _int > CHAR_MAX)
		throw std::overflow_error("Char overfow");
	return _char;
}
float Conversion::getFloat(void)	const {
	// if (!_isNan && ((long long int)getDouble() > FLT_MAX_EXP ||  (long long int)_double < FLT_MIN_EXP))
	// if (!_isNan && (getDouble() > FLT_MAX || fabs(_double) < FLT_MIN))
		// throw std::overflow_error("Float Overflow");
	return _float;
}
int Conversion::getInt(void)		const {
	if (_inputFromDouble)
	{
		long long n = getDouble();
		if (~n || n > INT_MAX || n < INT_MIN)
			throw std::overflow_error("Integer Overflow");
	}
	if (_fail || ((_inputInt > INT_MAX || _inputInt < INT_MIN) && !_inputFromDouble))
		throw std::overflow_error("Integer Overflow");
	return _int;
}
double Conversion::getDouble(void)	const {
	// if (_fail || (!_isNan && ((long long int)_double > DBL_MAX_EXP ||  (long long int)_double < DBL_MIN_EXP)))
	// if (_fail || (!_isNan && (_double > DBL_MAX ||  fabs(_double) < DBL_MIN)))
	if (_fail)
		throw std::overflow_error("Double Overflow");
	return _double;
}

bool Conversion::isNan(void)	const { return _isNan;}
bool Conversion::fail(void)		const { return _fail;}

std::ostream& operator<<(std::ostream &os, const Conversion &c){
	std::string trailing_zero;

	if (c.fail())
		return os << "Dude, stop trying overflow. Or giving bad args... Annoying :-( ... the goal is just to do some static cast :-)" << std::endl;

	os << "char: " << std::setprecision(20);
	try{
		if (c.isNan())
			os << "impossible" << std::endl;
		else if (std::isgraph(c.getChar()))
			os << c.getChar() << std::endl;
		else
			os << "Non displayable" << std::endl;
	}
	catch (std::overflow_error &e)
	{
		os << "overflow" << std::endl;
	}
	

	os << "int: ";
	try{
		if (c.isNan())
			os << "impossible" << std::endl;
		else
			os << c.getInt() << std::endl;
	}
	catch (std::overflow_error &e){
		os << "overflow" << std::endl;
	}
	
	os << "float: ";
	try{
		trailing_zero = c.getFloat() - static_cast<int>(c.getFloat()) ? "":  ".0";
		os << c.getFloat() << trailing_zero << "f" << std::endl;
	}
	catch (std::overflow_error &e){
		os << "overflow" << std::endl;
	}


	os << "double: ";
	try{
		trailing_zero = c.getDouble() - static_cast<int>(c.getDouble()) ? "":  ".0";
		os << c.getDouble() << trailing_zero << std::endl;
	}
	catch (std::overflow_error &e){
		os << "overflow" << std::endl;
	}
	
	return os;
}


