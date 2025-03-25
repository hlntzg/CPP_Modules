/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:43:45 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/25 16:49:45 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class	FlagTrap : public ClapTrap {

	public:
		FlagTrap(void);
		FlagTrap(const std::string name);
		FlagTrap(const FlagTrap &other);
		FlagTrap &operator=(const FlagTrap &other);
		~FlagTrap(void);

//		void	attack(const std::string& target);
		void	highFivesGuys(void);
};


#endif
