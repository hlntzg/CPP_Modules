#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::cout	<< std::endl
				<< "  WELCOME TO UNNECESSARY VIOLENCE  " << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;
	
	std::cout	<< "... TESTING ATTACK FROM HUMAN A ..." << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;

	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout	<< "[✔] Attack from Human A completed" << std::endl
				<< std::endl;
	
	std::cout	<< "... TESTING ATTACK FROM HUMAN B ..." << std::endl
				<< "-----------------------------------" << std::endl
				<< std::endl;
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout	<< "[✔] Attack from Human B completed" << std::endl
				<< std::endl;

	return (0);
}
