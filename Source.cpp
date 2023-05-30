#include <iostream>
#include <iomanip>

using namespace std;

// Note: when you do not explicitly assign values to the constants, the enum values are assigned sequential 
//		 integral values starting from 0.
enum MenuOption { OPTION_1 = 1, OPTION_2, EXIT };

void Menu(MenuOption& choice);
double Series_1(int n, int count);
double Series_2(int n, int count);

int main() {

	MenuOption choice;
	double val{ 0 };
	int n;

	do {
		Menu(choice);
		switch (choice) {
			case OPTION_1:
				cout << "Enter a value for n: ";
				cin >> n;
				cout << Series_1(n, n) << endl;
				break;
			case OPTION_2:
				cout << "Enter a value for n: ";
				cin >> n;
				cout << Series_2(n, n) << endl;
				break;
			case EXIT:
				//exit
				break;
			default:
				cout << "Error updating choice value\n";
				cout << "Terminating Program\n";
				exit(0);
		}
		cout << endl;
	} while (choice != EXIT);

	return 0;
}

void Menu(MenuOption& choice) {
	int input{ 0 };

	cout << "Menu:\n";
	cout << "1. Series 1: 1/(0+1)+1/(1+2)+...+1/((n-1)+n)\n";
	cout << "2. Series 2: (n*n)+((n-1)*(n-1))+...+(2*2)+(1*1)\n";
	cout << "3. Exit\n";
	cout << "Enter your choice: ";
	cin >> input;
	// Convert user input to MenuOption enum
	choice = static_cast<MenuOption>(input);
}

//		Recall that the purpose of a recursive function is that it calls itself directly
// or indirectly to solve a problem by breaking it down into smaller subproblems.
//		The idea is that with each recursive call, the function solves a smaller instance
// of the problem until it reaches a base case, which is a simple case that can be
// solved directly without further recursion.

double Series_1(int n, int count) {
	double val{ 0 };

	// Output Formatting
	cout << fixed << showpoint << setprecision(4);

	// Base case:
	if (n == 1) {
		return 1;
	}
	// Recursive case:
	else {
		// Show intermediate steps?
		if (count == n) {
			cout << "1 + ";
			for (int i{ 1 }; i < n - 1; i++) {
				cout << "1/(" << i << "+" << i + 1 << ") + ";
			}
			cout << "1/(" << count - 1 << "+" << count << ") = ";
		}
		val = (1.0 / ((n - 1) + n) + Series_1(n - 1, count));
		return val;
	}
}

double Series_2(int n, int count) {
	// Base case:
	if (n <= 1) {
		return 1;
	}
	// Recursive case:
	else {
		// Print intermediate steps
		if (n == count) {
			for (int i = count; i > 1; i--) {
				cout << "(" << i << "*" << i << ") + ";
			}
			cout << "(1*1) = ";
		}
		return (n * n) + Series_2(n - 1, count);
	}
}
