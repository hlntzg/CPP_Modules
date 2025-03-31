/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:56:28 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/31 08:41:31 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Brain.hpp"

#include <iostream>

class	Brain {

	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &other);
		~Brain(void);
		Brain &operator=(const Brain &other);

		std::string	getIdea(int i) const;
		void		setIdea(int i, const std::string& newidea);
};

#endif
