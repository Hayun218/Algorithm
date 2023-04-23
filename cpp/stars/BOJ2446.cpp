#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;

	for (int j = num; j > 1; j--) {
		for (int k = j; k < num; k++)
			cout << " ";
		for (int i = j * 2 - 1; i > 0; i--)
			cout << "*";
		cout << "\n";
	}

	for (int j = 1; j < num + 1; j++) {
		for (int k = j; k < num; k++)
			cout << " ";
		for (int i = 1; i < j * 2; i++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}