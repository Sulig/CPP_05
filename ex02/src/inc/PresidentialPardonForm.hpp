/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:04:21 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 16:05:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define P_MIN_GRADE_TO_SIGN	25
# define P_MIN_GRADE_TO_EXECUTE	5

class	Bureaucrat;

class	PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

		std::string const	&getTarget() const;

		virtual void	action() const;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif
