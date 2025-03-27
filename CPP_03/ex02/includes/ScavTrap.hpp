/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:20:48 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 10:36:32 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif
