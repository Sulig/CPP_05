/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:22:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/11 20:02:06 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Shrubberry.hpp"

# include <fstream>
# include <cstdlib>

# define MIN_GRADE_TO_SIGN		145
# define MIN_GRADE_TO_EXECUTE	137
# define TARGET_FILENAME		"_shrubbery"
# define THIS_DIRECTORY			"."
# define HOME_DIRECTORY			"~"

# define TREE SHRUBBERY

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		std::string const	&getTarget() const;

		virtual void	action() const;

		class FileCreationException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		std::string	_target;
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif
