/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:26:58 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/20 09:02:17 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable! I want to speak to the manager now."

Harl::Harl(void) {
	_complaints[0] = &Harl::_debug;
	_complaints[1] = &Harl::_info;
	_complaints[2] = &Harl::_warning;
	_complaints[3] = &Harl::_error;
}

Harl::~Harl(void) {
	std::cout << "[✔] Harl 2.0: Levels test completed." << std::endl << std::endl;
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
			std::cout << "[ HARL ] ";
			// call the corresponding member function (pointed to) using the pointer array
			(this->*_complaints[i])();
			return ;
		}
	}
}
