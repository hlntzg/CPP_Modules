/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:33:56 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 12:32:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {

	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &other);
		~Dog(void);
		Dog &operator=(const Dog &other);

		void	makeSound(void) const override;
};

#endif
