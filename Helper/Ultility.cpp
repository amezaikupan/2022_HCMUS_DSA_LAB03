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