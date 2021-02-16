/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:04:38 by juligonz          #+#    #+#             */
/*   Updated: 2021/02/16 22:42:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Conversion.hpp"

int main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Only one arg pls" << std::endl;
		return 1;
	}
	std::cout << Conversion(av[1]);	
	return 0;
}