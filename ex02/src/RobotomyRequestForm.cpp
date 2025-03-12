/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:17:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 17:36:01 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* Constructor & destructor */
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", R_MIN_GRADE_TO_SIGN, R_MIN_GRADE_TO_EXECUTE)
{
	srand(time(NULL));
	this->_target = "Default";
	std::cout << "RobotomyRequestForm created" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request", R_MIN_GRADE_TO_SIGN, R_MIN_GRADE_TO_EXECUTE)
{
	srand(time(NULL));
	this->_target = target;
	std::cout << "RobotomyRequestForm created" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	srand(time(NULL));
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

	seed = rand() % 2;
	std::cout << std::endl;
	std::cout << "Robotomizing " << this->_target << "..." << std::endl;
	std::cout << BCYAN << "* Take a drill and start drilling * " << RESET << std::endl;
	std::cout << BWHITE << "**Drilling noises**" << RESET << std::endl;
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
		std::cout << RED << "The drill broke... " << RESET << std::endl;
		std::cout << BWHITE << "Why the hands of the robot has converted in chainsaws??" << RESET << std::endl;
		std::cout << BRED << "Homer, run!!" << RESET << std::endl << std::endl;
	}
}
/* ----- */
