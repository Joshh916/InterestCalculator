/*
 * Functions File to define variables and Functions
 * By Joshua Hampton
 * Date: 2/7/21
 */

//declares files and libraries to use functions from
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <windows.h>
#include "Functions.h"
#include "InvestmentCalc.h"

//declares namespace std to avoid calling it for each use of namespace functions
using namespace std;


void PrintInitialMenu() {
	//prints initial menu with no values entered
	cout << setw(32) << setfill('*') << "*" << endl;
	cout << setw(22) << setfill('*') << " Data Input " << setw(10) << setfill('*') << "*" << endl;
	cout << "Initial Investment Amount:" << endl << "Monthly Deposit:" << endl << "Annual Interest:" << endl << "Number of years:" << endl;
	cout << "\nPress enter key to continue . . ." << endl;
	cout << "Enter q to quit . . ." << endl;
}

void PrintCalcMenu() {
	//prints formatted menu to make changes to investments
	cout << "      " << setw(39) << setfill('*') << "*" << endl;
	cout << "      *  1 - Change Initial Investment      *" << endl;
	cout << "      *  2 - Change Monthly Deposit         *" << endl;
	cout << "      *  3 - Change Annual Interest         *" << endl;
	cout << "      *  4 - Change Number of years         *" << endl;
	cout << "      *  5 - Print Interest Calculations    *" << endl;
	cout << "      *  6 - Restart Program                *" << endl;
	cout << "      *  7 - Exit Program                   *" << endl;
	cout << "      " << setw(39) << setfill('*') << "*" << "\n\n\n\n" << endl;
}

void PrintInputMenu(InvestmentCalc t_investment) {
	//prints formatted menu with investment amounts
	cout << setw(32) << setfill('*') << "*" << endl;
	cout << setw(22) << setfill('*') << " Data Input " << setw(10) << setfill('*') << "*" << endl;
	cout << fixed << setprecision(2);
	cout << "Initial Investment Amount: $" << t_investment.GetInitialInvestment() << endl;
	cout << "Monthly Deposit: $" << t_investment.GetMonthlyDeposit() << endl;
	cout << setprecision(0);
	cout << "Annual Interest: " << t_investment.GetAnualInterest() << endl;
	cout<< "Number of years: " << t_investment.GetNumberOfYears() << endl;
	cout << "\nPress enter key to continue . . ." << endl;
}

void CalculateInterest(double t_openAmt, double t_depositedAmt, double t_interestRate, double& t_yearEndBal, double& t_earnedInterest) {
	//calculates interest for a year compounded monthly
	for (int i = 0; i < 12; ++i){
		double tmpVal;
		double tmpInterest;
		tmpInterest = ((t_openAmt + t_depositedAmt) * ((t_interestRate / 100)/12));
		t_earnedInterest += tmpInterest;
		tmpVal = tmpInterest + t_openAmt + t_depositedAmt;
		t_openAmt = tmpVal;
	}
	t_yearEndBal = t_openAmt;
}
vector<double> GetBeginingInvestment() {
	//gets investment amounts from user and return them in a vector
	string tmpStr;
	vector<double> dblVector(4);

	cout << "Please Enter Initial Investment Amount: " << endl;
	cin >> tmpStr;
	dblVector.at(0) = stod(tmpStr);
	cout << "\nPlease Enter Monthly Deposit: " << endl;
	cin >> tmpStr;
	dblVector.at(1) = stod(tmpStr);
	cout << "\nPlease Enter Annual Interest: " << endl;
	cin >> tmpStr;
	dblVector.at(2) = stod(tmpStr);
	cout << "\nPlease Enter Number of years: " << endl;
	cin >> tmpStr;
	dblVector.at(3) = stod(tmpStr);
	if (!dblVector.at(0) || !dblVector.at(1) || !dblVector.at(2) || !dblVector.at(3)){
		throw runtime_error("Invalid Entry.");												//throws runtime error if a number is not entered
	}
	else {
		return dblVector;
	}
}
