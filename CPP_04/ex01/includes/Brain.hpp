/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:56:28 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/27 16:04:53 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

class	Brain {

	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &other);
		~Brain(void);
		Brain &operator=(const Brain &other);

};

#endif
