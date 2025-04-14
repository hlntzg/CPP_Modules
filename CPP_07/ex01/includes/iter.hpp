/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:00:54 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/14 14:18:33 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

// Template Parameters:
//	- T: The type of the elements in the array.
//	- F: The type of the function (can be a function pointer, lambda, or functor).

template	<class T, class F>
void	iter(T *array, size_t size, F function) {
	if (!array)
		std::cout << "Error: Empty array." << std::endl;
	else {
		for (size_t i = 0; i < size; i++)
			function(array[i]);
	}
}

#endif
