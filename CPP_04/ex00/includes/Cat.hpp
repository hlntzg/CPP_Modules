/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:29:55 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/28 09:41:44 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {

	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		~Cat(void) override; // why?
		Cat &operator=(const Cat &other);

		void	makeSound(void) const override;
};

#endif
