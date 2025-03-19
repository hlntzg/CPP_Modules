/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:24:28 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/19 16:24:31 by hutzig           ###   ########.fr       */
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
		Zombie();
		~Zombie();
		
		void		setName(std::string name);
		std::string	getName(void);

		void	announce(void);

};

Zombie*	zombieHorde(int N, std::string name);

#endif
