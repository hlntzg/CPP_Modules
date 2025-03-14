#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
# define WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable! I want to speak to the manager now."

enum	levelFilter {
		DEBUG,
		INFO,
		WARNING,
		ERROR
};

class	Harl {

	private:
		std::string	_levelFilter;
		void		_debug(void);
		void		_info(void);
		void		_warning(void);
		void		_error(void);

	public:
		Harl(void);
		~Harl(void);
		
		void		setLevel(const std::string& input);
		levelFilter	getLevel(void) const;
		
		void	complain(std::string& level);
};

#endif
