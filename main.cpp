#include <iostream>
#include "intArray_t.h"

using namespace std;

int main(int argsc, int** argv) {
	intArray_t arr;

	//TODO: Go Over and fix if needed!


	while (1) {
		cout << "\n| n | fst | lst | ins | rmv | RmvAll | delete | DeleteAll |A|P| < | F | : ";

		char c;
		int *e;
		int i;
		cin >> c;

		if (c != 'n' && c != 'f' && c != 'l' && c != 'e' && c != 'i' && c
				!= 'r' && c != 'R' && c != '<' && c != 'A' && c != 'P' && c != 'F' && c != 'd' && c != 'D')
			break;

		switch (c) {
		case 'n':
			cout << arr.getSize() << endl;
			break;
		case 'f':

			e = arr.getFirst();
			if (e != 0)
				cout << *e << endl;
			else
				cout << "Array Empty!";
			break;
		case 'l':
			e = arr.getLast();
			if (e != 0)
				cout << *e << endl;
			else
				cout << "Array Empty!";
			break;
		case 'd': //Remove and delete

			cout << "Input value of elements to delete :";
			cin >> i;

			arr.removeAndDelete(i);

			break;
		case 'D': //remove and delete all
			cout << "Deleting whole array";

			arr.removeAndDeleteAll();
			break;

		case 'i':
			e = new int;
			cout << "Input element value :";
			cin >> *e;

			arr.insert(e);
			break;
		case 'r': // remove

			cout << "Input element value to remove :";
			cin >> i;

			e = arr.remove(i) ;

			if (e == 0){
				cout << "Element not found!";
			}
			else
				cout << *e << " element removed!";

			delete e;

			break;
		case 'R': // remove all

			cout << "Removing all array";

			arr.removeAll();

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

