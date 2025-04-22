/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:01:24 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/22 11:59:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr	<< "Error: Wrong number of arguments." << std::endl
					<< "Usage: ./RPN <mathematical expression>" << std::endl
					<< "------------------------------------------" << std::endl
					<< "Operands type: integer" << std::endl
					<< "Operators available: '+', '-', '/', '*'" << std::endl
					<< "------------------------------------------" << std::endl;
		return (1);
	}
	
	RPN		rpn;

	try {
		rpn.processInput(argv[1]);
		rpn.getResult();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
