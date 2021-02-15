/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:05:37 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/15 19:50:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <sstream>
#include <ostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>

class Conversion
{
private:
	long double _input;
	char _char;
	int _int;
	float _float;
	double _double;

	bool _isChar;
	bool _isInt;
	bool _isFloat;
	bool _isDouble;
	
	Conversion();
	Conversion(const Conversion &);
	Conversion & operator=(const Conversion &);

	void _fromChar(const std::string &);
	void _fromDouble(const std::string &);
	
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

	bool	isChar(void) const;
	bool	isInt(void) const;
	bool	isFloat(void) const;
	bool	isDouble(void) const;
};

std::ostream& operator<<(std::ostream &os, const Conversion &);

#endif

// #######################################################

// #include "Conversion.hpp"

Conversion::Conversion(const std::string &input)
: _char(0), _int(0), _float(0), _double(0), _isChar(0), _isInt(0), _isFloat(0), _isDouble(0)
{
	std::istringstream iss(input);
	// Char
	if (input.size() == 1 && isalpha(input[0]))
	{
		_isChar = true;
		_input = input.c_str()[0];
	}
	else
	{
		
		iss >> _input;
		if (!iss.fail())
			;
		// _float = atof(input.c_str());
	}	
	// decimal
	{
		// _int = std::strtod(input.c_str(), &end);
		
	}
	_castAll(_input);
	_isFloat = true;
	_isInt = true;
	_isChar = true;
	_isDouble = true;
}

Conversion::~Conversion(){}

char Conversion::getChar(void)		const { return _char;}
int Conversion::getInt(void)		const { return _int;}
float Conversion::getFloat(void)	const { return _float;}
double Conversion::getDouble(void)	const { return _double;}

bool Conversion::isChar(void)		const { return _isChar;}
bool Conversion::isInt(void) 		const { return _isInt;}
bool Conversion::isFloat(void) 		const { return _isFloat;}
bool Conversion::isDouble(void)		const { return _isDouble;}

std::ostream& operator<<(std::ostream &os, const Conversion &c){
	os << "char: ";
	if (c.isChar())
		os << c.getChar() << std::endl;
	else
		os << "Non displayable" << std::endl;

	os << "int: ";
	if (c.isInt())
		os << c.getInt() << std::endl;
	else
		os << "Non displayable" << std::endl;

	os << "float: ";
	if (c.isFloat())
		os << c.getFloat() << std::endl;
	else
		os << "Non displayable" << std::endl;

	os << "double: ";
	if (c.isDouble())
		os << c.getDouble() << std::endl;
	else
		os << "Non displayable" << std::endl;

	return os;
}


