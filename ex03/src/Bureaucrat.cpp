/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:37:43 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/11 18:59:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Bureaucrat.hpp"
#include "./inc/AForm.hpp"

/* Constructor & destructor */
Bureaucrat::Bureaucrat() : _name("Bob"), _grade(B_MIN_GRADE)
{
	std::cout << "Default Bureaucrat " << this->_name;
	std::cout << " created with " << this->_grade << " as default grade" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < B_MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > B_MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat " << this->_name;
	std::cout << " created with " << this->_grade << " as grade" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat " << this->_name;
	std::cout << " copied with " << this->_grade << " as grade" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name;
	std::cout << " destroyed" << std::endl;
}
/* ----- */

/* Operator overloads */
std::ostream	&operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}
/* ----- */

/* Getters */
std::string const	&Bureaucrat::getName() const {	return (this->_name);	}
int					Bureaucrat::getGrade() const {	return (this->_grade);	}
/* ----- */

/* Exceptions thowers */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high, maximum is 1");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low, minimum is 150");
}
/* ----- */

/* Actions */
void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < B_MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > B_MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(AForm *form)
{
	if (form->getSigned())
		std::cout << this->_name << " cannot sign " << form->getName() << " because it's already signed";
	else if (this->_grade > form->getGradeToSign())
		std::cout << this->_name << " cannot sign " << form->getName() << " because grade is too low";
	else
	{
		form->beSigned(*this);
		std::cout << this->_name << " signs " << form->getName();
	}
	std::cout << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	if (!form.getSigned())
		std::cout << this->_name << " cannot execute " << form.getName() << " because it's not signed";
	else if (this->_grade > form.getGradeToExecute())
		std::cout << this->_name << " cannot execute " << form.getName() << " because grade is too low";
	else
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName();
	}
	std::cout << std::endl;
}
/* ----- */
