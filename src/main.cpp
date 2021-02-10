/*
 * ============================================================================
 * Name			: Module.cpp
 * Author		: Joshua Hampton
 * Date			: 2/6/21
 * Description	: Module 5 Project Two: Airgead Banking
============================================================================
*/

//declares files and libraries to use functions from
#include <iostream>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "InvestmentCalc.h"
#include "Functions.h"

//declares namespace std to avoid calling it for each use of namespace functions
using namespace std;

int main() {
	start:																							//entry point to restart program
	//declare and initialize variables
	char userInput = 'y';
	double tmpVal;
	int numberOfYears;
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	string null;
	vector<double> dblVector(4);

	//Print beginning menu
	PrintInitialMenu();

	//waiting for user to hit enter and assigns to userInput if a key is entered
	getline(cin, null);
	if (null.size() > 0){
		userInput = null.at(0);
	}
	//while loop to make sure all variables are entered
	while (!dblVector.at(0) || !dblVector.at(1) || !dblVector.at(2) || !dblVector.at(3)) {
		//exception block to catch an invalid character, if numbers are not entered
		try {
			dblVector = GetBeginingInvestment();													//save investment information to dblVactor
		}
		//catch block to ensure vector is accessed within designed range
		catch (out_of_range& excpt) {
			cout << excpt.what() << endl;
			cout << "Please enter a valid amount." << endl;
		}
		//catch block to ensure numbers are entered for Investment variables
		catch (invalid_argument& excpt) {
			cout << excpt.what() << " error." << endl;
			cout << "Please enter a valid amount." << endl;
		}
	}

	//saves vector entries to individual variables
	initialInvestment = dblVector.at(0);
	monthlyDeposit = dblVector.at(1);
	annualInterest = dblVector.at(2);
	numberOfYears = dblVector.at(3);

	//declares investment objects and sets values, then prints entries for review and waits for user input
	InvestmentCalc investment(initialInvestment, numberOfYears, monthlyDeposit, annualInterest);
	cout << string(100, '\n');																				//clears screen
	PrintInputMenu(investment);
	//waiting for user to hit enter and assigns to userInput if a key is entered
	getline(cin, null);
	if (null.size() > 0){
		userInput = null.at(0);
	}

	//prints chart with calculated investment entries and waits for user input
	cout << string(100, '\n');																				//clears screen
	investment.PrintInterestChart();
	//waiting for user to hit enter and assigns to userInput if a key is entered
	getline(cin, null);
	if (null.size() > 0){
		userInput = null.at(0);
	}

	//while loop for making changes to investment
	while (userInput != 'q' || userInput != 7) {
		cout << userInput;
		cout << string(100, '\n');																				//clears screen

		//prints options menu
		PrintCalcMenu();
		//exception block to catch invalid entries like characters instead of numbers
		try {
			cin >> userInput;
			if (isdigit(static_cast<int>(userInput))) {
				//switch statement changes the investment options
				switch (userInput) {
					case '1':
						//prompts for user to input value to change investment amount
						cout << "Please Enter Initial Investment Amount: ";
						cin >> tmpVal;
						investment.SetInitialInvestment(tmpVal);
						break;
					case '2':
						//prompts for user to input value to change monthly deposit amount
						cout << "Please Enter Monthly Deposit Amount: ";
						cin >> tmpVal;
						investment.SetMonthlyDeposit(tmpVal);
						break;
					case '3':
						//prompts for user to input value to change annual interest
						cout << "Please Enter Annual Interest Amount: ";
						cin >> tmpVal;
						investment.SetAnualInterest(tmpVal);
						break;
					case '4':
						//prompts for user to input value to change number of years
						cout << "Please Enter Number of years: ";
						cin >> tmpVal;
						investment.SetNumberOfYears(tmpVal);
						break;
					case '5':
						//prints investment chart with new calculations
						cout << string(100, '\n');								//clears screen
						PrintInputMenu(investment);
						investment.PrintInterestChart();
						getline(cin, null);										//removes whitespace
						getline(cin, null);										//waits for user to press enter
						if (null.size() > 0){
							userInput = null.at(0);
						}
						break;
					case '6':
						//restarts program
						goto start;
						break;
					case '7':
						//quits program
						userInput = 'q';
						break;
					default:
						cout << "Invalid Selection. Please try again.";
						break;
				}
			}
			else {
				//defines error to be thrown if an invalid character is entered
				throw runtime_error("Invalid Entry.");
			}
		}
		//catch block to catch runtime exception if number is not entered
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Please enter a valid number 1-6 or a valid amount." << endl;
		}
	}
	return 0;
}
