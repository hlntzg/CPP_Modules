/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:19:42 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/23 16:21:05 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This program uses Ford-Johnson sorting algorithm, or merge-insertion sort,
 * to sort a sequence of positive integers */


#include "PmergeMe.hpp"

/*
bool	isValidInput(char **argv) {

	int n;
	char rest;

	while (*argv) {
		std::istringstream token(*argv);
		if (!(token >> n) || token >> rest || n < 0) {
			return (false);
		}
		argv++;
	}
	return (true);
}*/

int	main(int argc, char **argv) {
	
	if (argc < 2) {
		std::cerr	<< "Error: Wrong number of arguments." << std::endl
					<< "Usage: ./PmergeMe 'positive integer sequence'" << std::endl;
		return (1);
	}

/*	if (isValidInput(argv)) {
		std::cerr << "Error: All inputs must be positive integers." << std::endl;
		return (1);
	}*/

	try {

		/// if validate input first, it is possible print 'Before: ' + loop argv elements
		
		PmergeMe	pmm;
		
		// start time
		pmm.importData(pmm.getVector(), argv + 1);
		// run algorithm
		// stop time

		std::cout << "Before:\t";
		pmm.printElements(pmm.getVector());
		std::cout << "After:\t";
		pmm.printElements(pmm.getVector());

		// start time
		pmm.importData(pmm.getDeque(), argv + 1);
		// run algorithm
		// stop time



	////// pmm.printElements(pmm.getDeque());
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
