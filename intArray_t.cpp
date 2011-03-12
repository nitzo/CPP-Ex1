/*
 * intArray_t.cpp
 *
 *  Created on: 07/03/2011
 *
 */
#include <iostream>
#include "intArray_t.h"

using namespace std;

/**
 * Constructors & Destructor
 */

//TODO: Initilization Lists
/*
 * Default Ctor
 */
intArray_t::intArray_t() {
	initializeMembers(XPAND_VALUE);
}

/*
 * Overload Ctor
 */
intArray_t::intArray_t(int size) {
	initializeMembers(size);
}

//TODO: ADIR
intArray_t::intArray_t(intArray_t& a){

}



/*
 * Dtor
 */
intArray_t::~intArray_t() {
	delete[] arr; //TODO: do we need to declare as arr*?
}



/**
 * Operator overloading
 */
//TODO: ADIR
const intArray_t& intArray_t::operator=(const intArray_t&){


	return *this; //TODO: Fix this!!!

}


/**
 * Public members
 */


int intArray_t::getSize(){
	return this->size;
}

int intArray_t::getCapacity(){
	return this->capacity;
}


void intArray_t::insert(int* e){

	insert_p(size, e);

}

int* intArray_t::getFirst(){
	if (this->size == 0) //Array is empty
		return 0;
	else
		return this->arr[0];
}

int* intArray_t::getLast(){
	if (this->size == 0) //Array is empty
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

/*
 * Remove the first element with the value "value"
 * Return 0 if fail or the element otherwise
 */
int* intArray_t::remove(int v){
	return remove_p(v);
}

void intArray_t::removeAll(){
	size = 0;
}

void intArray_t::removeAndDelete(int v){

}

int intArray_t::removeAndDeleteAll(){
	return 0;
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

	if (i > this->size - 1){
		return 0;
	}

	for (int j = 0; j < this->size - 1; j++){
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

	return 1;
}

/*
 * Insert element e at index i
 * Return 1 on success 0 otherwise
 */
int intArray_t::insert_p(int i, int* newElement){

	if (i > this->size){							//Attempt to insert after end of array
		return 0;
	}

	if((this->size == this->capacity) && !xpand()){			//xpand if necessary. Return 0 on fail
		return 0;
	}

	if (i < this->size && !shiftRight(i)){		//Move all elmemnts on the right hand size of i one position right
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

	if (index == 0) //case no such element
	{
		return 0;
	}

	int* element = arr[0];
	shiftLeft(index); //shift the elements left and override i the element in i index
	size--; //decrease size by 1

	return element;
}

/*
 * Find first element with value v starting from index i (including i)
 * Return element on success 0 otherwise (Not found)
 */
//int *intArray_t::find_p(int i, int v){
//
//	int *res = 0;
//
//	for (int j = i; j < this->size; j++){
//
//		if (*(this->arr[j]) ==  v){
//			res = this->arr[j];
//			break;
//		}
//	}
//
//	return res;
//}

/*
 * Return the first index of the element with value "value" starting from index i (including i)
 * Return element on success 0 otherwise (Not found)
 */
int intArray_t::findIndex(int startIndex, int value) {

	for (int i = startIndex; i < this->size; i++) //search the element in the array
	{
		if (*(this->arr[i]) == value) {
			return i;
		}
	}

	return 0; //case element didn't found
}

/*
 * Initialize class members
 */
void intArray_t::initializeMembers(int initialCapacity) {
	this->capacity = initialCapacity;
	this->size = 0;
	this->arr = new int*[capacity];
}

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
