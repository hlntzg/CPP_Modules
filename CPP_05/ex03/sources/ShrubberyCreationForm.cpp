/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:49:06 by hutzig            #+#    #+#             */
/*   Updated: 2025/04/04 15:23:39 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

constexpr const char ASCII_TREE[] =
R"(........................................................................................................................
........................................................................................................................
........................................................................................................................
........................................................................................................................
........................................................................................................................
........................................................................................................................
........................................................................................................................
.........................................................=...=..........................................................
......................................................=.====.===.=.=....................................................
....................................................========.==========.................................................
...............................................===========I================.............................................
.........................................=....========I===II=I=I=III=I======............................................
.........................................=.=.======I==III=II=III=II==I======............................................
.......................................=.==========II=IIIIII=I=IIII=I=====I=.===........................................
.....................................=..========I===IIIIIIII=IIIIII=I=I==II======.==....................................
.....................................============I=II=IIIIIIIAIIIAI=I====II========.==..................................
....................................=====I=I===I=.=III=IIIIAAIIIIAI=I==IIII============.................................
.....................................=====II==III==IIAI=IIIAII=AIAIII=IIII===II=======..................................
...................................==.======II=III==IAIIIIIAII=AAIII=II==I===II=I=====.==.=.............................
....................................========IIIIIII=IIAIIIAAIIIIAIII==I==I==IIIII==I===.===.............................
.............................=....=========IIIIIIIIIIIAIIAAAIIIIAIII=IAIII=IIIIIIII=========..==........................
..............................===.======I===IIAAAIIIIAAAIAAAAIAIAIIIIIAIIIAIIAAI======.=======.==.......................
............................===I===========IIIIAAAIIIIAAAAAAAIAIAIAI=II=IAAIII===I==============........................
..............................==I======III==IIIIIIAAI=AAIAAXAAAAIAAIIAAIAAIIIIII=I===IIII======....=....................
............................=..=IAI===IIIIIIIIIIIAAAAAIAIXIXAAXAIAXAAIIAAAIIAII=IIIIIII=======..===.....................
...........................====..IAII=IIIII=IIIIAIAIAAAAAXAXAAXAIAAAIAAAAIIIAIIIIIIIIII=====.=.===......................
..................=........=======IIIIIIIIIAIIIIIIIAAXAAAXAAXXXAIXAIAXIAAA=AIIA==I=II=====I=====........................
..................==......=========IIAIIIAIIIIAAAIIIAAAAAXAXXXXAAXAAAAAAAIAIIII==III=======.=========...................
...................=I==..=====I======IIIIIAAIAIIIAAAAAXXAXXXXAXAAXAXXIAAIAIIIIIIAII==.==IIII==III===....................
....................=II===I====IIIIIIIAAAAIAAAAAIIIAXXXXXXXXXXXAAAAAAAXAAAAAAAAIIIIIAAAAIIIIII====......................
....................==IIIIIIIIIIIIAAAAAAXAAAAIIIAIIIAXXXMXXXMXAAXXIAXAAXAAAAIII=IIII======IIII=I=====...................
................==..====IIIIAAAIIIIAIAAAAAXAAXAIIIAAAIXAAMXMMMXXAAXXXXXXAIIIIIIAIIIIIIIIIIIIIII========.................
...............=====I====IIAAAAAIII=====IIAXXAXXAAIAAAAXIAMMXMXAAAXMMXAIIAAAI=====IIIIIIIAII========....................
...................=====IIIIIIAAAAAAAIIIIIIAAAIAAXMMXXXXXXMMXMMXXMMXAIAAAAAIII====IIAAAAIIII====.=.........=............
...................========IIIIIAXXAAAIIAIIIIIAAAIAXAAAXAXXMMMXXMMMAAIAAAAAAIAIIIIAAAIAIII==========..=====.............
................=======II=========IAAAAXXXXAAAAAXXAAXAAIXMMMMXXMMMAIAAAAIAAXXAAAAAII==II=========..======...............
..........========.======IIIIIIIIIIIAAAXXXXXXXXAAXXXXXXXAXMMMMMMXXAAAXAAAAAXAAAAAIIIIIIIIIIIIIIIIIII===.................
............===IIIAIIIIIIIIAIAAAAXXXXXXXXXXXXXAXXAXAXXMXXMMMMMMXMXXXXAAAAAAAIIAIIAAAAAAIAAIIIIIII=====..................
................=======IIIIIIIAAAAAAAAAXAXAAAAXMMMXXAAMXIAMMMMMMMXMXXXXXXXXXXXAAAIIIIIIIIIIIIAII========................
.................====II==I=IIIIIIIIAIAAXAAAAXXXXXXXMXXXMMAMMMMXIAXXAAXXXXXXXXXXAAAAAAAAAIAAIIIIII=====..................
...............====================IIIAAAXAXXXXXAXXMMMMMXMMWMMMMXXXXXAAAAAAIAAXXXAAAAAII================................
.....................==...======IIIAAAXXXAAAAXAXIAAIAXMMAAMWWMXAXAAXXXAXAAXXAXAXXXAIIIIIII====I=======.=................
..................=====IIIIIIAAAAAAAAAAAI=IAIAAA=IIAXXAXMXMMMXIAAAAXXXXXAXAIAAAAAAAAAAAAIIIII==========.................
.................=====IIIIIIAAAIIIII=I=IIIIAXAAIAAIAXXXAIMMMMXIAIAAXXXAAXXXXXAIIIAAAIAAIAIIIII=====I====................
.................=======III=I======IIIIIIIAXAAAAIIAAIIIAAAMMMAAAAAIIIAXXXMXXXXAIII==IIIII==IIIII=======.................
................=================II==IIIAAAAAAAIIAI===IIIMMMMXAIIAIIIIIAAXXXXXXXAAII==IIII========.====.................
..................====..=============IIAAAAAIIIIIII===IIIXMMMAIIAIIAIII=IAAAAAXXAAIIAII==============...................
........................============IAAAIAII===I======I==AMMMAIII=IAI====IIIAAAAAAAAIIIIIII===========..................
......................======..======III===II============IIMMMIIIIIII=====I===IAAAAIAAI=I========........................
===================.....==....==============I=============MMMI=================IIAAIIIIIIII========.....................
==========================.....================..=========MMMI===================IIIIII====I==.==.......................
==============================================....========MMMI=.......=================I===I====........................
================================================..=.======MMMA==......==.=.......===..===.===.==........................
==========================================================MMMA=================.=========..==.......=========...........
==========================================================MMMX==========================================================
=========================================================IMMMX==========================================================
========II==IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIAAAIIAIIXMMMMAIIIIAAAIIIIIIIIIIIIIII=IIIII=IIIIIIIIIIII================
XXXXXXXXXXXXXXXXXXXXXXXXXXMXXXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMWMMMMMWWWWMMWWWWWWWWWWWWMWMWMMWMMWMMMMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM)";

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("DefaultShrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void)  {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (this->getSignedForm() == false)
		throw AForm::FormNotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	
	std::ofstream	outfile(this->_target + "_shrubbery");
	if (!outfile) {
		throw std::runtime_error("Error: Could not open the file in  Shrubbery class");
	}
	outfile  << ASCII_TREE;
	outfile.close();
}
