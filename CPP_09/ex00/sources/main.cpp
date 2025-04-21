/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 09:11:20 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/21 11:05:23 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cout	<< "Error: Wrong number of arguments." << std::endl
					<< "Usage: ./btc <file>" << std::endl
					<< "------------------------------------------" << std::endl
					<< "File: Database with 'date | value' format." << std::endl
					<< "Date: Year-Month-Day format." << std::endl
					<< "Value: Float or Integer type (0 - 1000)." << std::endl
					<< "------------------------------------------" << std::endl;
		return (1);
	}

	BitcoinExchange	btc;

	try {
		btc.importDatabase("data.csv");	
		btc.processFile(argv[1]);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
