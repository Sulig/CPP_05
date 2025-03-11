/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:08:26 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/11 19:00:38 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "color.hpp"

# include <stdexcept>

# include <iostream>
# include <string>

# define F_MAX_GRADE 1
# define F_MIN_GRADE 150

class	Bureaucrat;

class	AForm
{
	public:
		virtual ~AForm();
		virtual void	action() const = 0;

		void	beSigned(Bureaucrat const &bureaucrat);
		void	execute(Bureaucrat const &executor) const;

		std::string const	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

	private:
		std::string const	_name;
		bool				_signed;
		int					_gradeToSign;
		int					_gradeToExecute;

	protected:
		AForm();
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);

		AForm	&operator=(AForm const &rhs);

		void	setSigned(bool sign);

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

std::ostream	&operator<<(std::ostream &out, AForm const &form);

#endif
