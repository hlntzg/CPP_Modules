#include "ReplaceFile.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4){
		std::cerr	<< std::endl << "Error: Wrong number of arguments.\n"
					<< "Usage: ./Sed_is_for_losers <filename> <string1> <string2>\n"
					<< std::endl;
		return (1);
	}

	std::cout	<< std::endl
				<< "    WELCOME TO SED IS FOR LOSERS   " << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;
	try {
		ReplaceFile(argv[1], argv[2], argv[3]);
		return (0);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
}
