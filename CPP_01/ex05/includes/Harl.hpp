/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:26:47 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/20 08:34:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class	Harl {
	
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
		
		// member function for an array of pointers to member functions
		void	(Harl::*_complaints[4])(void);

	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);
};

#endif
