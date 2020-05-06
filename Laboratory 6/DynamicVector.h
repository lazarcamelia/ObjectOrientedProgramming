#pragma once
#include "Victim.h"

template <typename TYPE> 
class DynamicVector {
private:
	int capacity;
	int size;
	TYPE* files;
public:
	//constructor
	DynamicVector(int capacity = 10);
	//destructor
	~DynamicVector();
	//copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& dynamicVector);
	//asignment operator
	DynamicVector& operator=(const DynamicVector& dynamicVector);
	//[] operator
	TYPE& operator[](int position);
	//get the number of elements of the dynamicVector
	int getSize() const;
	//add an element to the dynamicVector
	void addElement(const TYPE& newElement);
	// delete an element from the dynamicVector
	void deleteElement(const TYPE& elementToBeDeleted);
	//update an element to the dynamicVector
	void updateElement(const TYPE& elementToBeUpdated);
	//check if an elment exist in the dynamicVector
	bool existElement(const TYPE& dynamicVector);
	//get the element on position from the dynamicVector
	TYPE getElementOnPosition(int position);
	//gte the element which is equal to the given element
	TYPE getElementEqual(const TYPE& element);
private:
	//resize the dynamic vector
	void resize(double factorOfResizing = 2);
};

template<typename TYPE>
inline DynamicVector<TYPE>::DynamicVector(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->files = new TYPE[this->capacity];
}

template<typename TYPE>
inline DynamicVector<TYPE>::~DynamicVector() {
	delete[] this->files;
}

template<typename TYPE>
inline DynamicVector<TYPE>::DynamicVector(const DynamicVector& dynamicVector) {
	this->capacity = dynamicVector.capacity;
	this->size = dynamicVector.size;
	this->files = new TYPE[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->files[i] = dynamicVector.files[i];
}

template<typename TYPE>
inline DynamicVector<TYPE>& DynamicVector<TYPE>::operator=(const DynamicVector& dynamicVector)
{
	DynamicVector<TYPE> copyOfDynamicVectorToBeDeleted{ dynamicVector };
	std::swap(copyOfDynamicVectorToBeDeleted.capacity, this->capacity);
	std::swap(copyOfDynamicVectorToBeDeleted.size, this->size);
	std::swap(copyOfDynamicVectorToBeDeleted.files, this->files);
	
	//because the new alocated vector is static, the previous elements from this will be destroyed after function
	return *this;
}


template<typename TYPE>
inline TYPE& DynamicVector<TYPE>::operator[](int position) {
	return this->files[position];
}

template<typename TYPE>
inline int DynamicVector<TYPE>::getSize() const {
	return this->size;
}

template<typename TYPE>
inline void DynamicVector<TYPE>::addElement(const TYPE& newElement) {
	if (this->size == this->capacity)
		this->resize();
	this->files[this->size++] = newElement;

}

template<typename TYPE>
inline void DynamicVector<TYPE>::deleteElement(const TYPE& elementToBeDeleted) {
	int positionToBeDeleted = 0;
	for (int i = 0; i < this->size; i++) {
		if (this->files[i] == elementToBeDeleted) {
			positionToBeDeleted = i;
			break;
		}
	}

	for (int i = positionToBeDeleted; i < this->size - 1; i++)
		this->files[i] = this->files[i + 1];
	this->size--;
}

template<typename TYPE>
inline void DynamicVector<TYPE>::updateElement(const TYPE& elementToBeUpdated) {
	for (int i = 0; i < this->size; i++) {
		if (this->files[i] == elementToBeUpdated) {
			this->files[i] = elementToBeUpdated;
			break;
		}
	}
}

template<typename TYPE>
inline bool DynamicVector<TYPE>::existElement(const TYPE& dynamicVector) {
	for (int i = 0; i < this->size; i++) {
		if (this->files[i] == dynamicVector)
			return true;
	}
	return false;

}

template<typename TYPE>
inline TYPE DynamicVector<TYPE>::getElementOnPosition(int position) {
	return this->files[position];
}

template<typename TYPE>
inline TYPE DynamicVector<TYPE>::getElementEqual(const TYPE& element)
{
	for (int i = 0; i < this->size; i++) {
		if (this->files[i] == element)
			return this->files[i];
	}
}

template<typename TYPE>
inline void DynamicVector<TYPE>::resize(double factorOfResizing) {
	this->capacity *= 2;
	TYPE* newDynamicVectorWithDoubleCapacity = new TYPE[this->capacity];

	for (int i = 0; i < this->size; i++)
		newDynamicVectorWithDoubleCapacity[i] = this->files[i];
	
	delete[] this->files;
	this->files = newDynamicVectorWithDoubleCapacity;
}
