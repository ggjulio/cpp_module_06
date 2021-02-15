/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:49 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/15 16:32:36 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base
{
public:
	virtual ~Base();	
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

void identify_from_pointer(Base * p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;	
}
void identify_from_reference(Base & p){
	if (dynamic_cast<A&>(*p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B&>(*p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C&>(*p))
		std::cout << "C" << std::endl;	
}

int main(){
	

	return 0;
}