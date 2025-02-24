/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:35:36 by hutzig            #+#    #+#             */
/*   Updated: 2025/02/24 18:59:29 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook{
	private:
		int		_index;
		int		_count;
		Contact _contacts[8];

	public:
		// Constructor & Destructor
		PhoneBook();
		~PhoneBook();
		
		void	addContact();
		void	searchContact();
		std::string truncate(const std::string &str);
};

#endif
