/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:29:35 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/17 16:06:09 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#if 0
int	main(void) {

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Should be 2 (9-11 or 6-3)
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	return (0);
}

#endif

#if 1

#include <ctime> 

#define RED "\033[0;31m"
#define RESET "\033[0;0m"

int	main(void) {
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Basic functionality ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Span	sp0(3);
		sp0.addNumber(1);
		sp0.addNumber(10);
		sp0.addNumber(100);
		std::cout << sp0.shortestSpan() << std::endl;
		std::cout << sp0.longestSpan() << std::endl;
		try {
			sp0.addNumber(42);
		}
		catch (const std::exception &e) {
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}


	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Not enought elements ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Span	sp1(2);
		sp1.addNumber(1);
		std::cout << "Attempting to get shortestSpan() with one element..." << std::endl;
		sp1.shortestSpan(); // Should throw
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		Span	sp2(200);
		sp2.addNumber(2);
		std::cout << "Attempting to get longestSpan() with one element..." << std::endl;
		sp2.longestSpan(); // Should throw
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Range Addition ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try { 
		Span sp3(10);
		std::vector<int> nums = {1, 2, 3, 4, 5};
		sp3.addNumbersRange(nums.begin(), nums.end());
		sp3.addNumber(100);
		std::cout << "Shortest span after range add: " << sp3.shortestSpan() << std::endl; // Should be 1
		std::cout << "Longest span after range add: " << sp3.longestSpan() << std::endl;   // Should be 99
	}
	catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}


	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Large number of elements (10.000) ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		const unsigned int N = 10000;
		Span bigSpan(N);

		// Fill vector with random numbers
		std::vector<int> bigNumbers;
		bigNumbers.reserve(N);
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		for (unsigned int i = 0; i < N; ++i) {
			bigNumbers.push_back(std::rand());
		}

		// Add all numbers using range addition
		bigSpan.addNumbersRange(bigNumbers.begin(), bigNumbers.end());

		std::cout << "Shortest span after range addition: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span after range addition: " << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}



	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Large number of elements (10.000) ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	try {
		Span sp4(3);
		std::vector<int> nums = {1, 2, 3, 4};
		sp4.addNumbersRange(nums.begin(), nums.end()); // Should throw
	}
	catch (const std::exception& e) {	
		std::cout << RED << e.what() << RESET << std::endl;
	}
}


#endif
