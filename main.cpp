#include <iostream>
#include "intArray_t.h"

using namespace std;

int main(int argsc, int** argv){
    intArray_t arr;

    while(1) {
    cout <<
     "\n| n | fst | lst | ins | rmv | RmvAll |A|P| < | : ";

        char c;
        cin >> c;

        if(c!='n' && c!='f' && c!='l' && c!='e' && c!='i'
                  && c!='r' && c!='R' && c!='<'
                  && c!='A' && c!='P' )   break;

        switch (c) {
            case 'n' :  cout << arr.getSize() << endl;
            	break;
            case 'f' :  cout << *arr.getFirst() << endl;
            	break;
            case 'l' :  cout << *arr.getLast() << endl;
            	break;

            case 'i' :  // insert
                        break;
            case 'r' :  // remove
                        break;
            case 'R' :  // remove all
                        break;
            case 'A' :  // append
                        break;
            case 'P' :  // prepend
                        break;
            case '<' :  // print array
                        break;
	}
    }

    return 0;

}

