/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:00:08 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/18 15:25:15 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

/**
 * template <class T, class Container = deque<T> > class stack;
 * https://cplusplus.com/reference/stack/stack/
 *
 * MutantStack template class defined by T (type of data: int, std::string, etc.)
 * and Container (underlying storage, set to std::deque<T> as default).
 * MutantStack inherits from std::stack<T, Container>, so it can access public and
 * protected members (empy(), size(), top(), push(), emplace(), pop(), swap()).
 *
 * Iterator functions: The underlying container (std::stack) has a protected member (c).
 * By inheriting from std::stack, MutantStack can access c.
 */

template	<typename T, typename Container = std::deque<T>>
class	MutantStack : public std::stack<T, Container> {

	public:
		// Inherit constructors
		using std::stack<T, Container>::stack;
		
		// Orthodox Canonical Form
		MutantStack(void) : std::stack<T, Container>() {}
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
		~MutantStack(void) {}
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other) {
				std::stack<T, Container>::operator=(other);
			}
			return (*this);
		}

		// Typedefs for iterators
		using iterator = typename Container::iterator;
		using const_iterator = typename Container::const_iterator;
		using reverse_iterator = typename Container::reverse_iterator;
		using const_reverse_iterator = typename Container::const_reverse_iterator;

		// Iterator functions: mutable forward
		iterator				begin() { return (this->c.begin()); }
		iterator				end() { return (this->c.end()); }

		// Iterator functions: read-only
		const_iterator			begin() const { return (this->c.begin()); }
		const_iterator			end() const { return (this->c.end()); }

		// Iterator functions: mutable reverse
		reverse_iterator		rbegin() { return (this->c.rbegin()); }
		reverse_iterator		rend() { return (this->c.rend()); }

		// Iterator functions: backwards read-only
		const_reverse_iterator	rbegin() const { return (this->c.rbegin()); }
		const_reverse_iterator	rend() const { return (this->c.rend()); }
};

#endif
