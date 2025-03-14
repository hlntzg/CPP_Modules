#include "Harl.hpp"

Harl::Harl(void) {
	_levelFilter = DEBUG;
}

Harl::~Harl(void) {
	std::cout << "[✔] Harl Filter: Log levels completed." << std::endl;
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

void	Harl::setLevel(const std::string& input) {
	
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	for (i = 0; i < 4; i++) {
		if (levels[i] == input)
			break ;
	}
	switch (i) {
		case 0:
			_levelFilter = DEBUG;
			break ; 
		case 1:
			_levelFilter = INFO;
			break ;
		case 2:
			_levelFilter = WARNING;
			break ;
		case 3:
			_levelFilter = ERROR;
			break ;
	}
}

levelFilter	Harl::getLevel(void) const {
	return (_levelFilter);
}

void		Harl::complain(std::string& level) {

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*_complaints[4])(void) = {
		&Harl::_debug;
		&Harl::_info;
		&Harl::_warning;
		&Harl::_error;
	};

	for (int i = _levelFilter; i < 4; i++) {
		if (levels[i] == level)
		{
			std::cout << "[HARL] ";
			(this->*_complaints[i])();
			return ;
		}
	}
}
