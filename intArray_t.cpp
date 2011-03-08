/*
 * intArray_t.cpp
 *
 *  Created on: 07/03/2011
 *
 */
#include "intArray_t.h"


/**
 * Constructors & Destructor (
 */
//TODO: ADIR
intArray_t::intArray_t(){

}
//TODO: ADIR
intArray_t::intArray_t(intArray_t& a){

}
//TODO: ADIR
intArray_t::intArray_t(int size){

}
//TODO: ADIR
intArray_t::~intArray_t(){

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
	return 0;
}

int intArray_t::getCapacity(){
	return 0;
}


void intArray_t::insert(int* e){

}

int* intArray_t::getFirst(){
	return 0;
}

int* intArray_t::getLast(){
	return 0;
}


int* intArray_t::find(int v){
	return 0;
}

int* intArray_t::remove(int v){
	return 0;
}

void intArray_t::removeAll(){

}

void intArray_t::removeAndDelete(int v){

}

int intArray_t::removeAndDeleteAll(){
	return 0;
}

int intArray_t::append(int i, int* e){
	return 0;
}

int intArray_t::prepend(int i, int* e){
	return 0;
}

/**
 * Private members
 */

/*
 * Shift all elements that are on the right hand side of index i into index i
 * Return 1 on success 0 otherwise
 */
int shiftLeft(int i){
	return 0;
}

/*
 * Shift all elements on the right hand side of index i (including i) one index right
 * Return 1 on success 0 otherwise
 */
int shiftRight(int i){
	return 0;
}

/*
 * Expand Array by xpand_value
 * Return 1 on success 0 otherwise
 */
int xpand(){
	return 0;
}

/*
 * Insert element e at index i
 * Return 1 on success 0 otherwise
 */
//TODO: ADIR
int insert_p(int i, int* e){
	return 0;
}

/*
 * Remove element at index i (DO NOT DELETE element)
 * Return 1 on success 0 otherwise
 */
//TODO: ADIR
int remove_p(int i){
	return 0;
}

/*
 * Find first element with value v starting from index i (including i)
 * Return element on success 0 otherwise (Not found)
 */
int *find_p(int i, int v){
	return 0;
}
