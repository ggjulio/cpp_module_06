/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:49:06 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/17 00:32:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>

struct Data {
	std::string s1;
	int n;
	std::string s2;
} __attribute__ ((packed));

void * serialize(void){
	Data *d = new Data;

	srand(time(0));
	
	d->s1 = std::string(8,0);
	d->s2 = std::string(8,0);
	for (size_t i = 0; i < 8; i++)
		d->s1[i] = rand() % 74 + '0';
	d->n = rand() % 22 + 21;
	for (size_t i = 0; i < 8; i++)
		d->s2[i] = rand() % 74 + '0';
	return (d);
}

Data * deserialize(void * raw){
	return reinterpret_cast<Data*>(raw);
}

int main(){
	std::cout << "sizeof(std::string):" << sizeof(std::string) << std::endl;
	std::cout << "sizeof(Date):" << sizeof(Data) << std::endl << std::endl;

	Data *d = deserialize(serialize());

	std::cout << "s1:" << d->s1 << std::endl
		<< "n:" << d->n << std::endl
		<< "s2:" << d->s2 << std::endl;
	delete d;
	return 0;
}