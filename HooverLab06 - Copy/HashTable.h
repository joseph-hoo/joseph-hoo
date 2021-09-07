#pragma once

#include <iostream>
#include <iomanip>

#include "Currencies.h"

using namespace std;

class HashTable {
private:
	int SIZE = 29;
	USD* hashTableArr = new USD[SIZE];
	int numCollisions = 0;
	int numItemsLoaded = 0;
	double loadFactor = 0;

public:
	// constructor
	HashTable() {
		
		for (int i = 0; i < SIZE; i++) {
			hashTableArr[i].setNoteVal(-1);
			hashTableArr[i].setCoinVal(-1);
		}
	}
	// destructor
	~HashTable() {

	}
	
	// getter
	USD* getArr() {
		return hashTableArr;
	}

	void printHash() {
		for (int i = 0; i < SIZE; i++) {
			cout << (i + 1) << ": " << hashTableArr[i] << endl;
		}
	}

	int hash(USD key) {
		int m = 2, n = 3, w = 0, f = 0, hashLocation = -1;

		w = key.getNoteVal();
		f = key.getCoinVal();

		hashLocation = (m * w + n * f) % SIZE;

		return hashLocation;
	}

	void hashInsert(USD arr[], USD key) {
		int i = 0;
		int bucketsProbed = 0;
		USD emptySinceStart;
		emptySinceStart.setNoteVal(-1);
		emptySinceStart.setCoinVal(-1);

		int bucket = hash(key) % SIZE;

		while (bucketsProbed < SIZE) {
			if (arr[bucket] == emptySinceStart) {
				arr[bucket] = key;
				
				numItemsLoaded = numItemsLoaded + 1;
				loadFactor = determineLoadFactor();
				return;
			}
			
			i = i + 1;
			bucket = (hash(key) + 2 * i + 3 * i + i * i) % SIZE;
			numCollisions = numCollisions + 1;
			bucketsProbed = bucketsProbed + 1;
		}
		
		loadFactor = determineLoadFactor();
		return;
	}

	bool hashSearch(USD key) {
		bool isInArray = false;
		int i = 0;

		int bucketsProbed = 0;
		int bucket = hash(key) % SIZE;
		USD emptySinceStart;
		emptySinceStart.setNoteVal(-1);
		emptySinceStart.setCoinVal(-1);

		while (!(hashTableArr[bucket] == emptySinceStart) &&
			   (bucketsProbed < SIZE)) {
			if (!(hashTableArr[bucket] == emptySinceStart) && (hashTableArr[bucket] == key)) {
				// item was found in array
				isInArray = true;
				std::cout << "The object is in element " << bucket << std::endl;
				return isInArray;
			}

			i = i + 1;
			bucket = (hash(key) + 2 * i + 3 * i + i * i) % SIZE;
			bucketsProbed = bucketsProbed + 1;
		}

		// item does not exist or was not found in array
		return isInArray;
	}

	double determineLoadFactor() {
		double numItems, size;
		numItems = numItemsLoaded;
		size = SIZE;

		return numItems / size;
	}

	// prints secondary info of hash table
	void printHashInfo() {
		std::cout << "This hash table has the following information" << std::endl;
		std::cout << "Number of Data Items: " << numItemsLoaded << endl;
		std::cout << "Load Factor of Table: " << setprecision(3) << loadFactor << endl;
		std::cout << "Number of Collisions: " << numCollisions << endl;

	}
};