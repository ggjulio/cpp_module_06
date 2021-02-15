/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:49:06 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/15 15:12:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>


struct Data {
	std::string s1;
	std::string s2;
	int n;
}; //__attribute__ ((packed));
// __attribute__ ((packed))
// typedef Data packedString;

std::string getRandom8chars(void)
{
	std::string result;

	srand(time(0));
	
	for (size_t i = 0; i < 8; i++)
		result[i] =	rand() % 74 + '0';
	return result;
}


void * serialize(void){
	Data *d = new Data;

	srand(time(0));

	d->s1 = "01234567";
	d->n = rand() % 43;
	d->s2 = "abcdefgh";
	
	return (d);
}

Data * deserialize(void * raw){
	Data *result = new Data;

	*result = *reinterpret_cast<Data*>(raw);
	return	result;
}

int main(){
	std::cout << "sizeof(std::string):" << sizeof(std::string) << std::endl;
	// std::cout << "sizeof(std::string) :" << sizeof(packedString) << std::endl;
	std::cout << "sizeof(Date):" << sizeof(Data) << std::endl;

	return 0;
}