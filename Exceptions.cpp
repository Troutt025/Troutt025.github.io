//
// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
	std::cout << "Running Even More Custom Application Logic." << std::endl;

	// Buffer Overflow variables
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
	// Runs overflow function
	std::cout << "Running Custom Application Logic." << std::endl;
	try {
		if (do_even_more_custom_application_logic()) {
				std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
		}
	}

	// Catch for any overflow errors
	catch (std::overflow_error& e) {
		std::cout << "Leaving Custom Application Logic." << std::endl;
	}
}

float divide(float num, float den)
{
	// Throws error for divide by zero
	if (den == 0) {
		throw std::runtime_error("Dividing by zero error\n");
	}

	return (num / den);
}

void do_division() noexcept
{
	// Division variables
	float numerator = 10.0f;
	float denominator = 0;

	// Tries division
	try {
		auto result = divide(numerator, denominator);
		std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
	}

	// Catches a division by zero error
	catch (std::runtime_error& e) {
		std::cout << "do_division function: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "Exceptions Tests!" << std::endl;

	// Tries to perform functions and catches any exceptions or errors
	// Starting with division
	try {
		do_division();
	}
	catch (std::runtime_error& e) {
		std::cout << "main function: " << e.what() << std::endl;
	}

	// Trying application logic
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
