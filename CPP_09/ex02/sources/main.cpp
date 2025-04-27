/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:19:42 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/24 17:25:01 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {

	try {
		
		PmergeMe	pmm;

		pmm.saveData(argc, argv);
		pmm.runAlgorithmVectorContainer(argc, argv);
		pmm.runAlgorithmDequeContainer(argc, argv);
		pmm.displayInformations();

	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}

	return (0);
}