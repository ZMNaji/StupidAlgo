#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>
#include <string>



// Return Random Value Based On Given Range
int returnRandomValue(int min_range, int max_range) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min_range, max_range);
    int randomValue = distribution(gen);
    return randomValue;
}


// Retun Sorted List
std::vector<int> returnSortedList(const std::vector<int>& unorderedList) {
    std::vector<int> sortedList = unorderedList; 
    std::sort(sortedList.begin(), sortedList.end()); 
    return sortedList; 
}


// Print Vector In Terminal Based On Given Vector
void printList(const std::vector<int>& vector) {
    std::cout << "[";

    if (!vector.empty()) {
        std::cout << vector[0];
        for (size_t i = 1; i < vector.size(); ++i) {
            std::cout << ", " << vector[i];
        }
    }

    std::cout << "]" << std::endl;
}


// BozoSort Algo :) 
void bozoSort(std::vector<int> unorderdeList){
    std::vector<int> orderedList = returnSortedList(unorderdeList);
    int counter = 0;
    bool areEqual = false;

    auto startingTimer = std::chrono::high_resolution_clock::now();
    while(!areEqual) {
        int i = returnRandomValue(0, unorderdeList.size() - 1);
        int j = returnRandomValue(0, unorderdeList.size() - 1);

        if (i != j) {
            std::swap(unorderdeList[i], unorderdeList[j]);
            counter ++;
        }
        
        for (int k = 0; k < unorderdeList.size(); k++){
            if (unorderdeList[k] != orderedList[k]) {
                break;
            } 
            if (k == unorderdeList.size() - 1) {
                areEqual = true;
            }
        }   

    printList(unorderdeList);
    }

    
    auto endingTimer = std::chrono::high_resolution_clock::now();
    // Calculate Amount of seconds it took till finished
    std::chrono::duration<double> totalSeconds = endingTimer - startingTimer;
    double seconds = totalSeconds.count();

    std::cout << "Sorted in " << counter << " iterations" << std::endl;
    std::cout << "Sorted in " << seconds << " seconds" << std::endl;

}



int main(){
    std::vector<int> unorderdList = {2,3,4,1,22,1,23,1,};
    bozoSort(unorderdList);
    return 0;
}


