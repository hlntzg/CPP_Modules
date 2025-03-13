#include "ReplaceFile.hpp"

ReplaceFile::ReplaceFile(const std::string& filename, const std::string& string1, const std::string& string2) : 
	_infile(filename), _search(string1), _replace(string2)
{
	if (_search.empty()) {
		throw std::invalid_argument("Error: Search string cannot be empty.");
	}
	
	// open filename
	std::ifstream		file(filename);
	if (!file)
        throw std::ios_base::failure("Error: Cannot open file '" + filename + "' ");

	// check empty file (move to the end, if size is 0, it's empty)
    file.seekg(0, std::ios::end);
    if (file.tellg() == 0) {
        throw std::invalid_argument("Error: File cannot be empty.");
    }
    file.seekg(0, std::ios::beg);  // move back to the beginning of the file

	// create outfile with ".replace"
	const std::string			outfile = filename + ".replace";
	_outfile.open(outfile);
	if (!_outfile) {
        throw std::ios_base::failure("Error: Cannot create new file '" + outfile + "' ");
	}

	// read, process and get each line
	std::string			line;
	while (std::getline(file, line)) {
		_outfile << _replaceString(line) << std::endl;
	}

	std::cout << "Success: '" << outfile << "' created." << std::endl;
}

ReplaceFile::~ReplaceFile() {}

std::string	ReplaceFile::_replaceString(const std::string& line)
{
	std::string	result;
	size_t		start = 0;
	size_t		match;

	while ((match = line.find(_search, start)) != std::string::npos) {
		result.append(line, start, match - start);		// copy part before match
		result.append(_replace);						// append _replace string
		start = match + _search.length();				// move past the matched substring
	}
	result.append(line, start, line.length() - start);	// append the remaining part
	return (result);
}
