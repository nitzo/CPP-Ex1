#ifndef _intArray_t_h
#define _intArray_t_h

#include <iostream>

using namespace std;

#define XPAND_VALUE 16

class intArray_t {



public:



		intArray_t();				//Default CTOR
		intArray_t(int size);		//Create an array with size i
		~intArray_t();				//Default DTOR



		friend ostream& operator<<(ostream &os, intArray_t& a); //Print Array Details



		int getSize() const;					//Get size of array
		int getCapacity() const;				//Get capacity of array
		void insert(int* e);					//Insert element e at end of array
		int* getFirst() const;					//Return first element e or 0 if fail (size == 0)
		int* getLast() const;					//Return last element e or 0 if fail (size == 0)
		int* find(int v);						//Return 0 if not found
		int* remove(int v);						//Remove ****first occurrence**** of v. Return 0 if fail element e otherwise
		void removeAll();						//Remove all elements
		void removeAndDelete(int v);			//Remove and Free ****all occurrences**** of v.
		void removeAndDeleteAll();				//Remove and Free Array.
		int append(int i, int* e);				//Insert Element e after element in index i. Return 0 on fail 1 otherwise
		int prepend(int i, int* e); 			//Insert Element e before element in index i. Return 0 on fail 1 otherwise

private:


		int capacity;
		int xpand_value;
		int size;


		int **arr;

		int shiftLeft(int i);
		int shiftRight(int i);
		int xpand();
		void initializeMembers(int initialCapacity);
		int findIndex(int startIndex, int value);
		int* intArray_t::remove_p(int value);
		int intArray_t::insert_p(int i, int* newElement);

		//Prevent copy
		const intArray_t& operator=(const intArray_t&); //Note: Not Implemented
		intArray_t(intArray_t& a);						//Note: Not Implemented

};

#endif
