// Justin.Starr_CS-405_Buffer-Overflow-Coding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  varaible, and its position in the declaration. It must always be directly before the variable used for input.

	const std::string account_number = "CharlieBrown42";
	char user_input[20];

	// used to detect if an overflow will occur
	std::string test_input;

	// used for tracking the number of attemps to avoid a continuous loop, particuarly in the case of running 
	// a script with the program in a shell and an exploit is attempted
	int max_num_attempts = 3;
	int current_attempt = 0;

	// get input from the user
	std::cout << "Enter a value: ";
	std::cin >> test_input;
	
	// detect if the user input will casue a buffer overflow and if so, continue getting a new value from the user
	while ((test_input.length() >= sizeof(user_input)) && current_attempt < max_num_attempts) {
		
		// display overflow message and allow them to try to enter a new value
		std::cout << std::endl << "!!! WARNING !!! " << std::endl << "Buffer Overflow Detected." << std::endl << std::endl; 

		// increase the users number of attempts
		current_attempt++;

		// check to see if user has reached the number of attempts limit
		if (current_attempt == max_num_attempts) {
			// display message to the user and terminate program execution
			std::cout << "You have reached the maximum number of attempts." << std::endl << std::endl;
			std::cout << "The program will now exit." << std::endl;
			exit(1);
		}

		// this code is reached if the user has not reached their maximum number of attempts
		std::cout << "Please enter a valid value (less than 20 chars)" << std::endl;
		std::cout << "Enter a value: ";
		std::cin >> test_input;
	}

	// this portion of code is not reached until the user input has been validated and their input will not cause a buffer overflow

	// copies the accepted input to the user_input array
	strcpy_s(user_input, test_input.c_str());

	// display the user's input
	std::cout << "You entered: " << user_input << std::endl;

	// display the account number to show it has not been modified
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
