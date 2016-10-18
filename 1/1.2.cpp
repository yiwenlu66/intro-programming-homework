#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

int main() {
	double radius, height, volume;
	const double pi = acos(-1.0);
	cout << "Please input radius:" << endl;
	cin >> radius;
	cout << "Please input height:" << endl;
	cin >> height;
	volume = pi * radius * radius * height;
	cout << "The volume is " << volume << "." << endl;
	getche();
	return 0;
}