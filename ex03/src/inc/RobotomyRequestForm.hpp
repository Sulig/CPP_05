/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:13:23 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 13:53:21 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# include <cstdlib>

# define R_MIN_GRADE_TO_SIGN	72
# define R_MIN_GRADE_TO_EXECUTE	45

class	Bureaucrat;

class	RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

		std::string const	&getTarget() const;

		virtual void	action() const;
};

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif
