/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:08:43 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/11 14:11:56 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**
 * This function converts Data* (pointer to a Data object) to an unsigned 
 * integer type. serialize() can be use on the address of the Data object.
 */
uintptr_t	Serializer::serialize(Data* ptr) {
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

/**
 * This function converts back an unsigned integer type (uintptr_t) to a
 * pointer to Data.
 */
Data*		Serializer::deserialize(uintptr_t raw) {
    Data *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}

// reinterpret_cast is a C++ cast operator that allows you to convert between unrelated types
