/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:35:36 by hutzig            #+#    #+#             */
/*   Updated: 2025/02/22 20:23:37 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>

class PhoneBook{
	private:
		int		_index;
		int		_count;

	public:
		// Constructor & Destructor
		PhoneBook();
		~PhoneBook();
		
		void	addContact();
		void	searchContact();
};

#endif
