//
// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
using namespace std;

bool do_even_more_custom_application_logic()
{
	cout << "Running Even More Custom Application Logic." << endl << endl;

	// Buffer Overflow variables
	short num1 = 32766; // Max length of short -1
	short num2 = 2; // Just enough to overflow num1 if added.

	// Tests for overflow
	if ((num2 > 0) && (num1 <= SHRT_MAX - num2)) {
		short result = num1 + num2;
		cout << result << endl << endl;
	}
	else { // Overflow found
		throw overflow_error("Overflow Found\n");
	}

	return true;
}

void do_custom_application_logic()
{
	// Runs overflow function
	cout << "Running Custom Application Logic." << endl << endl;
	try {
		if (do_even_more_custom_application_logic()) {
				cout << "Even More Custom Application Logic Succeeded." << endl;
		}
	}

	// Catch for any overflow errors
	catch (overflow_error& e) {
		cout << "do_even_more_custom_application_logic function: " << e.what() << endl;
	}
}

float divide(float num, float den)
{
	// Throws error for divide by zero
	if (den == 0) {
		throw runtime_error("Dividing by zero error\n");
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
		cout << numerator << " / " << denominator << " = " << result << endl << endl;
	}

	// Catches a division by zero error
	catch (runtime_error& e) {
		cout << "do_division function: " << e.what() << endl;
	}
}

int main()
{
	cout << "Exceptions Tests!" << endl << endl;

	// Tries to perform functions and catches any exceptions or errors
	// Starting with division
	try {
		do_division();
	}
	catch (runtime_error& e) {
		cout << "main function: " << e.what() << endl;
	}

	// Trying application logic
	try {
		do_custom_application_logic();
	}
	catch (overflow_error& e) {
		cout << "main function: " << e.what() << endl;
	}
	catch (exception& e) {
		cout << "main function: " << e.what() << endl;
	}
}
