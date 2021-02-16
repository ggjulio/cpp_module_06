/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:05:37 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/16 22:44:35 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
#define CONVERSION_H

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
