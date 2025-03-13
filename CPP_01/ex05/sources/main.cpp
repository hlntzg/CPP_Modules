#include "Harl.hpp"

int	main(void)
{
	std::cout	<< std::endl
				<< "WELCOME TO HARL 2.0 - Harl complains" << std::endl
				<< "------------------------------------" << std::endl
				<< std::endl;
	
	Harl	harl;
	
	std::cout	<< SWAP << "  TESTING HARL 2.0 FOR DEBUG LEVEL  " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("DEBUG");
	std::cout	<< std::endl;
	
	std::cout	<< SWAP << "  TESTING HARL 2.0 FOR INFO LEVEL   " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("INFO");
	std::cout	<< std::endl;
	
	std::cout	<< SWAP << " TESTING HARL 2.0 FOR WARNING LEVEL " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("WARNING");
	std::cout	<< std::endl;
	
	std::cout	<< SWAP << "  TESTING HARL 2.0 FOR ERROR LEVEL  " << RESET << std::endl
				<< "------------------------------------" << std::endl;
	harl.complain("ERROR");
	std::cout	<< std::endl;
	
	return (0);
}
