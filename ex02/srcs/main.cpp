/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:49 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/15 17:03:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <typeinfo>

class Base
{
public:
  const char* dynamic_type;
	virtual ~Base(){}
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

void identify_from_pointer(Base * p);
void identify_from_reference(Base & p);

int main(){
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	identify_from_pointer(a);
	identify_from_pointer(b);
	identify_from_pointer(c);
	identify_from_reference(*a);
	identify_from_reference(*b);
	identify_from_reference(*c);
	return 0;
}


void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Oups ! you can't do that !" << std::endl;
}

void identify_from_reference(Base & p)
{
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}catch(std::bad_cast &e){}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}catch(std::bad_cast &e){}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}catch(std::bad_cast &e){}
	std::cout << "Oups ! you can't do that !" << std::endl;
}
