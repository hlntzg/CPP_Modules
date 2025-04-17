/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:56:59 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/17 09:17:49 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

/**
 * swap: Swaps the values of two given parameters.
 * Does not return anything
 */
template	<class T>
void swap(T &a, T &b) {
	T	temp;
	temp = a;
	a = b;
	b = temp;
}

/**
 * min:  Compares the two values passed as parameters and returns the smallest one.
 * If they are equal, it returns the second one.
 * std::is_convertible<..., bool> checks if a < b is valid expression that returns 
 * something convertible to bool. If static_assert passes, the function compiles. 
 */
template	<class T>
T const &min(T &a, T &b) {
	static_assert(
        std::is_convertible<decltype(std::declval<T>() < std::declval<T>()), bool>::value,
        "Type T must support operator<"
    );
	return (a < b ? a : b);
}

/**
 * max: Compares the two values passed as parameters and returns the greatest one.
 * If they are equal, it returns the second one.
 */
template	<class T>
T const &max(T &a, T &b) {
	static_assert(
        std::is_convertible<decltype(std::declval<T>() > std::declval<T>()), bool>::value,
        "Type T must support operator>"
    );
	return (a > b ? a : b);
}

#endif

// The format for declaring function templates with type parameters is:
//	- template <class identifier> function_declaration;
//	- template <typename identifier> function_declaration;
// Either the keyword class or the keyword typename is possible,
// since both expressions have exactly the same meaning and behave exactly the same way.
