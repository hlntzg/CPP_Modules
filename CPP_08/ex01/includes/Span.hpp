/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:57:23 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/17 15:16:27 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class	Span {

	private:
		unsigned int		_size;
		std::vector<int>	_vector;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &other);
		~Span(void);
		Span &operator=(const Span &other);

		void			addNumber(int n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		void			addNumbersRange(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
};

#endif
