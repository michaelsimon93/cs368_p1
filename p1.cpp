#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

double * feedArray(double *arr, int arrSize) {
    int i;
    double element;
    for (i = 0; i < arrSize; i++) {
	cout << "Enter the elements in the array: ";
	cin >> element;
	arr[i] = element;
    }
    return arr;
}

void minElement(double *arr, int arrSize) {
    double min = arr[0];
    int i;
    for (i = 1; i < arrSize; i++) {
	if (min > arr[i]) {
	    min = arr[i];
	}
    }
    printf("Minimum element in array: %.3lf\n", min);
}

void maxElement(double *arr, int arrSize) {
    double max = arr[0];
    int i;
    for (i = 1; i < arrSize; i++) {
	if (max < arr[i]) {
	    max = arr[i];
	}
    }
    printf("Maximum element in array: %.3lf\n", max); 
}

double *sortArr(double *arr, int arrSize) {
    int i;
    int j;
    int minIndex;
    double min;
    for (i = 0; i < arrSize; i++) {
	minIndex = i;
	for (j = i + 1; j < arrSize; j++) {
	    if (arr[j] < arr[minIndex]) {
		minIndex = j;
	    }
	}
	swap(arr[i], arr[minIndex]);
    }
    return arr;	
}

void floatingAvg(double *arr, int arrSize) { 
    double average;
    double total;
    int i;
    for (i = 0; i < arrSize; i++) {
	total += arr[i];
    }
    
    average = total/arrSize;
    printf("The average of the elements are:  %.3lf\n", average);
}

double * randomRangeGenerate (double *arr, int arrSize, double lowerBound, double upperBound) {
    int i;
    double randomElement;
    for (i = 0; i < 100; i++) {
	randomElement = (rand() / (static_cast<double>(RAND_MAX) + 1.0)) * (upperBound - lowerBound) + lowerBound;
	arr[i] = randomElement;
    }
    return arr;
}

void printElements(double *arr, int arrSize) {
    int i;
    printf("The elements of the array are: ");
    for (i = 0; i < arrSize; i++) {
	printf("%.3lf ", arr[i]);
    }
    printf("\n");
}


int main() {

    srand(1000);
    int arrSize = 0; 
    double *arrptr;	
    int x;

    cout << "Welcome! \n";

    while (x != 8) {
	cout << "1) Feed array input\n";
	cout << "2) Determine the minimum element in the array\n";
	cout << "3) Determine the maximum element in the array\n";
	cout << "4) Sort the array of integers\n";
	cout << "5) Determine the average of the elements in the array\n";
	cout << "6) Randomly generate array elements within a specific range\n";
	cout << "7) Print the elements of the array\n";
	cout << "8) Exit program\n";
	cout << "Enter your choice: ";
	cin >> x;
	
	if (x == 1) {
	    cout << "Number of elements in the array: ";
	    cin >> arrSize;
	    double *arr = new double [arrSize];
	    arrptr = feedArray(arr, arrSize);
	}
	else if (x == 2){
	    if (arrSize == 0) {
		cout << "There must be at least one element in the array.\n";
	    }
	    else {   
		 minElement(arrptr, arrSize);
	    }	    
	}
	else if (x == 3) {
            if (arrSize == 0) {
                cout << "There must be at least one element in the array.\n";
            }   
	    else {	   
	 	maxElement(arrptr, arrSize);
	    }
	}
	else if (x == 4) {
	    if (arrSize == 0) {
                cout << "There must be at least one element in the array.\n";
            }
	    else {   
		arrptr = sortArr(arrptr, arrSize);
		printElements(arrptr, arrSize);
	    } 	    
	}
	else if (x == 5) {
            if (arrSize == 0) {
                cout << "There must be at least one element in the array.\n";
            }
	    else {   	    
		floatingAvg(arrptr, arrSize);
	    }
	}
	else if (x == 6) {
	    double lowerBound;
	    double upperBound;
	    
	    cout << "Number of elements: ";
	    cin >> arrSize;
	    double *arr = new double [arrSize];
	    cout << "Array lower bound: ";
	    cin >> lowerBound;
	    cout << "Array upper bound: ";
	    cin >> upperBound;

	    arrptr = randomRangeGenerate(arr, arrSize, lowerBound, upperBound);
	    printElements(arrptr, arrSize);
	}
	else if (x == 7) {
            if (arrSize == 0) {
                cout << "There must be at least one element in the array.\n";
            }
	    else {   	    
		printElements(arrptr, arrSize);
	    }
	}
    }
    printf("Exiting the program!\nThank you!\n");
    return(0);
} 
