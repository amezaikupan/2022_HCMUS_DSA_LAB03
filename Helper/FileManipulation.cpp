#include <string>
#include <string.h>
#include <fstream>

using namespace std;

//Reading data from input
int* readData(char* input, int &n){
    //Read input file
    ifstream file (input);
    
    //check if filename is valid
    if(file.fail()) return NULL;

    //Get data set's size
    string line = "";
    file >> line;

    //Make data set
    n = stoi(line);
    int* a = new int[n];

    //Read data set data
    int i = 0;
    while(file >> line){
        a[i] = stoi(line);
        i++;
    }
    
    return a;
}

//Writing sorted data to output
void writeData(string input, int* a, int n){
    ofstream of (input);
    
    of << n << endl;

    int i = 0;
    while(i < n){
        of << a[i] << " ";
        i++;
    }

    of.close();
}
