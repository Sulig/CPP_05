/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:38:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/12 16:19:23 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Bureaucrat.hpp"
#include "inc/AForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"

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
	/******************* */

	/************* Forms */
	/// Can't create a form with invalid grades
	/**/
	/*** Shrubbery */
	ShrubberyCreationForm	shrubbery(HOME_DIRECTORY);
	ShrubberyCreationForm	shrubbery2(THIS_DIRECTORY);

	std::cout << std::endl << "Shrubbery Forms created" << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << shrubbery2 << std::endl;

	// Try to sign a form with a bureaucrat with a grade too low
	std::cout << "Try to sign a form with a bureaucrat with a grade too low" << std::endl;
	/**/
	try
	{
		shrubbery.beSigned(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/**/
	try
	{
		bob.signForm(&shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/

	// Sign and execute the forms!
	std::cout << std::endl;
	std::cout << "Singing " << shrubbery.getName() << std::endl;
	gilbert.signForm(&shrubbery);
	gilbert.signForm(&shrubbery2);

	std::cout << "Executing " << shrubbery.getName() << std::endl;
	shrubbery.execute(gilbert);
	gilbert.executeForm(shrubbery2);

	std::cout << "Try to execute" << shrubbery2.getName() << std::endl;
	/**/
	try
	{
		shrubbery2.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/*** Robotomy */
	RobotomyRequestForm	robotomy("Bender");

	std::cout << std::endl << "Robotomy Form created" << std::endl;
	std::cout << robotomy << std::endl;

	// Try to sign a form with a bureaucrat with a grade too low
	std::cout << "Try to sign a form with a bureaucrat with a grade too low" << std::endl;
	/**/
	try
	{
		robotomy.beSigned(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/

	// Sign and execute the form!
	std::cout << std::endl;
	std::cout << "Try to Singing " << robotomy.getName() << std::endl;
	/**/
	try
	{
		bob.signForm(&robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/**/
	std::cout << "Singing " << robotomy.getName() << std::endl;
	gilbert.signForm(&robotomy);

	std::cout << "Executing " << robotomy.getName() << std::endl;
	robotomy.execute(gilbert);

	std::cout << "Try to execute" << robotomy.getName() << std::endl;
	/**/
	try
	{
		robotomy.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/*** Presidential Pardon */
	PresidentialPardonForm	presidential("Zaphod Beeblebrox");

	std::cout << std::endl << "Presidential Pardon Form created" << std::endl;
	std::cout << presidential << std::endl;

	// Try to sign a form with a bureaucrat with a grade too low
	std::cout << "Try to sign a form with a bureaucrat with a grade too low" << std::endl;
	/**/
	try
	{
		presidential.beSigned(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/

	// Sign and execute the form!
	std::cout << std::endl;
	std::cout << "Try to Singing " << presidential.getName() << std::endl;
	/**/
	try
	{
		bob.signForm(&presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/
	/**/
	std::cout << "Singing " << presidential.getName() << std::endl;
	gilbert.signForm(&presidential);

	std::cout << "Executing " << presidential.getName() << std::endl;
	presidential.execute(gilbert);

	std::cout << "Try to execute" << presidential.getName() << std::endl;
	/**/
	try
	{
		presidential.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	/**/

	/*--*/
	/**** */
	std::cout << std::endl << std::endl;
	return (0);
}
