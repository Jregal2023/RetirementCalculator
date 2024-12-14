#include <iostream>
#include <cmath> // For pow function
#include <iomanip> // For formatting output
#include "tools.h"


using namespace std;
// Function prototypes
/* removed and sent to tools.cpp*/
/*The main function is meant to bring it all together. From the beginnign it welcomes
its users and ask the for inputs use fucntions that have been defined int tools.cpp
Making the code more readable*/
// Main function
int main() {
    // Variables to hold user inputs
    double annualContribution = 0.0;
    double interestRate = 0.0;
    int yearsToRetirement = 0;
    int yearsDuringRetirement = 0;

    // Welcome message
    cout << "Welcome to the Retirement Income Calculator!\n";
    
    
    
    UserInput userInput;
    RetirementCalculator retireCalc;


    // Get user input
    userInput.getUserInput(annualContribution, interestRate, yearsToRetirement, yearsDuringRetirement);

    // Calculate future value of the fund
    double futureValue = retireCalc.calculateFutureValue(annualContribution, interestRate, yearsToRetirement);

    // Calculate monthly withdrawal rate
    double monthlyRate = retireCalc.calculateMonthlyRate(futureValue, yearsDuringRetirement);

    // Display the results
    retireCalc.displayResults(futureValue, monthlyRate);

    // Optional: Test application with sample inputs
    cout << "\nRunning automated tests...\n";
    retireCalc.testApplication();

    return 0;
}