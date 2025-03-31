/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:33:56 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 08:41:45 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {

	private:
		Brain*	_dogBrain;

	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &other);
		~Dog(void) override;
		Dog &operator=(const Dog &other);

		void	makeSound(void) const override;
		Brain*	getBrain(void);
};

#endif
