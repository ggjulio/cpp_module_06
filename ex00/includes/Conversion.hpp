/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:05:37 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/15 11:08:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <ostream>
#include <cstdlib>
#include <cctype>

class Conversion
{
private:
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
	// Char
	if (input.size() == 1 && isalpha(input[0]))
	{
		_isChar = true;
		_char = input.c_str()[0];
	}
	// int
	{
		char *end = NULL;
		_int = std::strtod(input.c_str(), &end);
		if (end)
			_isInt = true;
		
	}
	// double
	{
		_float = atof(input.c_str());
		_isFloat = true;
	}
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
		os << c.isDouble() << std::endl;
	else
		os << "Non displayable" << std::endl;
  

	return os;
}


