/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realType.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:38:13 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/11 15:25:41 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALTYPE_HPP
# define REALTYPE_HPP

#include "Base.hpp"

#include <iostream>
//# include <cstdlib>
# include <ctime>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
