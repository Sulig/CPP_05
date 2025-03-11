/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:38:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/11 15:50:38 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"

int	main()
{
	/*** Bureaucrats */
	Bureaucrat	bob("Bob", 150);
	Bureaucrat	gilbert("Gilbert", 1);

	//They're Experts Bob, EXPERTS! 'Quote from Gilbert of The Increibles'
	std::cout << std::endl << "Bureaucrats created" << std::endl;
	std::cout << bob << std::endl;
	std::cout << gilbert << std::endl;
	std::cout << std::endl;

	bob.incrementGrade();
	gilbert.decrementGrade();

	std::cout << "Bureaucrats' grades changed" << std::endl;
	std::cout << bob << std::endl;
	std::cout << gilbert << std::endl;
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
	std::cout << bob << std::endl;
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
	std::cout << gilbert << std::endl;
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
	/**** */

	/*** Forms */
	Form	basicForm("Basic Form", F_MIN_GRADE, F_MIN_GRADE);
	Form	citizenComplaint("Citizen Complaint", 100, 50);
	Form	superHeroRegistration("Super Hero Registration", F_MAX_GRADE, F_MAX_GRADE);

	std::cout << std::endl << "Forms created" << std::endl;
	std::cout << basicForm << std::endl;
	std::cout << citizenComplaint << std::endl;
	std::cout << superHeroRegistration << std::endl;
	std::cout << std::endl;

	//Try to create a form with invalid grades
	/**/
	try
	{
		Form	invalidForm("Invalid Form", 0, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/**/
	try
	{
		Form	invalidForm("Invalid Form", 151, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/*--*/
	std::cout << std::endl;

	//Try to sign a form with a bureaucrat with a grade too low
	std::cout << "Try to sign a form with a bureaucrat with a grade too low" << std::endl;
	/**/
	try
	{
		citizenComplaint.beSigned(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/**/
	try
	{
		bob.signForm(&citizenComplaint);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/

	// Sign a form with a bureaucrat with a grade high enough
	std::cout << std::endl;
	std::cout << "Sign a form with a bureaucrat with a grade high enough" << std::endl;
	gilbert.signForm(&citizenComplaint);
	std::cout << citizenComplaint << std::endl;

	// Try to sign a form that is already signed
	std::cout << std::endl;
	std::cout << "Try to sign a form that is already signed" << std::endl;
	gilbert.signForm(&citizenComplaint);
	citizenComplaint.beSigned(gilbert);
	/*--*/
	/**** */
	std::cout << std::endl << std::endl;
	return (0);
}
