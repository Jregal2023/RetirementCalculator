#include <iostream>
#include <cmath> // For pow function
#include <iomanip> // For formatting output
#include "tools.h"

using namespace std;
/*Using tools.h, tools.cpp defines the functions within tools.h. 
Thankfully we already have the functions pre-defined, due to the original code.
The only difference is that it now derives off of classes, and not the main function.

*/
// Define UserInput class member function
void UserInput::getUserInput(double &annualContribution, double &interestRate, int &yearsToRetirement, int &yearsDuringRetirement) {
    cout << "Enter annual contribution amount (in dollars): ";
    cin >> annualContribution;

    cout << "Enter expected annual interest rate (as a percentage): ";
    cin >> interestRate;
    interestRate /= 100.0; // Convert percentage to decimal

    cout << "Enter number of years until retirement: ";
    cin >> yearsToRetirement;

    cout << "Enter number of years during retirement: ";
    cin >> yearsDuringRetirement;
}

// Calculates the future value of your input 
double RetirementCalculator::calculateFutureValue(double annualContribution, double interestRate, int yearsToRetirement) {
    if (interestRate == 0) {
        return annualContribution * yearsToRetirement;
    }
    return annualContribution * (pow(1 + interestRate, yearsToRetirement) - 1) / interestRate;
}
// Calculates the monthly rate using futureValue, and yearsDuringRetirement
double RetirementCalculator::calculateMonthlyRate(double futureValue, int yearsDuringRetirement) {
    if (yearsDuringRetirement == 0) {
        return 0.0; // Avoid division by zero
    }
    return futureValue / (yearsDuringRetirement * 12);
}
//displays the results of the future value.
void RetirementCalculator::displayResults(double futureValue, double monthlyRate) {
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "\n=== Retirement Income Summary ===\n";
    cout << "Future value of the fund: $" << futureValue << "\n";
    cout << "Monthly withdrawal amount during retirement: $" << monthlyRate << "\n";
    cout << "==================================\n";
}
/*This function was used to test the program and display results.
Although it is useful, it has no genuine purpose but to display that the functions work.*/
void RetirementCalculator::testApplication() {
    double annualContributionArray[3] = {5000.0, 0.0, 10000.0};
    double interestRateArray[3] = {5.0 / 100.0, 4.0 / 100.0, 0.0};
    int yearsToRetirementArray[3] = {30, 25, 20};
    int yearsDuringRetirementArray[3] = {20, 15, 10};

    for (int i = 0; i < 3; ++i) {
        double futureValue = calculateFutureValue(annualContributionArray[i], interestRateArray[i], yearsToRetirementArray[i]);
        double monthlyRate = calculateMonthlyRate(futureValue, yearsDuringRetirementArray[i]);
        cout << "Test Case " << i + 1 << ": Future Value = $" << futureValue << ", Monthly Rate = $" << monthlyRate << "\n";
    }
}
