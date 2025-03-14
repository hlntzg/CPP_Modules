#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {
	std::cout << "[✔] Harl Filter: Log levels test completed." << std::endl;
}

void	Harl::_debug(void) {
	std::cout << "[ DEBUG ]\n" << DEBUG << "\n" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "[ INFO ]\n" << INFO << "\n" << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "[ WARNING ]\n" << WARNING << "\n" << std::endl;
}

void	Harl::_error(void) {
	std::cout << "[ ERROR ]\n" << ERROR << "\n" << std::endl;
}

void	Harl::complain(std::string level) {

	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*_complaints[4])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	int		i;
	for (i = 0; i < 4; i++) {
		if (levels[i] == level) {
			break ;
		}
	}
	
	switch (i) {
		case 0:
			(this->*_complaints[0])();
		case 1:
			(this->*_complaints[1])();
		case 2:
			(this->*_complaints[2])();
		case 3:
			(this->*_complaints[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
	}
}
