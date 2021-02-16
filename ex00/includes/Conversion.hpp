/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:05:37 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/17 00:06:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

class Conversion
{
private:
	char _char;
	int _int;
	float _float;
	double _double;

	bool _isNan;
	bool _inputFromDouble;
	bool _fail;

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
	
	void _fromFloat(const std::string &);
	void _fromDouble(const std::string &);
	void _fromInt(const std::string &);
	
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
