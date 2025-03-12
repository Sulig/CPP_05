/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:28:59 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 16:58:53 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Intern.hpp"
#include "./inc/ShrubberyCreationForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/PresidentialPardonForm.hpp"

/* Constructor & destructor */
Intern::Intern()					{	std::cout << "Intern created" << std::endl;		}
Intern::Intern(Intern const &src)	{					*this = src;					}
Intern::~Intern()					{	std::cout << "Intern destroyed" << std::endl;	}
/* ----- */

/* Operator overloads */
Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}
/* ----- */

/* Exceptions thowers */
const char	*Intern::FormNotFound::what() const throw()
{
	return ( RED "Eror 404, Form not found!" RESET );
}
/* ----- */

/* Action */
AForm	*Intern::makeForm(std::string const formName, std::string const target)
{
	AForm				*form;
	std::string const	formCreators[4] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	int					formIndex = 5;

	for (int i = 0; i < 4; i++) {
		if (formName == formCreators[i]) {
			formIndex = i;
			break;
		}
	}

	switch (formIndex)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::FormNotFound();
	}
	return (form);
}
/* ----- */
