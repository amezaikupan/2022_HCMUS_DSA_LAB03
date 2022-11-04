#include <unordered_map>
#include <string>

using namespace std;

//Swap integer a and b
void swap(int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
}

//Make duplication of array a
int* copyData(int* a, int* &b, int n)
{
    b = new int[n];
    for(int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    return b;
}

//Get algorithm from command - return id of that algorithm
int getAlgorithm(char* algorithm){
    string al (algorithm);

    unordered_map <string, int> aList {{"selection-sort", 1}, {"insertion-sort", 2}, 
    {"bubble-sort", 3},
    {"shaker-sort", 4}, {"shell-sort", 5}, 
    {"heap-sort", 6}, {"merge-sort", 7}, 
    {"quick-sort", 8}, {"counting-sort", 9}
    , {"radix-sort", 10}, {"flash-sort", 11}};

    return aList[al];
}

//Get order from command - return id of that order
int getOrder(char* order){
    string o (order);

    unordered_map<string, int> oList {{"-rand", 0}, {"-sorted", 1}, {"-rev", 2}, {"-nsorted", 3}};

    //If order is invalid then isn not in map
    if(oList.count(o) < 1) return -1;
    
    return oList[o];
}

string getOrderName(int order){
    unordered_map<int, string> oList {{0, "Randomize"}, {1, "Sorted"}, {2, "Reversed"}, {3, "Nearly Sorted"}};
    return oList[order];
}

string getAlgorithmName(int algorithm)
{
    unordered_map <int, string> aList {{1, "selection-sort"}, {2, "insertion-sort"}, 
    {3, "bubble-sort"},
    {4, "shaker-sort"}, {5, "shell-sort"}, 
    {6, "heap-sort"}, {7, "merge-sort"}, 
    {8, "quick-sort"}, {9,"counting-sort"}
    , {10, "radix-sort"}, {11, "flash-sort"}};

    return aList[algorithm];
}