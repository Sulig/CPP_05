/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:17:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 14:24:44 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Constructor & destructor */
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", R_MIN_GRADE_TO_SIGN, R_MIN_GRADE_TO_EXECUTE)
{
	this->_target = "Default";
	std::cout << "RobotomyRequestForm created" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request", R_MIN_GRADE_TO_SIGN, R_MIN_GRADE_TO_EXECUTE)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm created" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	this->_target = src._target;
	std::cout << "RobotomyRequestForm copied" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}
/* ----- */

/* Operator overloads */
std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &form)
{
	out << "Form " << form.getName();
	out << " requires grade " << form.getGradeToSign() << " to sign";
	out << " and grade " << form.getGradeToExecute() << " to execute";
	return (out);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}
/* ----- */

/* Getters */
std::string const	&RobotomyRequestForm::getTarget() const	{	return (this->_target);	}
/* ----- */

/* Actions */
void	RobotomyRequestForm::action() const
{
	int	seed;

	srand(time(NULL));
	seed = rand() % 2;
	std::cout << std::endl;
	std::cout << "Robotomizing " << this->_target << "..." << std::endl;
	std::cout << BWHITE << "**Drilling noises**" << RESET << std::endl;
	std::cout << BCYAN << "We need this robot!!" << RESET << std::endl;
	if (seed)
	{
		std::cout << "* Someone put a trumpet on robot's head *\n" << RESET;
		std::cout << BWHITE << "**Even more drilling noises**" << RESET << std::endl;
		std::cout << MAGENTA << "* Wait, The robot is... ¿Dancing Swing? *" << std::endl;
		std::cout << BGREEN << "<|°_°|>" << "\n Now, " << this->_target << ", is robotomized\n" << RESET << std::endl;
		std::cout << BMAGENTA << " Rock it for me!!" << RESET << std::endl << std::endl;
	}
	else
	{
		std::cout << YELLOW << "Oh noo!! The gears are coming out!!" << std::endl;
		std::cout << RED << "Go for it or “Put more chrome on it”" << std::endl;
		std::cout << BYELLOW << "No! It doesn't even work with Whiskey!" << std::endl;
		std::cout << BRED << "I'm sorry, " << this->_target << " robotomy failed\n" << RESET << std::endl;
	}
}
/* ----- */
