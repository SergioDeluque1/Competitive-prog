#include <iostream>
#include <fstream>
#include <string>

std ::string FileName = "numbers10.txt";

std:: ifstream DataFile(FileName);
int main() {
    int n = 10; //number of elements in the array
    int A[n]; //Declare array of integers
}
for (int i = 0; i<n; i++){
    DataFile >> A[i];
    //print the value of A[i]
    std:: cout << A[i] << endl;
}
DataFile.close();

int MaxVal = A[0];
for (int i = 1; i<n; i++){
    if A[i] == MaxVal;
}
