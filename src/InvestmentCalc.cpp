/*
 * Class File to define variables and methods for InvestmentCalc
 * By Joshua Hampton
 * Date: 2/7/21
 */

//declares files and libraries to use functions from
#include <iostream>
#include <string>
#include <iomanip>
#include "InvestmentCalc.h"
#include "Functions.h"

//declares namespace std to avoid calling it for each use of namespace functions
using namespace std;

InvestmentCalc::InvestmentCalc(){
	//default constructor sets all variables to 0
	this->initialInvestment = 0;
	this->numberOfYears = 0;
	this->monthlyDeposit = 0;
	this->annualInterest = 0;
}
InvestmentCalc::InvestmentCalc(double m_initialInvestment, int m_numberOfYears, double m_monthlyDeposit, double m_annualInterest) {
	//overloaded constructor sets variables to provided variables
	this->initialInvestment = m_initialInvestment;
	this->numberOfYears = m_numberOfYears;
	this->monthlyDeposit = m_monthlyDeposit;
	this->annualInterest = m_annualInterest;
}
void InvestmentCalc::PrintInterestChart() {
	//prints formatted interest sheets with and without monthly deposits
	double yearEndBal = 0;
	double earnedInterest = 0;
	double openAmt = initialInvestment;

	cout << string(100, '\n');
	cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setw(64) << setfill('=') << "=" << endl;
	cout << "  Year       Year End Balance       Year End Earned Interest" << endl;
	cout << setw(64) << setfill('-') << "-" << endl;
	for (int i = 0; i < numberOfYears; ++i) {
		CalculateInterest(openAmt, 0, annualInterest, yearEndBal, earnedInterest);
		openAmt = yearEndBal;
		cout << "    " << i + 1 << fixed << setprecision(2) << setw(23) << setfill(' ') << "$" << yearEndBal << setw(31) << setfill(' ') << earnedInterest << endl << endl;
		earnedInterest = 0;
	}
	yearEndBal = 0;
	earnedInterest = 0;
	openAmt = initialInvestment;
	cout << "\n    Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setw(64) << setfill('=') << "=" << endl;
	cout << "  Year       Year End Balance       Year End Earned Interest" << endl;
	cout << setw(64) << setfill('-') << "-" << endl;
	for (int i = 0; i < numberOfYears; ++i) {
			CalculateInterest(openAmt, monthlyDeposit, annualInterest, yearEndBal, earnedInterest);
			openAmt = yearEndBal;
			cout << "    " << i + 1 << fixed << setprecision(2) << setw(23) << setfill(' ') << "$" << yearEndBal << setw(31) << setfill(' ') << earnedInterest << endl << endl;
			earnedInterest = 0;
		}
	cout << "Press enter key to continue . . ." << endl;
}
double InvestmentCalc::GetInitialInvestment() {
	//Getter method to return investment amount
	return this->initialInvestment;
}
void InvestmentCalc::SetInitialInvestment(double m_initialInvestment) {
	//setter method to set initial investment amount
	this->initialInvestment = m_initialInvestment;
}
double InvestmentCalc::GetNumberOfYears() {
	//Getter method to return number of years for investment
	return this->numberOfYears;
}
void InvestmentCalc::SetNumberOfYears(int m_numberOfYears) {
	//Setter method to set number of years for investment
	this->numberOfYears = m_numberOfYears;
}
double InvestmentCalc::GetMonthlyDeposit() {
	//Getter method to return monthly deposit amount
	return this->monthlyDeposit;
}
void InvestmentCalc::SetMonthlyDeposit(double m_monthlyDeposit) {
	//Setter method to set monthly deposit amount
	this->monthlyDeposit = m_monthlyDeposit;
}
double InvestmentCalc::GetAnualInterest() {
	//Getter method to return annual interest
	return this->annualInterest;
}
void InvestmentCalc::SetAnualInterest(double m_annualInterest){
	//Setter method to set annual interest
	this->annualInterest = m_annualInterest;
}
