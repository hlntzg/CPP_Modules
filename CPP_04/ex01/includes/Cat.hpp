/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:29:55 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 16:18:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {

	private:
		Brain*	_catBrain;

	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		~Cat(void);
		Cat &operator=(const Cat &other);

		void	makeSound(void) const override;
};

#endif
