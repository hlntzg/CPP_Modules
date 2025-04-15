/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:03:42 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/15 10:07:25 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template	<typename T>
class	Array {
	
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(const unsigned int n);
		Array(const Array &other);
		~Array(void);
		Array &operator=(const Array &other);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int	size() const;
};

#include "Array.tpp"  // Required to ensure definitions are visible to the compiler

#endif
