// Bubble Sort
#include <iostream>
#include <vector>

int BubbleSort(std::vector<int> & vec);

int main()
{
    std::vector<int> vec {7, 5, 6, 3, 4, 2, 1};
    std::cout << "Before Bubble Sort: " << std::endl;
    for (auto elem : vec) {
        std::cout << elem << " ";
    } 
    std::cout << "\nNumber of comparisons: " << BubbleSort(vec);
    std::cout << "\nAfter Bubble Sort: " << std::endl;
    for (auto elem : vec) {
        std::cout << elem << " ";
    } 
}

int BubbleSort(std::vector<int> & vec)
{
    int temp;
    int n = 0;
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 1; j < vec.size() - i; ++j) {
            if (vec[j-1] > vec[j]) {
                temp = vec[j-1];
                vec[j-1] = vec[j];
                vec[j] = temp;
            }
            ++n;
        }
    }
    return n;
}