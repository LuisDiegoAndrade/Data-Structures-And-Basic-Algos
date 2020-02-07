#ifndef DataGen_h
#define DataGen_h

#include "RandomSupport.h"

/*void quickSort(long list[], long left, long right) {

      long i = left, j = right;
      long tmp;
      long pivot = list[(left + right) / 2];

      while (i <= j) { //start
            while (list[i] < pivot)
                  i++;

            while (list[j] > pivot)
                  j--;

            if (i <= j) {

                  tmp = list[i];
                  list[i] = list[j];
                  list[j] = tmp;
                  i++;
                  j--;
            }

      }//end

      if (left < j)
            quickSort(list, left, j);

      if (i < right)
            quickSort(list, i, right);

}*/

/*void merge(long list[], long start, long mid, long end){

long i = start;
long j = mid+1;

while(j <= end && i <= mid){

    if (list[i] < list[j]){
	i++;
	} else {
	   long temp = list[j];

	   for (long k = j; k > i; --k){
 	   list[k] = list [k-1];
	   } // for end
	   
	   list[i] = temp;
	   mid++;
	   i++;
	   j++;
	} //else end
   } //while end
}

void merge_sort (long list[], long start, long end){
   if (start < end){
   
     long mid = (start+end)/2;
     merge_sort (list, start, mid);
     merge_sort (list, mid+1, end);

     merge (list, start, mid, end);
  }

}*/


void insertion_sort(long list[], long size){
    long n = size;
    for (long i = 1; i < n; i++) {
        long j = i;
        while (j > 0 && list[j-1] > list[j]){
            long temp = list[j];
            list[j] = list[j-1];
            list[j-1] = temp;
            j = j - 1;
        }
    }
}



void efficientRandomSortedList(long temp[], long s){
    // Get a new random device
    randomizer device = new_randomizer();
    // Get a uniform distribution from 1 to 1000
    //Note: Changing distribution to 1 to 1 will give a sorted array
    uniform_distribution range = new_distribution(1, 1000);
    
    for (long i = 0; i < s; i++) {
        // Insert a randomly selected number
        // from distribution defined above
        temp[i] = sample(range, device);
    }
    
    // Now sort the array using insertion_sort (fastest when array is sorted)
    insertion_sort(temp, s-1);
    //quickSort(temp, 0, s-1);
    //merge_sort(temp, 0, s-1);
}


#endif /* DataGen_h */
