#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Task 1: Separate odd and even integers into separate arrays
    
    // Test Data:
    // Input the number of elements to be stored in the array: 5
    // Input 5 elements in the array:
    // element - 0 : 25
    // element - 1 : 47
    // element - 2 : 42
    // element - 3 : 56
    // element - 4 : 32

    // Expected Output:
    // The Even elements are: 42 56 32
    // The Odd elements are: 25 47
    vector<int> evens; 
    vector<int> odds;
    vector<int> numSort = {25,47,42,56,32};
    for (int i = 0; i < numSort.size(); i++){
        if (numSort[i]%2 == 0){
            evens.push_back(numSort[i]);
        }else{
            odds.push_back(numSort[i]);
        }
    }
    cout << "The Even elements are: ";
    for (int e = 0; e < evens.size(); e++){
        cout << evens[e] << ' ';
    }
    cout << "the Odd elements are: ";
    for (int o = 0; o < odds.size(); o++){
        cout << odds[o] << " ";
    }
    
    // Task 2: Insert an additional value into a sorted array

    // Test Data:
    // Input the size of array: 3
    // Input 3 elements in the array in ascending order:
    // element - 0 : 5
    // element - 1 : 7
    // element - 2 : 9
    // Input the value to be inserted: 8
    cout << "\n";
    // Expected Output:
    // The existing array list is: 5 7 9
    // After Insert the list is: 5 7 8 9
    vector<int> sorting = {5,7,9};
    sorting.insert(sorting.begin()+2, 8);
    for (int s=0; s < sorting.size(); s++){
        cout << sorting[s] << " ";
    }

    // Task 3: Delete an element at a desired position from an array

    // Test Data:
    // Input the size of array: 5
    // Input 5 elements in the array in ascending order:
    // element - 0 : 1
    // element - 1 : 2
    // element - 2 : 3
    // element - 3 : 4
    // element - 4 : 5
    // Input the position where to delete: 3
    cout << "\n";
    // Expected Output:
    // The new list is: 1 2 4 5
    vector<int> dele = {1,2,3,4,5};
    dele.erase(dele.begin()+3);
    for (int d: dele){
        cout << d << " ";
    }

    // Task 4: Find the second smallest element in an array
    cout << '\n';
    // Test Data:
    // Input the size of array: 5
    // Input 5 elements in the array (value must be <9999):
    // element - 0 : 0
    // element - 1 : 9
    // element - 2 : 4
    // element - 3 : 6
    // element - 4 : 5

    // Expected Output:
    // The Second smallest element in the array is: 4
    vector<int> small = {0,9,4,6,5};
    sort(small.begin(), small.end());
    cout << small[1];
    // Task 5: Add two matrices of the same size
    cout << '\n';
    // Test Data:
    // Input the size of the square matrix (less than 5): 2
    // Input elements in the first matrix:
    // element - [0],[0] : 1
    // element - [0],[1] : 2
    // element - [1],[0] : 3
    // element - [1],[1] : 4

    // Input elements in the second matrix:
    // element - [0],[0] : 5
    // element - [0],[1] : 6
    // element - [1],[0] : 7
    // element - [1],[1] : 8

    // Expected Output:
    // The First matrix is:
    // 1 2
    // 3 4
    // The Second matrix is:
    // 5 6
    // 7 8
    // The Addition of two matrices is:
    // 6 8
    // 10 12
    int matrix1[2][2] = {
        {1,2},
        {3,4}
    };
    int matrix2[2][2] = {
        {5,6},
        {7,8}
    };
    int matrix3[2][2] = {
        {matrix1[0][0]+matrix2[0][0],matrix1[0][1]+matrix2[0][1]},
        {matrix1[1][0]+matrix2[1][0],matrix1[1][1]+matrix2[1][1]}
    };
    cout << "First Matrix is: \n";
    cout << matrix1[0][0] << ' ' << matrix1[0][1] << '\n' << matrix1[1][0] << ' ' << matrix1[1][1] << '\n';
    cout << "Second Matrix is: \n";
    cout << matrix2[0][0] << ' ' << matrix2[0][1] << '\n' << matrix2[1][0] << ' ' << matrix2[1][1] << '\n';
    cout << "Third Matrix is: \n";
    cout << matrix3[0][0] << ' ' << matrix3[0][1] << '\n' << matrix3[1][0] << ' ' << matrix3[1][1] << '\n';
    return 0;
}
