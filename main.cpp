#include <iostream>
#include "Labs/Labs.h"
using namespace std;

int main() {
	int choice;
	do {
		cout << "\n===== CEN203 Data structures La =====" << endl;
		cout << " 2. Week 2 - Projectstructure test" << endl;
		cout << " 3. Week 3 - Linked List" << endl;
		cout << " 0.Exit" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 2: runWeek02(); break;
		case 3: runWeek03(); break;

		case 0: cout << "Bye!" << endl; break;
		default: cout << "Invalid choice!" << endl;
		}

	} while (choice != 0);

	return 0;
}