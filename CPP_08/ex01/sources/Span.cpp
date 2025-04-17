/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:20 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/17 15:19:30 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N) {}

Span::Span(const Span &other) : _size(other._size), _vector(other._vector) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_size = other._size;
		_vector = other._vector;
	}
	return (*this);
}

void	Span::addNumber(int n) {
	if (_vector.size() >= _size)
		throw std::overflow_error("Error: Span is full. Failure to add element.");
	_vector.push_back(n);
}

unsigned int	Span::shortestSpan() {
	if (_vector.size() < 2)
		throw std::domain_error("Error: Not enough elements to compute the shortest span.");

    std::vector<int>	sorted = _vector;
    std::sort(sorted.begin(), sorted.end());

    unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); i++)
	{
        unsigned int temp = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (temp < shortestSpan)
            shortestSpan = temp;
    }
    return (shortestSpan);	
}

unsigned int	Span::longestSpan() {
	if (_vector.size() < 2)
		throw std::domain_error("Error: Not enough elements to compute the longest span.");

	auto [minIt, maxIt] = std::minmax_element(_vector.begin(), _vector.end());
    return (static_cast<unsigned int>(*maxIt - *minIt));
}

void	Span::addNumbersRange(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last) 
{
    size_t range_size = std::distance(first, last);
    if (_vector.size() + range_size > _size)
        throw std::overflow_error("Error: Span will exceed its limit. Cannot add range.");
    _vector.insert(_vector.end(), first, last);
}
