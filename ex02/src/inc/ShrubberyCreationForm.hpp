/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:22:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 13:19:02 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Shrubberry.hpp"

# include <fstream>
# include <cstdlib>

# define S_MIN_GRADE_TO_SIGN	145
# define S_MIN_GRADE_TO_EXECUTE	137
# define TARGET_FILENAME		"_shrubbery"
# define THIS_DIRECTORY			"."
# define HOME_DIRECTORY			"~"

# define TREE SHRUBBERY

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

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
};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif
