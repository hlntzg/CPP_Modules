/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:26:18 by hutzig            #+#    #+#             */
/*   Updated: 2025/03/19 16:26:20 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_FILE_HPP
# define REPLACE_FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

class ReplaceFile {
	private:
		std::string		_infile;
		std::string		_search;
		std::string		_replace;
		std::ofstream	_outfile;

		std::string		_replaceString(const std::string& line);

	public:
		ReplaceFile(const std::string& filename, const std::string& string1, const std::string& string2);
		~ReplaceFile(void);
};

#endif
