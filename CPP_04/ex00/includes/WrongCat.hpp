/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:41:24 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 09:24:57 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat &other);
		~WrongCat(void);
		WrongCat &operator=(const WrongCat &other);

		void	makeSound(void) const;
};

#endif
