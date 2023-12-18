// Uses classes to create a collection
// Kaila Anderson
// November 15, 2022

#include <iostream>
#include "collection.hpp"

using std::cin; using std::cout; using std::endl; 

int main() {
	Collection myCollection; 
	double sumOfArray;
	char choice;


	cout << "Hello! Let's start your collection!" << endl;

	do {
		cout << "Would You Like To Add(a) or Remove(r) from your collection? (q to Quit): " << endl;
		cin >> choice;
		if (choice != 'q' || choice != 'Q') {
			switch (choice) {
			case 'a':
				cout << "What number would you like to add?" << endl;
				double add;
				cin >> add;
				if (myCollection.check(add) != -1)
					cout << "that number is already in your collection." << endl;
				else myCollection.addNumber(add);
				break;
			case 'r':
				cout << "What number would you like to remove?" << endl;
				double remove;
				cin >> remove;
				if (myCollection.check(remove) == -1)
					cout << "That number is not in your collection." << endl;
				else myCollection.removeNumber(remove);
				break;
			}
			sumOfArray = myCollection.value();
			cout << "Your collection: ";
			myCollection.output(); cout << endl; 
			cout << "Total Value: " << sumOfArray << endl;
		}
	} while (choice != 'q');

}