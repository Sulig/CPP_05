/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:40:29 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/10 20:03:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Form.hpp"

/* Constructor & destructor */
Form::Form() : _name("Default")
{
	this->_signed = false;
	this->_gradeToSign = F_MIN_GRADE;
	this->_gradeToExecute = F_MIN_GRADE;

	std::cout << "Default Form " << this->_name;
	std::cout << " created with " << this->_gradeToSign << " as default grade to sign";
	std::cout << " and " << this->_gradeToExecute << " as default grade to execute" << std::endl;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name)
{
	if (gradeToSign < F_MAX_GRADE || gradeToExecute < F_MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > F_MIN_GRADE || gradeToExecute > F_MIN_GRADE)
		throw Form::GradeTooLowException();
	else
	{
		this->_signed = false;
		this->_gradeToSign = gradeToSign;
		this->_gradeToExecute = gradeToExecute;
	}
	std::cout << "Form " << this->_name;
	std::cout << " created with " << this->_gradeToSign << " as grade to sign";
	std::cout << " and " << this->_gradeToExecute << " as grade to execute" << std::endl;
}

Form::Form(Form const &src) : _name(src._name)
{
	this->_signed = src._signed;
	this->_gradeToSign = src._gradeToSign;
	this->_gradeToExecute = src._gradeToExecute;

	std::cout << "Form " << this->_name;
	std::cout << " copied with " << this->_gradeToSign << " as grade to sign";
	std::cout << " and " << this->_gradeToExecute << " as grade to execute" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->_name;
	std::cout << " destroyed" << std::endl;
}
/* ----- */

/* Operator overloads */
std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << ", signed: " << form.getSigned();
	out << ", grade to sign: " << form.getGradeToSign();
	out << ", grade to execute: " << form.getGradeToExecute();
	return (out);
}

Form	&Form::operator=(Form const &rhs)
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
std::string const	&Form::getName() const			{	return (this->_name);			}
bool				Form::getSigned() const			{	return (this->_signed);			}
int					Form::getGradeToSign() const	{	return (this->_gradeToSign);	}
int					Form::getGradeToExecute() const	{	return (this->_gradeToExecute);	}
/* ----- */

/* Exceptions thowers */
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high, maximum is 1");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low, minimum is 150");
}
/* ----- */

/* Actions */
void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else if (this->_signed)
		std::cout << "Form " << this->_name << " is already signed" << std::endl;
	else
		this->_signed = true;
}
/* ----- */
