#include <cstddef>
#include <iostream>

// Generate the combining array
int *apply_all(const int *const arr1, size_t n1, const int *const arr2, size_t n2) {
   int *arr = new int [n1*n2];

   for (size_t i = 0; i < n1; ++i) {
      int base = i*n2;
      for (size_t j = 0; j < n2; ++j) {
         arr[base + j] = arr1[i] * arr2[j];
         /* printf("XT_DEBUG: i=%d j=%d base=%d, arr1[i]=%d arr2[i]=%d arr[base+j]=%d\n", i, j, base, arr1[i], arr2[j], arr[base+j]); */
      }
   }
   return arr;
}


// Display array
void display_array(const int *const arr, size_t n) {
   for (size_t i = 0; i < n; ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << std::endl;
}


// Main function
int main() {
   int arr1[] {1, 2, 3, 4, 5};
   int arr2[] {10, 20, 30};

   int n1 = int(sizeof(arr1)/sizeof(arr1[0]));
   int n2 = int(sizeof(arr2)/sizeof(arr2[0]));

   // Display arrays
   std::cout << "Input array 1, " << n1 << " elements" << std::endl;
   display_array(arr1, n1);
   std::cout << "Input array 2, " << n2 << " elements" << std::endl;
   display_array(arr2, n2);

   int *arr = apply_all(arr1, n1, arr2, n2);
   std::cout << "Output array, " << n1*n2 << " elements" << std::endl;
   display_array(arr, n1*n2);
   
   std::cout << "Done" << std::endl;

   // Return
   delete [] arr;
   return 0;
}

