/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:29:40 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/20 09:08:51 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable! I want to speak to the manager now."

Harl::Harl(void) {}

Harl::~Harl(void) {
	std::cout << "[✔] Harl Filter: Log levels test completed." << std::endl << std::endl;
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
