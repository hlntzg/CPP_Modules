#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr	<< std::endl << "Error: Wrong number of arguments.\n"
					<< "Usage: ./harlFilter <level>\n"
					<< "Available level: DEBUG; INFO; WARNING; ERROR;\n"
					<< std::endl;
		return (1);
	}
	try {
		if (is_valid_level(argv[1]) == false)
			throw error;

		if (argc == 2) {
			std::string user_input(argv[1]);
			harlcomplains(user_input);
		}
		else {
			std::string	no_input("DEBUG");
			harlcomplains(no_input);
		}
	}
	catch {
	}
	

	return (0);
}

static bool	ia_valid_level(std::string& input) {
	
	std::string	level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (input == level[i])
			return (true);
	} return (false);
}

static void	harlcomplains(std::string& input) {
	
	Harl	harl;

	harl.setLevel(input);
	harl.complain()
}
