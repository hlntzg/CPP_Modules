/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:49:02 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/11 11:00:32 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

#include <iostream>
#include <cstdint> // For uintptr_t

class	Serializer {

	private:
		Serializer(void) = delete;
		Serializer(const Serializer &other) = delete;
		~Serializer(void) = delete;
		Serializer &operator=(const Serializer &other) = delete;

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
