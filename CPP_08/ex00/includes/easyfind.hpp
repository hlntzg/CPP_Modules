/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:43:45 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/17 13:43:54 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>   // for std::find
#include <iostream>    // for std::cout, std::endl
#include <stdexcept>   // for std::runtime_error
#include <type_traits> // For std::is_same

template	<typename T>
int	easyfind(T &container, int value) {
	
	// Compile-time check: static_assert with std::is_same enforces type constraints at compile time.
	// If you pass a container with a value type other than int, compilation fails with custom message.
    static_assert(std::is_same<typename T::value_type, int>::value, "Container must hold integers (int)");

	auto i = std::find(container.begin(), container.end(), value);
	if (i == container.end())
		throw std::runtime_error("Element " + std::to_string(value) + " not found.");			
	return (*i);
}

#endif
