#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <cmath>
#include <iomanip>

/*This file is used to define the classes that will be used in main.cpp and tools.cpp. This helps the program
maintain cleanliness, and makes it more readable. The program originally didn't need it, however this makes the program
more efficient than before.*/

//This class get the user input that will then get the values which will be used by RetirementCalculator
class UserInput
{
    public:
        void getUserInput(double &annualContribution, double &interestRate, int &yearsToRetirement, int &yearsDuringRetirement);
double calculateFutureValue(double annualContribution, double interestRate, int yearsToRetirement);


};
/*This holds all the functions from the previous code, in which it helps make the code cleaner, and efficient.
Additionally,*/
class RetirementCalculator
{
    public:
    double calculateFutureValue(double annualContribution, double interestRate, int yearsToRetirement);
    double calculateMonthlyRate(double futureValue, int yearsDuringRetirement);
    void displayResults(double futureValue, double monthlyRate);
    void testApplication();
    
    
};

#endif