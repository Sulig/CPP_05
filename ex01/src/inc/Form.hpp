/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:08:26 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/11 15:37:32 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "color.hpp"

# include <stdexcept>

# include <iostream>
# include <string>

# define F_MAX_GRADE 1
# define F_MIN_GRADE 150

class	Bureaucrat;

class	Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExecute;

	public:
		Form();
		Form(std::string const name, int gradeToSign, int gradeToExecute);
		Form(Form const &src);
		~Form();

		Form	&operator=(Form const &rhs);

		std::string const	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Form const &form);

#endif
