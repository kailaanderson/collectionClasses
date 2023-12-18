// Defines class methods and the big 3
// Kaila Anderson
// November 14, 2022

#include <iostream>
#include "collection.hpp"

using std::cin; using std::cout; using std::endl;

Collection::Collection() {
	size_ = 0;
	col_ = new double[size_];
}

int Collection::check(double number) {
	for (int i = 0; i < size_; ++i) {
		if (col_[i] == number)
			return i;
	}

	return -1;
}

void Collection::addNumber(double number) {
	int index = check(number);

	if (index == -1) {

		double* tmpArray = new double[size_ + 1];
		size_++;
		for (int i = 0; i < size_ - 1; ++i) {
			tmpArray[i] = col_[i];
		}

		tmpArray[size_ - 1] = number;
		delete[] col_;
		col_ = tmpArray;

	}
}

void Collection::removeNumber(double number) {
	if (check(number) != -1) {
		bool found = false;
		double* tmpArray = new double[size_ - 1];
		size_--;
		for (int i = 0; i < size_; ++i) {
			if (col_[i] == number) {
				found = true;
			}
			else {
				if (found == false) {
					tmpArray[i] = col_[i];
				}
				else
					tmpArray[i - 1] = col_[i];

			}
		}
		tmpArray[size_ - 1] = col_[size_];
		delete[] col_;
		col_ = tmpArray;
	}
}

void Collection::output() const {
	for (int i = 0; i < size_; ++i) {
		cout << col_[i] << " "; 
	}
}

double Collection::value() const {
	double sum = 0;
	for (int i = 0; i < size_; ++i) {
		sum += col_[i];
	}
	return sum;
}

void Collection::outputSize() const {
	int size = size_;
	cout << size_ << endl;
}

Collection::Collection(const Collection& collect) {
	size_ = collect.size_;
	col_ = new double[size_];
	for (int i = 0; i < size_; ++i) {
		col_[i] = collect.col_[i];
	}
}

Collection& Collection::operator=(const Collection& rhs) {
	if (this != &rhs) {
		size_ = rhs.size_;
		delete[] col_;
		col_ = new double[size_];
		for (int i = 0; i < size_; ++i) {
			col_[i] = rhs.col_[i];
		}
	}
	return *this;
}

Collection::~Collection() {
	delete[] col_;
}