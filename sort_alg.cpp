//============================================================================
// Name        : BubbleSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <time.h>
#include <chrono>
#include <ctime>

using namespace std;
void IntroSort(int* tab, int left, int right, int M);
int *pom;
int M = 2*log(10); // maxdepth  used for IntroSort
//helper function to swap to elements in an array
void swap(int* a, int* b) {
	int* temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* tab, int n) {

	     while(n > 1) {
		     for(int j = 0; j < n-1; j++) {
			    if(tab[j] > tab[j+1]) swap(tab[j], tab[j+1]);
		     }
		     n--;
	     }
    }

void InsertionSort(int* tab, int n) {
	for(int i = 1; i< n; i++) {
		int temp = tab[i];
		int j= i-1;

		while(j >= 0 && tab[j] >= temp) {
			tab[j+1] = tab[j];
			tab[j] = temp;
			j--;

		}
	}
}

void Heapify(int* tab, int size, int index) {
	int root = index;
	int left = 2*index+1;
	int right = 2*index+2;
	if(left < size && tab[left] > tab[root]) root = left;
	if(right < size && tab[right] > tab[root]) root = right;
	if(root != index) {
		swap(tab[index], tab[root]);
		Heapify(tab, size, root);
	}
}

void HeapSort(int* tab,int size) {
	for(int i = size/2 -1; i >= 0; i--) {
		Heapify(tab, size, i);
	}
	for(int j = size-1; j>= 0;j--) {
		swap(tab[0], tab[j]);
		Heapify(tab, j,0);
	}
}

void Merge(int tab[], int left, int mid, int right) {

	int i = left, j = mid + 1;

  for(int i = left; i <= right; i++)
    pom[i] = tab[i];

  for(int k = left; k <= right; k++)
  if(i <= mid)
    if(j <= right)
         if(pom[j] < pom[i])
             tab[k] = pom[j++];
         else
             tab[k] = pom[i++];
    else
        tab[k] = pom[i++];
  else
      tab[k] = pom[j++];

}

void MergeSort(int tab[],int left, int right)
{
	if(right <= left) return;

	int mid = (left + right)/2;

	MergeSort(tab, left, mid);
	MergeSort(tab, mid + 1, right);

	Merge(tab, left, mid, right);
}

void  QuickSort(int* tab, int left, int right) {

      int leftmark = left, rightmark = right; // current left and right indexes
      int pivot = tab[(left + right) / 2];    // assign middle element to pivot

      //partition stage
      while (leftmark <= rightmark) { // do until left and right meet up
    	  //left side
    	  while (tab[leftmark] < pivot) // move leftmark until a value higher than current pivot is found
            	leftmark++;

            while (tab[rightmark] > pivot) // move rightmark until a value lower than current pivot is found
            	rightmark--;

            //now the element of leftmark is on the wrong side and so is the element of rightmark- swap them
            if (leftmark <= rightmark) {
                  swap(tab[leftmark], tab[rightmark]); //swapping elements to put them on the correct side of pivot
                  leftmark++;
                  rightmark--;
            }
      }


      //Recursively call to function unttil the partitioned subarrays are of size 1
      if (left < right) {

    	  QuickSort(tab, left, rightmark); //start left of pivot
    	  QuickSort(tab, leftmark, right); //start right of pivot

    }
}

// Creats an array of randomly generated integer values of given length n
//Made for tests
int* CreateArray(long n) {

	int* tab = new int[n];
	srand (time(NULL));
	for(int i = 0; i < n; i++) {
		tab[i] = rand() % 100;
	}
	return tab;
}

//Creats an array with some of the first elements already sorted and the rest randomly generated
//Made for tests
int* CreateSortedArray(int n) {
	int* tab = new int[n];
	srand (time(NULL));

	for(int i = 0; i < 0.5*n; i++) {
		tab[i] = i;
	}
	for(int i = 0.5*n; i < n; i++) {
			tab[i] = rand() % 100;
		}
	return tab;
}

int* CreateDescendingArray(int n) {
	int* tab = new int[n];
	for(int i = 0; i < n; i++) {
		tab[i] = n-i;
	}
	return tab;
}
//Performs a given Sorting method on 100 arrays
void TestSort(int n) {

	for(int i = 0; i < 100; i++) {
		int* sample = CreateDescendingArray(n);
		//Put any sorting algorithm here
		QuickSort(sample, 0, n-1);
		delete [] sample;
	}
}
void IntroSort(int* tab, int left, int right, int M) {
	//Check whether maxdepth has been reached
	if(M > 0) {
		 int leftmark = left, rightmark = right; // current left and right indexes
		      int pivot = tab[(left + right) / 2]; // assign middle element to pivot

		    //Partition Stage
		      while (leftmark <= rightmark) { // do until left and right meet up
		            //left side
		    	  	while (tab[leftmark] < pivot) // move leftmark until a value higher than current pivot is found
		            	leftmark++;
		    	  	//right side
		            while (tab[rightmark] > pivot) // move rightmark until a value lower than current pivot is found
		            	rightmark--;

		            //now the element of leftmark is on the wrong side and so is the element of rightmark- swap them
		            if (leftmark <= rightmark) {
		                  swap(tab[leftmark], tab[rightmark]); //swapping elements to put them on the correct side of pivot
		                  leftmark++;
		                  rightmark--;
		            }
		      }


		    //Recursively call to function unttil the partitioned subarrays are of size 1
		      if (left < right) {

		    	  IntroSort(tab, left, rightmark, M-1); //we give the function the value of M-1  to update current depth of recursion
		    	  IntroSort(tab, leftmark, right, M-1);

		    }
	}
	// if maxdepth has been reached switch over from quicksort
	// to heapsort to prevent worst-case scenario of quicksort
	else {
		HeapSort(tab, right-left);
	}
}

//prints elements f given array
void PrintArray(int* tab) {
	for(int i = 0; i < 10; i++)
		cout << tab[i] << "    ";
	}

int main() {


	int n = 1500000; // length of sorted array
	//int tab[10] = {1,5,3,8,2,9,7,6,4,0};
	//pom = new int[n]; //helper array for MergeSort

	//Using the chrono library to measure time passed
	//from beginning to end of function execution
	auto start = std::chrono::system_clock::now();
	std::cout << "sorting in progress.. ";
	TestSort(n);
	cout << '\n';
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
	          << "elapsed time: " << elapsed_seconds.count() << "s\n";


	//int* tab = CreateDescendingArray(n);
	//cout << "tablica nieposortowana: ";
	//PrintArray(tab);
	//BubbleSort(arr, 100);
	//InsertionSort(tab, n);
	//HeapSort(tab, n);
	//MergeSort(tab, 0, n-1);
	//IntroSort(tab,0,10-1, M);
	//QuickSort(tab, 0, 10-1);
	//cout << "\n tablica posortowana: ";
	//PrintArray(tab);
	return 0;
}
