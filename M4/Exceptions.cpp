// Justin.Starr_CS-405_Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    // throw any standard exception. I chose to throw a runtime_error exception
    throw std::exception("Standard exception thrown");

    // this portion of code will not be reached because an exception is thrown
    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl << std::endl;;

    // try/block implemented to handle std::exceptions
    // will try what is in the try block first and if any errors are thrown
    try {
        if (do_even_more_custom_application_logic())
        {
            // this portion of code is never reached because true is never returned
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    // catch to handle any errors that are caught during the try part of the block
    // will handle the exception thrown from do_more_application_logic() function
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl << std::endl;
    }


    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main

    // throws a custome exception that will be handled by the main function
    throw std::runtime_error("Custom exception thrown and caught by main function.");

    // this code is not reachable becasue an exception has been thrown
    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception

    // we know we cannot divide by zero. Therefore, the only number we need to check here is the denominator.
    // if denominator is equal to zero, throw an exception.
    if (den == 0) {
        throw std::invalid_argument("Cannot Divide by Zero.");
    }
    // this portion of code is only reached if the denominator is not equal to zero
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    // try/catch blcok implemented to catch any errrors that may be thrown from the divide() function.
    try {
        float numerator = 10.0f;
        float denominator = 0;

        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    // catches any errors thrown by divide() function and displays the error to the user
    catch (std::invalid_argument& e) {
        std::cout << e.what() << std::endl << std::endl;
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

    // try/catch block to wrap the main function
    try {
        do_division();
        do_custom_application_logic();
    }
    // catches the runtime error thrown by do_custom_application_logic() and displays the error message to the user.
    catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

