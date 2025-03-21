#include "Fixed.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>
/*
float*	getCoordinates(char **argv) {
	
	float	args = nullptr;

	try {
		args = new Fixed[8];
		for (int i = 0; i < 8; i++)
			args[i] = static_cast<float>(std::atof(argv[i + 1]));
	}
	catch (std::bad_alloc&) {
		std::cout << "Memory allocation failed." << std::endl;
		return (nullptr);
	}
	catch (std:: ?? ) {
		std::cout << "?????." << std::endl;
		return (nullptr);
	}*/
//	return (args);
//}

#include <regex>

bool isNum(const std::string& str) {
	// std::regex is class for handling regular expression
    std::regex	pattern(R"(^[-+]?\d*\.?\d+$)");
    return (std::regex_match(str, pattern));
}

void	checkPoint(Point const a, Point const b, Point const c, Point const point)
{
	if (bsp(a, b, c, point) == true)
		std::cout << "[✔] The point (" << point.getX() << ", " << point.getY() << ") is inside of the triangle." << std::endl;
	else
		std::cout << "[✗] The point (" << point.getX() << ", " << point.getY() << ") is not inside of the triangle." << std::endl;
}

int	main(int argc, char **argv) {
	if (argc != 9) {
		std::cout	<< std::endl << "Error: Invalid number of arguments.\n"
					<< "Usage: ./BSP <xP> <yP> <xA> <yA> <xB> <yB> <xC> <yC>\n"
					<< "The program will indicate wheter a point B is inside of triangle A, B, C or not."
					<< std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++) {
		if (!isNum(argv[i])) {
			std::cout << "Error: Invalid argument: " << argv[i] << std::endl;
			return (1);
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
	
	float* args = new float[8];

    for (int i = 1; i < argc; i++) {
        args[i - 1] = static_cast<float>(std::atof(argv[i]));
    }
	
	//float*	args = getCoordinates(argv);
	//if (args != nullptr) {
		
		Point	point(args[0], args[1]); //std::atof(argv[1]), std::atof(argv[2]));
		Point		a(args[2], args[3]); //std::atof(argv[3]), std::atof(argv[4]));
		Point		b(args[4], args[5]); //std::atof(argv[5]), std::atof(argv[6]));
		Point		c(args[6], args[7]); //std::atof(argv[7]), std::atof(argv[8]));
		
		if (a == b || a == c || b == c)
			std::cout << "Error: Invalid triangle coordinates. A, B, C must be different." << std::endl;
		else 
			checkPoint(a, b, c, point);
		delete[] args;
	//}
	return (0);
}
