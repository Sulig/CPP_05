/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:28:47 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 16:47:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern	&operator=(Intern const &rhs);

		AForm	*makeForm(std::string const formName, std::string const target);

		class	FormNotFound : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif
