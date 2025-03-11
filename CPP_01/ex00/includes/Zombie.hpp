/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 09:51:18 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/11 12:00:45 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:	
		std::string	_name;
	
	public:
		Zombie(std::string name);
		~Zombie();

		void		setName(std::string name);
		std::string	getName(void);

		void	announce(void);

};
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
