#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class	AdvancedArithmetic
{
	public:
		virtual int divisorSum(int n) = 0;
};

class	Calculator : public AdvancedArithmetic
{
	public:
		int divisorSum(int n)
		{
			int	divisor;
			int	res;

			res = 0;
			divisor = 1;
			while (divisor <= n)
			{
				if (n % divisor == 0)
					res += divisor;
				divisor++;
			}
			return res;
		}
};

int	main(void)
{
	int	n;
	cout << "Enter integer to calculate sum of its divisors: ";
	cin >> n;
	AdvancedArithmetic *myCalculator = new Calculator();
	int	sum = myCalculator->divisorSum(n);
	cout << "The sum of all divisors of " << n << " is: " << sum;
	return 0;
}
