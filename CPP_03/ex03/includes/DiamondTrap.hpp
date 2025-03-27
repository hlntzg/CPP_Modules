/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:04:07 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 12:00:36 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &other);
		~DiamondTrap(void);
		DiamondTrap &operator=(const DiamondTrap &other);

		void	whoAmI(void);
		void	howManyPoints(void);
};


#endif
