#include <iostream>
#include <vector>
#include <string>

using namespace std;
template <typename T> // function template declaration which allows generic usage

void	printArray(vector<T> v) // function template definition
{ // Depending on actual vector passed, the type T is determined
	size_t	i;

	i = 0;
	while (i < v.size())
		cout << v[i++] << endl;
}

int	main(void)
{
	int	n;
	cout << "Enter the number of integers: ";
	cin >> n;
	vector<int>	int_vector(n);
	for (int i = 0; i < n; i++)
	{
		cout << "The " << i + 1 << " integer is: ";
		int	value;
		cin >> value;
		int_vector[i] = value;
	}
	cout << "Enter the number of strings: ";
	cin >> n;
	vector<string>	string_vector(n);
	for (int i = 0; i < n; i++)
	{
		cout << "The " << i + 1 << " string is: ";
		string	value;
		cin >> value;
		string_vector[i] = value;
	}
	printArray<int>(int_vector); // So we specify that T = int
	printArray<string>(string_vector); // Similar, but T = string
	return 0;
}
