// August 5, 2019
// Purpose: This program gives the user what type of number are inside a file.
// input:
// Output: Prime number, perfect number, triangular number, mersenne prime number, and the sum from 1 to the determined number.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

bool prime(int);
bool perfectNum(int);
bool triangularNum(int);
bool mersennePnum(int);
int sum(int);

int main()
{
	ifstream inputFile;
	ofstream outputFile;

	int num = 1;
	
	inputFile.open("numbers.txt");
	outputFile.open("outputFile.txt");

	while (!inputFile.eof()) {

		inputFile >> num;

		prime(num) ? outputFile << num << " This is a prime number \n" :
					 outputFile << num << " This is not a prime number\n";
		
		perfectNum(num) ? outputFile << "This is a perfect number\n" :
						  outputFile << "This is not a perfect number\n";
		
		triangularNum(num) ? outputFile << "This is a triangular number\n" :
							 outputFile << "This is not a triangular number\n";
		
		mersennePnum(num) ? outputFile << "This is a mersenne prime number\n" :
							outputFile << "This is not a mersenne prime number\n";
	
		outputFile << "The sum of all the numbers between 1 and " << num << " is: " << sum(num) << endl;
		outputFile << "\n";
	}
	inputFile.close();
	outputFile.close();

	return 0;
}
bool prime(int x)
{
	if (x <= 1)
		return false;

	for (int i = 2; i < x; i++)
		if (x % i == 0)

			return false;

	return true;
}
bool perfectNum(int x)
{
	int sum = 1;

	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			if (i * i != x)
				sum += i + x / i;
			else
				sum += +i;
		}
	}
	if (sum == x && x != 1)
		return true;

	return false;
}
bool triangularNum(int x)
{
	int sum = 0;

	if (x < 0)
		return false;

	for (int i = 1; sum <= x; i++)
	{
		sum += i;
		if (sum == x)
			return true;
	}
	return false;
}
bool mersennePnum(int x)
{
	int i = 2;

	while (pow(2, i) < x) i++;

	if ((int)(pow(2, i) - 1) == x)

		return true;
}
int sum(int x)
{
	if (x == 1)
		return 1;

	else return x + sum(x - 1);
}
