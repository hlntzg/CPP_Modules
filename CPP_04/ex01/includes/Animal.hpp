/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:25:49 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 08:41:25 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal {

	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &other);
		virtual	~Animal(void);
		Animal &operator=(const Animal &other);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
