/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:21:01 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/24 16:35:14 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap {

	private:
		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackPoints;

	public:
		ClapTrap(void);								// Default Constructor
		ClapTrap(const std::string name);			// Parameterized Constructor
		ClapTrap(const ClapTrap &other);			// Copy Constructor
		~ClapTrap(void);							// Default Destructor
		ClapTrap &operator=(const ClapTrap &other);	// Copy Assignment Operator

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
