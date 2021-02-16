/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:49 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/17 00:35:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <typeinfo>
#include <cstdlib>

class Base
{
public:
  const char* dynamic_type;
	virtual ~Base(){}
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base * generate(void);
void identify_from_pointer(Base * p);
void identify_from_reference(Base & p);

int main(){
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	Base *base = new Base();
	Base *random = generate();
	Base *random2 = generate();

	identify_from_pointer(a);
	identify_from_pointer(b);
	identify_from_pointer(c);
	identify_from_pointer(base);

	identify_from_reference(*a);
	identify_from_reference(*b);
	identify_from_reference(*c);
	identify_from_reference(*base);


	identify_from_pointer(random);
	identify_from_reference(*random);
	identify_from_pointer(random2);
	identify_from_reference(*random2);
	delete a;
	delete b;
	delete c;
	delete base;
	delete random;
	delete random2;
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

template<typename T>
Base * newDerived(void){
	return new T();
}

Base * generate(void){
	static bool seeded;
	Base * (*funcs[])(void) = {	newDerived<A>, newDerived<B>, newDerived<C>};

	if (!seeded)
	{
		srand(time(0));
		seeded = true;
	}
	return (funcs[rand() % 3])();
}
