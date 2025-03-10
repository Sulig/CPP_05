/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:38:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/10 17:59:22 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Bureaucrat.hpp"

int	main()
{
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	gilbert("Gilbert", 1);

	//They're Experts Bob, EXPERTS! 'Quote from Gilbert of The Increibles'
	std::cout << std::endl << "Bureaucrats created" << std::endl;
	std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;
	std::cout << gilbert.getName() << " has a grade of " << gilbert.getGrade() << std::endl;
	std::cout << std::endl;

	bob.incrementGrade();
	gilbert.decrementGrade();

	std::cout << "Bureaucrats' grades changed" << std::endl;
	std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;
	std::cout << gilbert.getName() << " has a grade of " << gilbert.getGrade() << std::endl;
	std::cout << std::endl;

	/* Try to create a bureaucrat with an invalid grade
	** This should throw an exception
	*/
	/**/
	try
	{
		Bureaucrat	invalid("Invalid", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/**/
	try
	{
		Bureaucrat	invalid("Invalid", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/*--*/
	std::cout << std::endl;

	//Try to reduce bob's grade to 151
	std::cout << bob.getName() << " has a grade of " << bob.getGrade() << std::endl;
	bob.decrementGrade();
	/**/
	try
	{
		bob.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/*--*/

	//Try to increase gilbert's grade to 0
	std::cout << gilbert.getName() << " has a grade of " << gilbert.getGrade() << std::endl;
	gilbert.incrementGrade();
	/**/
	try
	{
		gilbert.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/*--*/

	return (0);
}
