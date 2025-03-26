/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:43:45 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/26 13:17:14 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {

	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap(void);

		void	highFivesGuys(void);
};


#endif
