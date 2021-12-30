#include <iostream>
#include <cstdlib>
using namespace std;

double getBase (double carValue, double& premium);
double accidentAdjust (double accidents, double& premium);
double getRiskSurcharge (double& premium, char riskSurcharge);

int main()
{
	double carValue, premium=0;
	double accidents;
	char riskSurcharge;
	
	cout << "GoldOak Insurance Agency" << endl;
	cout << "Automotive Policy Six-Month premium Calculator" << endl << endl;
	
	cout << "Enter the value of the car to be insured:  kshs";
	cin >> carValue;
	if (carValue<0)
	{
		cout<<"You have entered an invalid number. The program will now terminate." <<endl;
		exit(1);   
	}
	
	else getBase(carValue, premium);

	cout << "How many accidents has the policyholder caused in the last three years? ";
	cin >> accidents;
	if (accidents<0)
	{
		cout<<"You have entered an invalid number. The program will now terminate." <<endl;
		exit(1);   
	}

	else accidentAdjust(accidents, premium);
	
	cout << "Enter the geographical risk factor (Class a - e): ";
	cin >> riskSurcharge;
	
	getRiskSurcharge(premium, riskSurcharge);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "The premium for this policyholder will be kshs" << premium << endl << endl;
	
	cout << "Insure to be Sure" << endl;
	
	return 0;
}

double getBase(double carValue, double& premium)
{
	premium = carValue / 20;
	return premium;
}

double accidentAdjust(double accidents, double& premium)
{
	if (accidents<2)
		premium=premium;
	if (accidents>1 && accidents<=3)
		premium=premium*(accidents*.01)+premium;
	if (accidents>3 && accidents<=6)
		premium=premium*(accidents*.03)+premium;
	if (accidents>6)
	{
		cout<<"We will not be able to insure your vehicle."<<endl;
		exit(1);   
	}
	
	return premium;
}

double getRiskSurcharge(double& premium, char riskSurcharge)
{
	switch (riskSurcharge) 
	{
	case 'A':
	case 'a':
		premium=premium+20;
		break;
	case 'B':
	case 'b':
		premium=premium+30;
		break;
	case 'C':
	case 'c':
		premium=premium+50;
		break;
	case 'D':
	case 'd':
		premium=premium+100;
		break;
	case 'E':
	case 'e':
		premium=premium+250;
		break;
	default:
		cout<<"You have entered an invalid number. The program will now terminate."<<endl;
		exit(1);
	}

		return premium;
}