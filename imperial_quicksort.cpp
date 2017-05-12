/*

QUICK SORT with random numbers of n, where n = 1000, 10000, 100000

Implemented in C++ by JOSEPH MARVIN R. IMPERIAL, BSCS 3A 
In compliance for the final project for Design and Analysis of Algorithm (DAA)
Date Submitted: March 27, 2017

Quick Sort is an efficient sorting algorithm, serving as a systematic method for placing the elements of an array in order. (Wikipedia)

*/

//HEADERS
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream> //library needed to write to files
#include <ctime>
#include <ctime>

using namespace std;

void quick(int array[], int, int);

main()
{
	srand (time(NULL));	//seed
	int n,x;
	int *array;
	int start, stop; //clock variables
	
	//Opens file for writing/appending
	ofstream quickFile;
	quickFile.open("quicksortOutput.txt",std::ofstream::app);
	
	//N = 1000
		start=clock(); //starts the clock to measure speed
		
		cout << "Sorting 1000 random numbers...";	
		n = 1000;
		array = new int[n];
		
		// File creation
		quickFile << "Quick Sort, n = " << n;
		quickFile << "\n\n";
		
		// Fills the array with random numbers of range n
		for(x=0; x<n; x++){
			array[x] = rand() % n + 1;
		}    
		
		//calls quicksort function
		quick(array, 0, n-1);
		cout << "Done!";
		
		stop=clock();	//stops clock
		//calculates and displays time taken by program
		cout << "\nExecution time of n = 1000: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n";
		
		for(x=0; x<n; x++){
			//writing sorted array to file
			quickFile << array[x] << " ";
		}
		cout << "\n";
		quickFile << "\n\n";
		delete[]array;
	
	//N = 10000
		start=clock(); 
		cout << "Sorting 10000 random numbers...";	
		n = 10000;
		array = new int[n];
		quickFile << "Quick Sort, n = " << n;
		quickFile << "\n\n";
		for(x=0; x<n; x++){
			array[x] = rand() % n + 1;
		}    
		quick(array, 0, n-1);
		cout << "Done!";
		stop=clock();
		cout << "\nExecution time of n = 10000: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n";
		for(x=0; x<n; x++){
			quickFile << array[x] << " ";
		}
		cout << "\n";
		quickFile << "\n\n";
		delete[]array;
		
	//N = 100000
		start=clock(); 
		cout << "Sorting 100000 random numbers...";	
		n = 100000;
		array = new int[n];
		quickFile << "Quick Sort, n = " << n;
		quickFile << "\n\n";
		for(x=0; x<n; x++){
			array[x] = rand() % n + 1;
		}    
		quick(array, 0, n-1);
		cout << "Done!";
		stop=clock();
		cout << "\nExecution time of n = 100000: " << (stop-start)/double(CLOCKS_PER_SEC) << " seconds\n";
		for(x=0; x<n; x++){
			quickFile << array[x] << " ";
		}
		quickFile << "\n\n";
		delete[]array;
	
}



// QUICK SORT FUNCTION
void quick(int array[], int s, int e){
	
	int i,j,pivot;
	i = s;
	j = e;
	pivot = array[(s + e) / 2];	//the median will be the pivot
	
	//partition operation
	while (i <= j) {
		
		//loops and shifts forward until it gets an element which is greater than pivot, then stops
        while (array[i] < pivot){
        	i = i+1;
        }
        //loops and shifts backward until it gets an element which is less than pivot, then stops
	    while (array[j] > pivot){
	    	j = j-1;
	    }
	    if (i <= j) {
	    	// swaps the two values obtained so that elements less than pivot will go to left, and elements greater than pivot will go to the right
	    	swap(array[i],array[j]);
	    	//on to the next element
	        i = i+1;
	        j = j-1;
	    }
	}
	
	//recursion function that sorts the array section less than the pivot, the left part of the pivot
  	if (s < j){
  		//s becomes new start, j becomes new end
  		quick(array, s, j);	
  	}
  	
  	//recustion function that sorts the array section greater than the pivot, the right part of the pivot
  	if (i < e){
  		//i becomes new start, e becomes new end
  		quick(array, i, e);	
  	}
     
}


