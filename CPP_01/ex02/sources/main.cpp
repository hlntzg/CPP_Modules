#include <iostream>
#include <string>

int	main(void) {
	std::cout	<< std::endl
				<< "WELCOME TO THE ADDRESS MANIPULATION" << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	std::string		myString = "HI THIS IS BRAIN";
	std::string*	stringPTR = &myString;
	std::string&	stringREF = myString;

	std::cout	<< std::endl
				<< "     VARIABLES' MEMORY ADDRESS     " << std::endl
				<< "-----------------------------------" << std::endl
				<< "myString:\t" << &myString << std::endl
				<< "stringPTR:\t" << stringPTR << std::endl
				<< "stringREF:\t" << &stringREF << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	std::cout	<< std::endl
				<< "       VALUE OF THE VARIABLES      " << std::endl
				<< "-----------------------------------" << std::endl
				<< "myString:\t" << myString << std::endl
				<< "stringPTR:\t" << *stringPTR << std::endl
				<< "stringREF:\t" << stringREF << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	return (0);
}
