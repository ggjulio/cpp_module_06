/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Demo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:02:50 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/15 16:30:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEMO_H
#define DEMO_H

#include 

class Base
{
public:
	virtual ~Base();	
};

class A: public Base
{	
// private:
// 	A(const A &);
// 	A & operator=(const A &);
// public:
// 	A();
// 	~A();
};

class B: public Base {};

class C: public Base {}


#endif
