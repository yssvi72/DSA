// IP:  1 2 3 4 5 6 7 
// OP : 7 6 5 4 3 2 1
// Task is to reverse the array 

//Approach 1: Using for loop for traversing end to beginning
int main() {
    const int maxSize = 100; // Set a maximum size for the array
    int arr[maxSize]; // Declare an array
    int n;
    std::cout << "Enter the size of the array: ";  // Input the size of the array
    std::cin >> n; // Input the elements of the array
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; i++) {  std::cin >> arr[i]; }
    for (int i = n - 1; i >= 0; i--) { // Reverse the array using for loop
        std::cout << arr[i] << " ";  }
    return 0;
     }
   //  Time Complexity---> O(n) , Space Complexity --> O(1)---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

   // Approach 2: Using STL function ( Reverse function)
   std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Reverse the array using std::reverse
    std::reverse(arr, arr + n);

    // Print the reversed array
    std::cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
  //---Time Complexity ---->O(n) , Space Complexity --> o(n) or O(1) based on size of array------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  // Aproach 3: Using pointers although time and space complexity remains same , TC-->O(n) and SC-->O(1)

void reverseArray(int arr[], int size) {  // Function to reverse the array using pointers
    int *start = arr;            // Pointer to the start of the array
    int *end = arr + size - 1;    // Pointer to the end of the array

    // Swap elements pointed by start and end until they meet in the middle
    while (start < end) {
        std::swap(*start, *end);  // Swap the elements

        // Move pointers towards each other
        start++;                  // Move start pointer to the right
        end--;                    // Move end pointer to the left
    }
}

int main() {
    const int maxSize = 100;     // Set a maximum size for the array
    int arr[maxSize];             // Declare an array
    int n;

    // Input the size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    // Input the elements of the array
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Reverse the array using pointers
    reverseArray(arr, n);

    // Print the reversed array
    std::cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
