/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:25:45 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/19 16:25:47 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& aWeapon) : _name(name), _weapon(aWeapon) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) const {
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType() << std::endl;
}

