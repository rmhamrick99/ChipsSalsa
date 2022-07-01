#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Headers

class sold
{
public:

	void mainline(void);
private:

	void findHighest(double dSoldArray[], string sSName[]);
	void findLowest(double dSoldArray[], string sSName[]);
	double getSold(string sSName);
	void initializeSalsa(string sSName[]);
	void showResult(double dSoldArray[], string sSName[]);

	string sSalsa[5];
	double dTotalSold;
	double dNumSold[5];
	double dHoldHighest;
	string sHoldName;
	double dHoldLowest;
	double dSold;
	int iCnt;

};

int main()
{
	sold r1;
	r1.mainline();

}

void sold::mainline()
{
	

	initializeSalsa(sSalsa);
	

	dNumSold[0] = getSold(sSalsa[0]);
	dNumSold[1] = getSold(sSalsa[1]);
	dNumSold[2] = getSold(sSalsa[2]);
	dNumSold[3] = getSold(sSalsa[3]);
	dNumSold[4] = getSold(sSalsa[4]);
	showResult(dNumSold, sSalsa);
	findLowest(dNumSold, sSalsa);
	cout << "The salsa that was sold the least is: " << sSalsa[4] << endl;
	findHighest(dNumSold, sSalsa);
	cout << "The salsa that was sold the most is: " << sSalsa[4] << endl;
	dTotalSold = dNumSold[0] + dNumSold[1] + dNumSold[2] + dNumSold[3] + dNumSold[4];
	cout << "Total salsa sold is: " << dTotalSold << endl;
	system("pause");
	return;
}

void sold::findHighest(double dSoldArray[], string sSName[])
{
	

	for (iCnt = 1; iCnt <= 4; iCnt++)
	{
		if (dSoldArray[iCnt - 1] > dSoldArray[iCnt])
		{
			dHoldHighest = dSoldArray[iCnt - 1];
			dSoldArray[iCnt - 1] = dSoldArray[iCnt];
			dSoldArray[iCnt] = dHoldHighest;
			sHoldName = sSName[iCnt - 1];
			sSName[iCnt - 1] = sSName[iCnt];
			sSName[iCnt] = sHoldName;
		}
	}
}

void sold::findLowest(double dSoldArray[], string sSName[])
{
	

	for (iCnt = 1; iCnt <= 4; iCnt++)
	{
		if (dSoldArray[iCnt - 1] < dSoldArray[iCnt])
		{
			dHoldLowest = dSoldArray[iCnt - 1];
			dSoldArray[iCnt - 1] = dSoldArray[iCnt];
			dSoldArray[iCnt] = dHoldLowest;
			sHoldName = sSName[iCnt - 1];
			sSName[iCnt - 1] = sSName[iCnt];
			sSName[iCnt] = sHoldName;
		}
	}
}

double sold::getSold(string sSName)
{
	

	cout << "For the salsa: " << sSName << endl;
	cout << "Enter amount sold for this salsa." << endl;
	cin >> dSold;

	return dSold;
}

void sold::initializeSalsa(string sSName[])
{
	sSName[0] = "Mild";
	sSName[1] = "Medium";
	sSName[2] = "Sweet";
	sSName[3] = "Hot";
	sSName[4] = "Zesty";
}

void sold::showResult(double dSoldArray[], string sSName[])
{
	

	for (iCnt = 0; iCnt <= 4; iCnt++)
	{
		cout << dSoldArray[iCnt] << "   " << sSName[iCnt] << endl;
	}
}

