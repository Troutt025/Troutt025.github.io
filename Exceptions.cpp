//
// Exceptions.cpp : Program is meant to test user input for any buffer overflow or underflow. Also tests for divide by zero errors. 
//

#include <iostream>
#include <limits>
using namespace std;

// Validates user input will not overflow or underflow a short variable
short getShort() {
	short shrtNum;

	// User input checks for short variable
	while (!(cin >> shrtNum) || shrtNum < SHRT_MIN || shrtNum > SHRT_MAX) {
		if (!cin) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		cout << "Invalid number\nPlease input a valid number: ";
	}
	return shrtNum;
}

// Validates usser input will not overflow or underflow a float variable
float getFloat() {
	float fltNum;

	// User input checks for float variable
	while (!(cin >> fltNum) || fltNum < FLT_MIN || fltNum > FLT_MAX) {
		if (!cin) {
			cin.clear();
			cin.ignore(1024, '\n');
		}
		cout << "Invalid number\nPlease input a valid number: ";
	}
	return fltNum;
}

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
	catch (overflow_error & e) {
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
	cout << "Beginning division section" << endl << endl;
	// Division variables
	float numerator = 10.0f;
	float denominator = 2.0f;

	// Allows user to input variables for numerator and denominator to test dividing
	cout << "Please input numerator: ";
	numerator = getFloat();
	cout << endl << endl;

	cout << "Please input denominator: ";
	denominator = getFloat();
	cout << endl << endl;

	cout << "Performing division" << endl << endl;

	// Tries division
	try {
		auto result = divide(numerator, denominator);
		cout << numerator << " / " << denominator << " = " << result << endl << endl;
	}

	// Catches a division by zero error
	catch (runtime_error & e) {
		cout << "do_division function: " << e.what() << endl;
	}
}

float multiply(short plicand, short plier)
{
	// Tests if either numbers are zero, if so no overflow/underflow could happen
	if (plier == 0 || plicand == 0) {
		return (plicand * plier);
	} // Tests for overflow
	else if (((plier > 0) && (plicand > 0) && (plicand > SHRT_MAX / plier)) || ((plier < 0) && (plicand < 0) && (plicand < SHRT_MAX / plier))) {
		throw overflow_error("Overflow error\n");
	} // Tests for underflow
	else if (((plier > 0) && (plicand < 0) && (plicand < SHRT_MIN / plier)) || ((plier < 0) && (plicand > 0) && (plicand > SHRT_MIN / plier))) {
		throw underflow_error("Underflow error\n");
	}
	else {
		return (plicand * plier);
	}
}

void do_multiplication() noexcept
{
	cout << "Beginning multiplication section" << endl << endl;

	// Multiplication variables
	short multiplicand = 8;
	short multiplier = 8;

	// Allows user to input variables
	cout << "Please input multiplicand: ";
	multiplicand = getShort();
	cout << endl << endl;

	cout << "Please input multiplier: ";
	multiplier = getShort();
	cout << endl << endl;

	// Tries multiplication
	try {
		auto result = multiply(multiplicand, multiplier);
		cout << multiplicand << " * " << multiplier << " = " << result << endl << endl;
	}

	// Catches an underflow or overflow error
	catch (overflow_error & e) {
		cout << "do_multiplication function: " << e.what() << endl;
	}
	catch (underflow_error & e) {
		cout << "do_multiplication function: " << e.what() << endl;
	}
}

int main()
{
	cout << "Exceptions Tests!" << endl << endl;

	// Tries to perform functions and catches any exceptions or errors
	// Starting with division function
	try {
		do_division();
	}
	catch (runtime_error & e) {
		cout << "main function: " << e.what() << endl;
	}

	// Trying multiplication through function with catches for errors
	try {
		do_multiplication();
	}
	catch (overflow_error & e) {
		cout << "main function: " << e.what() << endl;
	}

	// Trying application logic trhough function with catches for errors
	try {
		do_custom_application_logic();
	}
	catch (overflow_error & e) {
		cout << "main function: " << e.what() << endl;
	}
	catch (exception & e) {
		cout << "main function: " << e.what() << endl;
	}
}
