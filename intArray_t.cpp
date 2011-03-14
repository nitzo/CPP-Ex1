/*
 * intArray_t.cpp
 * Created on: 07/03/2011
 *
 * Assumption given at course forum:
 * 1. same pointer will not be insert twice
 * 2. avoid handle "new" failures
 */
#include <iostream>
#include "intArray_t.h"

using namespace std;

/**
 * Constructors & Destructor
 */


/*
 * Default Ctor
 */
intArray_t::intArray_t() {
		size = 0;
		initializeMembers(XPAND_VALUE);
}

/*
 * Overload Ctor
 */
intArray_t::intArray_t(int initialSize) 
	: size(initialSize){
	initializeMembers(size);
}




/*
 * Dtor
 */
intArray_t::~intArray_t() {
	delete[] arr;
}




/**
 * Public members
 */

int intArray_t::getSize() const{
	return this->size;
}

int intArray_t::getCapacity() const{
	return this->capacity;
}


void intArray_t::insert(int* e){

	insert_p(size, e);					//insert element

}

int* intArray_t::getFirst() const{
	if (this->size == 0)				//Array is empty
		return 0;
	else
		return this->arr[0];
}

int* intArray_t::getLast() const{
	if (this->size == 0)				//Array is empty
		return 0;
	else
		return this->arr[size - 1];
}


int* intArray_t::find(int v){

	int i = findIndex(0, v);

	if (i != -1){
		return this->arr[i];
	}
	else
		return 0;
}


int* intArray_t::remove(int v){
	return remove_p(v);
}

void intArray_t::removeAll(){
	this->size = 0;
}

void intArray_t::removeAndDelete(int v){

	int *e;

	e = remove_p(v);					//Find & remove first match

	while (e != 0){
		delete e;						//Free memory

		e = remove_p(v);				//Remove next match
	}

}

void intArray_t::removeAndDeleteAll(){


	//free all elemets in array
	for (int i = 0; i < this->size; i++){
		delete this->arr[i];
	}

	this->size = 0;

}

int intArray_t::append(int i, int* e){

	return insert_p(i + 1, e);

}

int intArray_t::prepend(int i, int* e){

	return insert_p(i, e);
}

/**
 * Private members
 */

/*
 * Shift all elements that are on the right hand side of index i into index i
 * Return 1 on success 0 otherwise
 */
int intArray_t::shiftLeft(int i){

	if (i > this->size){
		return 0;
	}

	for (int j = i; j < this->size - 1; j++){
		this->arr[j] = this->arr[j + 1];
	}

	return 1;


}

/*
 * Shift all elements on the right hand side of index i (including i) one index right
 * Return 1 on success 0 otherwise
 */
int intArray_t::shiftRight(int i){

	if (i > this->size || this->size + 1 > this->capacity){
		return 0;
	}

	for (int j = size; j > i; j--){
		this->arr[j] = this->arr[j - 1];
	}

	return 1;
}



/*
 * Expand Array by xpand_value
 * Return 1 on success 0 otherwise
 */
int intArray_t::xpand(){

	int **tmp = new int* [this->capacity + this->xpand_value];

	if (tmp == 0){
		return 0;
	}

	for (int i = 0; i < this->size; i++){
		tmp[i] = this->arr[i];
	}

	this->capacity += this->xpand_value;

	delete[] arr;

	this->arr = tmp;

	return 1;
}

/*
 * Insert element e at index i
 * Return 1 on success 0 otherwise
 */
int intArray_t::insert_p(int i, int* newElement){

	if( newElement == NULL){						//case NULL do nothing
		return 0;
	}

	if (i > this->size){							//Attempt to insert after end of array
		return 0;
	}

	if((this->size == this->capacity) && !xpand()){			//xpand if necessary. Return 0 on fail
		return 0;
	}


	if (i < this->size && !shiftRight(i)){		//Move all elmements on the right hand size of i one position right
		return 0;
	}

	this->size++;						//increment size
	this->arr[i] = newElement;		//assign newElement

	return 1;
}


/*
 * Remove the first element with the value "value"
 * return 0 if no such element, or the element otherwise
 */
int* intArray_t::remove_p(int value) {

	int index = findIndex(0, value); //find the index of value

	if (index == -1) //case no such element
	{
		return 0;
	}

	int* element = this->arr[index];
	shiftLeft(index); //shift the elements in array left onto index i
	this->size--; //decrease size by 1

	return element;
}


/*
 * Return the first index of the element with value "value" starting from index i (including i)
 * Return index of element on success -1 otherwise (Not found)
 */
int intArray_t::findIndex(int startIndex, int value) {

	for (int i = startIndex; i < this->size; i++) //search the element in the array
	{
		if (*(this->arr[i]) == value) {
			return i;
		}
	}

	return -1; //case element wasn't found
}

/*
 * Initialize class members
 */
void intArray_t::initializeMembers(int initialCapacity) {
	this->capacity = initialCapacity;
	this->xpand_value = XPAND_VALUE;
	this->arr = new int*[capacity];
}


/*
 * Print out array status and elements
 */
ostream& operator<< (ostream& os, intArray_t& a){


	os << "\n" << "Size: " <<  a.size << "\n" << "Capacity: "
			<< a.capacity << "\n";

	os << "| ";

	for (int i = 0; i < a.size; i++) {
		os << *(a.arr[i]) << " | ";
	}

	os << "\n";

	return os;

}
