//Zerosum.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

int main(){
    int FileSize = 100;
    string FileName = "Zerosum.txt";
    int numbers[FileSize];
    cout << "hello world\n"; 


    ifstream MyFile(FileName); //read Zerosum.txt
    for (int i = 0; i<FileSize; i++){
        MyFile >> numbers[i];
        cout << numbers[i] << endl;

    }
    MyFile.close();
    //start timer
    auto start = chrono :: high_resolution_clock::now();

    // find triplets
    for (int i = 0; i < FileSize-3; i++) {
        for(int j = i+1; j < FileSize-2; j++) {
            for (int k = j+1; k < FileSize; k++){
                if (numbers[i] == numbers[j]) {
                    cout << "Zero sum pair: (" << numbers[i] << numbers[j] << ")" << endl;
                }
            }
        }
    }
//stop clock & report runtime
auto stop = chrono :: high_resolution_clock::now();
auto duration = chrono :: duration_cast<chrono::microseconds>(stop - start);
cout << "running time" << duration.count() << "ms" << endl;
}