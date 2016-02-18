#include <iostream>
#include <string>
#include <random>
#include <functional>
#include <chrono>
#include <sstream>

using namespace std;

const char* ALLOWABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!$%^&*()[]{}@~#<>,.? ";
const int MAX = 80;

int main()
{
	
	int numPasswords;
	int length;
	string generate(const int, default_random_engine&, uniform_int_distribution<int>&);

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> dist(0, MAX);

	cout << "How many passwords would you like to generate?\n";
	cin >> numPasswords;

	cout << "How long should they be?\n";
	cin >> length;

	for (int i = 0; i < numPasswords; i++) 
		cout << "Password " << i + 1 << ": " << generate(length, generator, dist) << endl;
}

string generate(const int length,
	default_random_engine& generator,
	uniform_int_distribution<int>& dist)
{
	ostringstream password;
	for (int i = 0; i < length; i++) 
		password << ALLOWABLE[dist(generator)];

	return password.str();
}