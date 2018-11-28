#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// helper function to merge two adjacent arrays within an array, to the
// passed array
void merge(int * array, int a, int b, int c, int d){
   // get the size of the two arrays
   int size = d-a+1;
   // create a temp array of that size
   int temp[size];
   // initialize the start of each array to merge
   int i = a;
   int j = c;
   int k = 0;
   // merge the two arrays until you get to the end of one
   while (i<=b && j<=d){
      if (array[i] < array[j])
         temp[k++] = array[i++];
      else 
         temp[k++] = array[j++];
   }
   // add the remainder of the first array to the temp array, if any
   while (i <= b){
      temp[k++] = array[i++];
   }
   // add the remainder of the second array to the temp array, if any
   while (j <= d){
      temp[k++] = array[j++];
   }
   // copy the temp array back into the first and second half
   // of the passed array
   for (i = 0; i < size; i++)
      array[a+i] = temp[i];
}

// merge sort the passed array, given the range indicies
void merge_sort(int * array, int a, int b){
   // check for NULL input
   if (array == NULL) return;
   // base case, one element
   if (b == a) return;
   // divide the array in half
   int half = (b-a)/2;
   // merge sort the left half
   merge_sort(array, a, a+half);
   // merge sort the right half
   merge_sort(array, a+half+1, b);
   // merge the left and right side
   merge(array, a, a+half, a+half+1, b);
}

// helper function to print an integer array, given the size
void print_array(int * array, int size){
   if (array == NULL){
      fprintf(stdout, "NULL\n");
      return;
   }

   fprintf(stdout, "[");
   for (int i = 0; i < size; i++){
      if (i+1<size)
         fprintf(stdout, "%d, ", array[i]);
      else
         fprintf(stdout, "%d", array[i]);
   }
   fprintf(stdout, "]\n");
}

// main entry point with tests. normally a header would hide the functions
// that are private and expose the functions that are public. for this case, 
// no such header exists
//
int main(void){

   // arrays to sort
   int array1[] = {1, 3, 2, 4, 5, 7, 9, 11, 6, 0, 8};
   int array2[] = {3, 2, 4, 5, 8};
   int array3[] = {1, 3, 2, 4, 5, 7, -9, -11, 6, 0, -8};
   int array4[] = {};
   int sizes[] = {sizeof(array1), sizeof(array2), sizeof(array3), sizeof(array4)};

   int number_of_tests = 5;
   int ** tests = malloc(number_of_tests*sizeof(int *));

   tests[0] = array1;
   tests[1] = array2;
   tests[2] = array3;
   tests[3] = array4;
   tests[4] = NULL;

   for (int i = 0; i < number_of_tests; i++){
      int * array = tests[i];
      // get the size fo the array
      int size = sizes[i]/sizeof(int);
      // print the array
      fprintf(stdout, "Presorted A = ");
      print_array(array, size);
      // merge sort the array
      merge_sort(array, 0, size-1);
      // print the resultant array
      fprintf(stdout, "Sorted    A = ");
      print_array(array, size);
      fprintf(stdout, "\n");
   }
   // exit
   return 0;
}
