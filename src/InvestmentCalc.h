/*
 * Header File to declare variables and methods for InvestmentCalc.cpp
 * By Joshua Hampton
 * Date: 2/7/21
 */

//ifndef defines safeguards to prevent libraries files from being imported multiple times
#ifndef INVESTMENTCALC_H
#define INVESTMENTCALC_H

//declares files and libraries to use functions from
#include <iostream>
#include <string>

//declares namespace std to avoid calling it for each use of namespace functions
using namespace std;

class InvestmentCalc {

public:
	//defines public methods to be used
	InvestmentCalc();
	InvestmentCalc(double m_initialInvestment, int m_numberOfYears, double m_monthlyDeposit, double m_annualInterest);
	void PrintInterestChart();
	double GetInitialInvestment();
	void SetInitialInvestment(double m_initialInvestment);
	double GetNumberOfYears();
	void SetNumberOfYears(int m_numberOfYears);
	double GetMonthlyDeposit();
	void SetMonthlyDeposit(double m_monthlyDeposit);
	double GetAnualInterest();
	void SetAnualInterest(double m_annualInterest);

private:
	//defines private variables
	double initialInvestment;
	int numberOfYears;
	double monthlyDeposit;
	double annualInterest;
};


#endif
