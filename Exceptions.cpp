// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
	// TODO: Throw any standard exception

	std::cout << "Running Even More Custom Application Logic." << std::endl;

	// Buffer Overflow exception example
	short max = 32767; // Max length of short
	short num1 = 32766; // Max length of short -1
	short num2 = 2; // Just enough to overflow num1 if added.

	// Tests for overflow
	if ((num2 > 0) && (num1 <= max - num2)) {
		short result = num1 + num2;
		std::cout << result << std::endl;
	}
	else { // Overflow found
		throw std::overflow_error("Overflow Found\n");
	}

	return true;
}
void do_custom_application_logic()
{
	// TODO: Wrap the call to do_even_more_custom_application_logic()
	//  with an exception handler that catches std::exception, displays
	//  a message and the exception.what(), then continues processing
	std::cout << "Running Custom Application Logic." << std::endl;
	try {
		if (do_even_more_custom_application_logic()) {
				std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
		}
	}

	// TODO: Throw a custom exception derived from std::exception
	//  and catch it explictly in main
	catch (std::overflow_error& e) {
		std::cout << "Leaving Custom Application Logic." << std::endl;
	}
}

float divide(float num, float den)
{
	// TODO: Throw an exception to deal with divide by zero errors using
	//  a standard C++ defined exception
	if (den == 0) {
		throw std::runtime_error("Dividing by zero error\n");
	}

	return (num / den);
}

void do_division() noexcept
{
	//  TODO: create an exception handler to capture ONLY the exception thrown
	//  by divide.

	float numerator = 10.0f;
	float denominator = 0;
	try {
		auto result = divide(numerator, denominator);
		std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cout << "do_division function: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "Exceptions Tests!" << std::endl;

	// TODO: Create exception handlers that catch (in this order):
	//  your custom exception
	//  std::exception
	//  uncaught exception 
	//  that wraps the whole main function, and displays a message to the console.
	try {
		do_division();
	}
	catch (std::runtime_error& e) {
		std::cout << "main function: " << e.what() << std::endl;
	}

	try {
		do_custom_application_logic();
	}
	catch (std::overflow_error& e) {
		std::cout << "main function: " << e.what() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "main function: " << e.what() << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
