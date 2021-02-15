/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:04:38 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/15 11:12:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Conversion.hpp"

int main(int ac, char **av)
{
	// Tests
	std::cout << "### \"c\":" << std::endl;	
	std::cout << Conversion("c");
	std::cout << std::endl << "### \"0\":" << std::endl;	
	std::cout << Conversion("0");
	std::cout << std::endl << "### \"nan\":" << std::endl;	
	std::cout << Conversion("nan");	
	std::cout << std::endl << "### \"42.0f\":" << std::endl;	
	std::cout << Conversion("42.0f");	
	std::cout << std::endl << "### ### ###" << std::endl << std::endl;	

	if (ac != 2){
		std::cout << "Only one arg pls" << std::endl;
		return 1;
	}
	std::cout << Conversion(av[1]);	

	
	return 0;
}