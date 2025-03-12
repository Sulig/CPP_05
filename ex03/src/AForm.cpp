/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:40:29 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/11 15:56:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/AForm.hpp"
#include "./inc/Bureaucrat.hpp"

/* Constructor & destructor */
AForm::AForm() : _name("Default")
{
	this->_signed = false;
	this->_gradeToSign = F_MIN_GRADE;
	this->_gradeToExecute = F_MIN_GRADE;

	std::cout << "Default AForm " << this->_name;
	std::cout << " created with " << this->_gradeToSign << " as default grade to sign";
	std::cout << " and " << this->_gradeToExecute << " as default grade to execute" << std::endl;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name)
{
	if (gradeToSign < F_MAX_GRADE || gradeToExecute < F_MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > F_MIN_GRADE || gradeToExecute > F_MIN_GRADE)
		throw AForm::GradeTooLowException();
	else
	{
		this->_signed = false;
		this->_gradeToSign = gradeToSign;
		this->_gradeToExecute = gradeToExecute;
	}
	std::cout << "AForm " << this->_name;
	std::cout << " created with " << this->_gradeToSign << " as grade to sign";
	std::cout << " and " << this->_gradeToExecute << " as grade to execute" << std::endl;
}

AForm::AForm(AForm const &src) : _name(src._name)
{
	this->_signed = src._signed;
	this->_gradeToSign = src._gradeToSign;
	this->_gradeToExecute = src._gradeToExecute;

	std::cout << "AForm " << this->_name;
	std::cout << " copied with " << this->_gradeToSign << " as grade to sign";
	std::cout << " and " << this->_gradeToExecute << " as grade to execute" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name;
	std::cout << " destroyed" << std::endl;
}
/* ----- */

/* Operator overloads */
std::ostream	&operator<<(std::ostream &out, AForm const &form)
{
	out << "AForm " << form.getName() << ", signed: " << form.getSigned();
	out << ", grade to sign: " << form.getGradeToSign();
	out << ", grade to execute: " << form.getGradeToExecute();
	return (out);
}

AForm	&AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExecute = rhs._gradeToExecute;
	}
	return (*this);
}
/* ----- */

/* Getters */
std::string const	&AForm::getName() const			{	return (this->_name);			}
bool				AForm::getSigned() const			{	return (this->_signed);			}
int					AForm::getGradeToSign() const	{	return (this->_gradeToSign);	}
int					AForm::getGradeToExecute() const	{	return (this->_gradeToExecute);	}
/* ----- */

/* Setters */
void	AForm::setSigned(bool sign)	{	this->_signed = sign;	}
/* ----- */

/* Exceptions thowers */
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high, maximum is 1");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low, minimum is 150");
}
/* ----- */

/* Actions */
///	void	AForm::action() const = 0;

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->setSigned(true);
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
	{
		std::cout << "Form not signed" << std::endl;
		return ;
	}
	else if (executor.getGrade() > this->getGradeToExecute())
	{
		std::cout << "Executor grade is too low to execute the form" << std::endl;
		return ;
	}
	else
		this->action();
}
/* ----- */
