#include "Harl.hpp"

Harl::Harl(void) {
	_complaints[0] = &Harl::_debug;
	_complaints[1] = &Harl::_info;
	_complaints[2] = &Harl::_warning;
	_complaints[3] = &Harl::_error;
}

Harl::~Harl(void) {
	std::cout << SWAP << "[✔] Harl 2.0: Levels test completed." << RESET << std::endl << std::endl;
}

void	Harl::_debug(void) {
	std::cout << DEBUG << std::endl;
}

void	Harl::_info(void) {
	std::cout << INFO << std::endl;
}

void	Harl::_warning(void) {
	std::cout << WARNING << std::endl;
}

void	Harl::_error(void) {
	std::cout << ERROR << std::endl;
}

void	Harl::complain(std::string level) {
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			std::cout << "[HARL] ";
			// call the corresponding member function (pointed to) using the pointer array
			(this->*_complaints[i])();
			return ;
		}
	}
}
