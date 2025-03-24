/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:24:51 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 14:07:01 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <string>
#include <iostream>
#include <regex>

/** 
 * This function gets the coordinates from the user input.
 * It allocates an array of floats and converts command-line arguments to float values.
 * 
 * @param argc Number of command-line arguments.
 * @param argv Array of argument strings.
 * @return Pointer to an array of float values, or nullptr if memory allocation fails.
 */
static float*	getCoordinates(int argc, char **argv) {
	
	float*	args = nullptr;

	try {
		args = new float [8];
		for (int i = 1; i < argc; i++)
			args[i - 1] = static_cast<float>(std::atof(argv[i]));
	}
	catch (std::bad_alloc&) {
		std::cout << "Memory allocation failed." << std::endl;
		return (nullptr);
	}
	return (args);
}

/** 
 * Checks if a given string represents a valid number (integer or decimal).
 * Uses a regular expression to validate the format of the number.
 * 
 * @param str The input string to check.
 * @return True if the string represents a valid number, false otherwise.
 */
static bool isNum(const std::string& str)
{
    std::regex	pattern(R"(^[-+]?\d*\.?\d+$)");
    return (std::regex_match(str, pattern));
}

/**
 * Determines whether a given point is inside a triangle using the BSP algorithm.
 * If the point is inside, prints a success message; otherwise, prints a failure message.
 *
 * @param a, b, c Vertices of the triangle.
 * @param point The point to check.
 */
static void	checkPoint(Point const a, Point const b, Point const c, Point const point)
{ 
	try {
		if (bsp(a, b, c, point) == true)
			std::cout << "\e[0;32m" << "[✔] The point (" << point.getX() << ", " << point.getY() << ") is inside of the triangle." << "\e[0m" << std::endl;
		else
			std::cout << "\e[0;31m" <<"[✗] The point (" << point.getX() << ", " << point.getY() << ") is not inside of the triangle." << "\e[0m" <<  std::endl;
		if (std::cout.fail()) {
            throw std::ios_base::failure("Output stream failed.");
		}
	}
    catch (const std::ios_base::failure& e) { 
        std::cout << "Error: " << e.what() << std::endl;
	}
}

/**
 * Validates command-line arguments.
 * Converts input values to `Point` objects.
 * Checks if a given point is inside a triangle.
 * Handles various errors including invalid input and memory allocation issues.
 */
int	main(int argc, char **argv) {
	try {
		if (argc != 9) {
			throw std::invalid_argument ("Invalid number of arguments.\nUsage: ./BSP <xP> <yP> <xA> <yA> <xB> <yB> <xC> <yC>.");
		}
		for (int i = 1; i < argc; i++) {
			if (!isNum(argv[i])) {
				throw std::invalid_argument ("Error: Invalid argument: " + std::string(argv[i]));
			}
		}

		std::cout	<< std::endl
					<< "                     WELCOME TO BSP                     " << std::endl
					<< "--------------------------------------------------------" << std::endl
					<< "Let's check if the point (" << argv[1] << ", " << argv[2] << ") is inside of a triangle." << std::endl
					<< "The triangle has the following vertices:" << std::endl
					<< "Vertex A (" << argv[3] << ", " << argv[4] << ")" << std::endl
					<< "Vertex B (" << argv[5] << ", " << argv[6] << ")" << std::endl
					<< "Vertex C (" << argv[7] << ", " << argv[8] << ")" << std::endl
			<< std::endl;
		
		if (std::cout.fail())
            throw std::ios_base::failure("Failed to write to stdout.");

		float*	args = getCoordinates(argc, argv);
	
		if (!args)
			throw std::runtime_error("Failed to parse coordinates.");
		
		Point	point(args[0], args[1]);
		Point		a(args[2], args[3]);
		Point		b(args[4], args[5]);
		Point		c(args[6], args[7]);
		
		delete[] args;
		
		if (a == b || a == c || b == c)
			throw std::logic_error("Invalid triangle coordinates. A, B, and C must be different.");
		checkPoint(a, b, c, point);
	}
	catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (1);
    }
	return (0);
}
