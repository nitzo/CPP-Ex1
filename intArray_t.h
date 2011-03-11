#ifndef _intArray_t_h
#define _intArray_t_h

#define XPAND_VALUE 16

class intArray_t {



public:

		intArray_t();				//Default CTOR
		intArray_t(intArray_t& a);	//Copy CTOR
		intArray_t(int size);		//Create an array with size i
		~intArray_t();				//Default DTOR


		const intArray_t& operator=(const intArray_t&); //TODO: Should we implement?

		int getSize();				//Get size of array
		int getCapacity();			//Get capacity of array
		void insert(int* e);		//Insert element e at end of array
		int* getFirst();			//Return first element e or 0 if fail (size == 0)
		int* getLast();				//Return last element e or 0 if fail (size == 0)
		int* find(int v);			//Return 0 if not found
		int* remove(int v);			//Remove ****first occurrence**** of v. Return 0 if fail element e otherwise
		void removeAll();			//Remove all elements
		void removeAndDelete(int v);//Remove and Free ****all occurrences**** of v.
		int removeAndDeleteAll();	//Remove and Free Array.
		int append(int i, int* e);	//Insert Element e after element in index i. Return 0 on fail 1 otherwise
		int prepend(int i, int* e); //Insert Element e before element in index i. Return 0 on fail 1 otherwise

private:

	//TODO: Move private members to cpp file??
	int capacity;
	int xpand_value;
	int size;


	int **arr;

	int shiftLeft(int i);
	int shiftRight(int i);
	int xpand();
	//int *find_p(int i, int v); //TODO: Remove
	void initializeMembers(int initialCapacity);
	int findIndex(int startIndex, int value);
	int* intArray_t::remove_p(int value);
	int intArray_t::insert_p(int i, int* newElement);





};


#endif
