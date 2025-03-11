/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:22:27 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/11 18:56:00 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/ShrubberyCreationForm.hpp"
#include "./inc/Bureaucrat.hpp"

/* Constructor & destructor */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE)
{
	this->_target = THIS_DIRECTORY;
	std::cout << "ShrubberyCreationForm created" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", MIN_GRADE_TO_SIGN, MIN_GRADE_TO_EXECUTE)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm created" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	this->_target = src._target;
	std::cout << "ShrubberyCreationForm copied" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}
/* ----- */

/* Operator overloads */
std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &form)
{
	out << "Form " << form.getName();
	out << " requires grade " << form.getGradeToSign() << " to sign";
	out << " and grade " << form.getGradeToExecute() << " to execute";
	return (out);
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}
/* ----- */

/* Getters */
std::string const	&ShrubberyCreationForm::getTarget() const	{	return (this->_target);	}
/* ----- */

/* Exceptions thowers */
const char	*ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return (RED "File creation failed" RESET);
}
/* ----- */

/* Actions */
void	ShrubberyCreationForm::action() const
{
	std::ofstream	file;
	std::string		filename;
	const char *homeDir = getenv("HOME");

	if (homeDir == NULL)
		filename = TARGET_FILENAME;
	else
	{
		if (this->_target == HOME_DIRECTORY)
		{
			filename = homeDir;
			filename += "/";
			filename += TARGET_FILENAME;
		}
		else if (this->_target == THIS_DIRECTORY)
			filename = TARGET_FILENAME;
		else
		{
			filename = homeDir;
			filename += "/";
			filename += this->_target;
			filename += "/";
			filename += TARGET_FILENAME;
		}
	}
	std::cout << "Creating file: " << filename << std::endl;
	file.open(filename.c_str());
	if (!file.is_open())
		throw FileCreationException();
	else
	{
		file << TREE;
		file.close();
	}
	std::cout << GREEN << "ShrubberyCreationForm executed" << RESET << std::endl;
}
/* ----- */
