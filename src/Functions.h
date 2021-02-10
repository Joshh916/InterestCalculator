/*
 * Header File to declare variables and methods for Functionss.cpp
 * By Joshua Hampton
 * Date: 2/7/21
 */

//ifndef defines safeguards to prevent libraries files from being imported multiple times
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//declares files and libraries to use functions from
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "InvestmentCalc.h"

//declares namespace std to avoid calling it for each use of namespace functions
using namespace std;

void PrintCalcMenu();

void PrintInitialMenu();

void PrintInputMenu(InvestmentCalc t_investment);

void CalculateInterest(double t_depositedAmt, double t_openAmt, double t_interestRate, double& t_yearEndBal, double& t_earnedInterest);

vector<double> GetBeginingInvestment();

#endif
