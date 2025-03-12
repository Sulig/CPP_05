/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:04:30 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 16:17:06 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/PresidentialPardonForm.hpp"

/* Constructor & destructor */
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", P_MIN_GRADE_TO_SIGN, P_MIN_GRADE_TO_EXECUTE)
{
	this->_target = "Zafod Beeblebrox";
	std::cout << "PresidentialPardonForm created with " << this->_target << " as default target" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Pardon", P_MIN_GRADE_TO_SIGN, P_MIN_GRADE_TO_EXECUTE)
{
	this->_target = target;
	std::cout << "PresidentialPardonForm created with " << this->_target << " as target" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	this->_target = src._target;
	std::cout << "PresidentialPardonForm copied with " << this->_target << " as target" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm with target " << this->_target << " destroyed" << std::endl;
}
/* ----- */

/* Operator overloads */
std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &form)
{
	out << form.getName() << " form with target " << form.getTarget();
	return (out);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}
/* ----- */

/* Getters */
std::string const	&PresidentialPardonForm::getTarget() const	{	return (this->_target);	}
/* ----- */

/* Actions */
void	PresidentialPardonForm::action() const
{
	std::cout << GREEN;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	std::cout << RESET << BLUE;
	std::cout << "This don't change anything, but now it's *officially* inocent" << std::endl;
	std::cout << RESET;
}
/* ----- */
