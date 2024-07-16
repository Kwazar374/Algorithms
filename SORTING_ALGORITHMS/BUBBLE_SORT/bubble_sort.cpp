// Bubble Sort
// Author of the code snippet: Bartosz Satola
//////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
//////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BubbleSort(std::vector<T> & vec);
template <typename T>
void Swap(std::vector<T> & vec, int first_elem_index, int second_elem_index);
template <typename T>
void VecPrint(const std::vector<T> & vec, const std::string header_message);
void XORSwap(std::vector<int> & vec, int first_elem_index, int second_elem_index);
//////////////////////////////////////////////////////////////////////////////////////////
// MAIN  
int main()
{
    // Create a vector of 20 integers
    std::vector<int> vec(20);

    // Set up random number generator and distribution
    std::random_device rd; // Seed for the random number engine (provides nondeterministic random numbers often sourced from hardware entropy)
    std::mt19937 gen(rd()); // Standard Mersenne_Twister engine (provides high-quality pseudo-random numbers with a long period and is faster than rd)
    std::uniform_int_distribution<int> dist(1, 100); // Uniform distribution of integers from 1 to 100

    // Fill the vector with random integers
    std::generate(vec.begin(), vec.end(), [&]() {return dist(gen);});

    // Sort the vector using Bubble Sort
    VecPrint(vec, "Before Bubble Sort: ");
    int number_of_comparisons = BubbleSort(vec);
    VecPrint(vec, "After Bubble Sort: ");
    std::cout << "Number of comparisons: " <<  number_of_comparisons << std::endl;
}
// MAIN
//////////////////////////////////////////////////////////////////////////////////////////
// Function to perform optimized Bubble Sort
// Returns the number of comparisons made during the sort
template <typename T>
int BubbleSort(std::vector<T> & vec)
{
    int number_of_comparisons = 0;
    for (int i = 0; i < vec.size(); ++i) { // Outer loop to iterate through the vector
        for (int j = 1; j < vec.size() - i; ++j) { // Inner loop to compare adjacent elements
            if (vec[j-1] > vec[j]) { // If the previous element is greater than the current element
                XORSwap(vec, j-1, j); // Then swap them
            }
            ++number_of_comparisons;
        }
    }
    return number_of_comparisons;
}
//////////////////////////////////////////////////////////////////////////////////////////
// Function to perform swapping of two vector elements
template <typename T>
void Swap(std::vector<T> & vec, int first_elem_index, int second_elem_index) {
    T temp;
    temp = vec[first_elem_index];
    vec[first_elem_index] = vec[second_elem_index];
    vec[second_elem_index] = temp;
}
//////////////////////////////////////////////////////////////////////////////////////////
// Function to print vector elements
template <typename T>
void VecPrint(const std::vector<T> & vec, const std::string header_message) {
    std::cout << header_message << std::endl;
    for (const auto & elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

}
//////////////////////////////////////////////////////////////////////////////////////////
// Function to perform XOR swapping of two vector elements
// XOR Swapping Algorithm doesn't require a temporary variable
// Proof of its correctness is provided in README.md in BUBBLE_SORT directory
// Function works only for integers (due to their bitwise representation)
void XORSwap(std::vector<int> & vec, int first_elem_index, int second_elem_index) {
    int & a = vec[first_elem_index];
    int & b = vec[second_elem_index];

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
//////////////////////////////////////////////////////////////////////////////////////////