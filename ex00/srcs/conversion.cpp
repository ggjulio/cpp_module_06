/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:05:22 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/17 00:07:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include <sstream>
#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <stdexcept>

#include "Conversion.hpp"

Conversion::Conversion(const std::string &input)
: _char(0), _int(0), _float(0), _double(0), _isNan(0), _inputFromDouble(0), _fail(0)
{
	// Char
	if (input.size() == 1 && !isdigit(input[0]))
		_castAll(input.c_str()[0]);
	//float
	else if ((input.find('.') != std::string::npos && input[input.size()-1] == 'f')
	|| !input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		_fromFloat(input);
	// double
	else if (input.find('.') != std::string::npos
	|| !input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		_fromDouble(input);
	// Integer
	else 
		_fromInt(input);	
}

Conversion::~Conversion(){}

char Conversion::getChar(void)		const {
	if (getInt() < CHAR_MIN || _int > CHAR_MAX)
		throw std::overflow_error("Char overfow");
	return _char;
}
float Conversion::getFloat(void)	const {
	return _float;
}
int Conversion::getInt(void)		const {
	long long n = getDouble();
	if (_fail || (_inputFromDouble && (n > INT_MAX || n < INT_MIN)))
		throw std::overflow_error("Integer Overflow");
	// if (_fail)// || ((_inputInt > INT_MAX || _inputInt < INT_MIN) && !_inputFromDouble))
		// throw std::overflow_error("Integer Overflow");
	return _int;
}
double Conversion::getDouble(void)	const {
	if (_fail)
		throw std::overflow_error("Double Overflow");
	return _double;
}

bool Conversion::isNan(void)	const { return _isNan;}
bool Conversion::fail(void)		const { return _fail;}

void Conversion::_fromFloat(const std::string &input){
	std::istringstream ist(input);
	float inputFloat;
	
	_isNan = true;
	if (!input.compare("-inf"))
		inputFloat = -INFINITY;
	else if (!input.compare("+inf"))
		inputFloat = INFINITY;
	else if (!input.compare("nan"))
		inputFloat = NAN;
	else
	{
		ist >> inputFloat;
		_isNan = false;
	}
	_inputFromDouble = true;
	if (!ist)
		_fail = true;
	_castAll(inputFloat);
}

void Conversion::_fromDouble(const std::string &input){
	std::istringstream ist(input);
	double inputDbl;
	_isNan = true;
	if (!input.compare("-inf"))
		inputDbl = -INFINITY;
	else if (!input.compare("+inf"))
		inputDbl = INFINITY;
	else if (!input.compare("nan"))
		inputDbl = NAN;
	else
	{
		ist >> inputDbl;
		_isNan = false;
	}
	_inputFromDouble = true;
	if (!ist)
		_fail = true;
	_castAll(inputDbl);
}

void Conversion::_fromInt(const std::string &input){
	std::istringstream ist(input);
	int inputInt;
	ist >> inputInt;
	if (!ist)
		_fail = true;
	_castAll(inputInt);
}

std::ostream& operator<<(std::ostream &os, const Conversion &c){
	std::string trailing_zero;

	if (c.fail())
		return os << "Dude, stop trying overflow. Or giving bad args... Annoying :-( ... the goal is just to do some static cast :-)" << std::endl;
os << std::setprecision(10);
	os << "char: ";
		try{
			if (c.isNan())
				os << "impossible" << std::endl;
			else if (std::isgraph(c.getChar()))
				os << c.getChar() << std::endl;
			else
				os << "Non displayable" << std::endl;
		}
		catch (std::overflow_error &e){
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
			trailing_zero = c.getFloat() - static_cast<long>(c.getFloat()) ? "":  ".0";
			os << c.getFloat() << trailing_zero << "f" << std::endl;
		}
		catch (std::overflow_error &e){
			os << "overflow" << std::endl;
		}
	os << "double: ";
		try{
			trailing_zero = c.getDouble() - static_cast<long>(c.getDouble()) ? "":  ".0";
			os << c.getDouble() << trailing_zero << std::endl;
		}
		catch (std::overflow_error &e){
			os << "overflow" << std::endl;
		}
	return os;
}
