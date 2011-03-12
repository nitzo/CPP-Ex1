#include <iostream>
#include "intArray_t.h"

using namespace std;

int main(int argsc, int** argv) {
	intArray_t arr;

	while (1) {
		cout << "\n| n | fst | lst | ins | rmv | RmvAll |A|P| < | F | : ";

		char c;
		int *e;
		int i;
		cin >> c;

		if (c != 'n' && c != 'f' && c != 'l' && c != 'e' && c != 'i' && c
				!= 'r' && c != 'R' && c != '<' && c != 'A' && c != 'P' && c != 'F')
			break;

		switch (c) {
		case 'n':
			cout << arr.getSize() << endl;
			break;
		case 'f':
			cout << *arr.getFirst() << endl;
			break;
		case 'l':
			cout << *arr.getLast() << endl;
			break;

		case 'i':
			e = new int;
			cout << "Input element value :";
			cin >> *e;

			arr.insert(e);
			break;
		case 'r': // remove
			break;
		case 'R': // remove all
			break;
		case 'A': // append
			e = new int;
			cout << "Tnput element value :";
			cin >> *e;

			cout << "Input index: ";
			cin >> i;
			arr.append(i, e);

			break;
		case 'P': // prepend

			e = new int;
			cout << "Tnput element value :";
			cin >> *e;

			cout << "Input index: ";
			cin >> i;
			arr.prepend(i, e);
			break;

		case 'F': //find

			cout << "Input element to find: ";
			cin >> i;

			e = arr.find(i);

			if (e != 0)
				cout << *e;
			else
				cout << "Element not found\n";

			break;
		case '<': // print array
			cout << arr;
			break;
		}
	}

	return 0;

}

