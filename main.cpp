#include <iostream>
#include <fstream>

using namespace std;
int n = 0;
unsigned timeInMilliseconds;
int* bubbleSort(int A[]);
unsigned long long int numOperations;
void printResults(int A[]);
void experiment(int n);
int testNumber = 0;


int main() {
    int numberOfTests = 10;
    for (int i = 1; i <= numberOfTests; i++) {
        n = n + 5000;
        experiment(n);
        numOperations = 0;
        experiment(n);
        numOperations = 0;
        experiment(n);
        numOperations = 0;
        experiment(n);
        numOperations = 0;
        experiment(n);
        numOperations = 0;
        testNumber = 0;
    }
}

void experiment(int n) {
    testNumber++;
    int A[n];
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }
    random_shuffle(&A[0], &A[n]);
    printResults(bubbleSort(A));
}

int* bubbleSort(int A[]) {
    clock_t startTime = clock();
    int count = n - 1;
    bool sFlag = true;
    while (sFlag == true) {
        sFlag = false;
        for (int i = 0; i < n ; i++) {
        	if (A[i + 1] < A[i]) {
                numOperations++;
        		int p = A[i];
        		A[i] = A[i + 1];
        		A[i + 1] = p;
        		sFlag = true;
        		count = count - 1;
        	}
        }
    }
    clock_t timeElapsed = clock() - startTime;
    timeInMilliseconds = timeElapsed / (CLOCKS_PER_SEC/1000);
    return A;
}

void printResults(int A[]) {
    for(int i = 0; i < n; i++){
        cout << "Number at " << i << ":" << A[i] << "\n" << endl;
    }
    cout << "Length of array: " << n << "\n" << endl;
    cout << "Time taken: " << timeInMilliseconds << "\n" << endl;
    cout << "Number of operations: " << numOperations << "\n" << endl;
    cout << "Number of test: " << testNumber << "\n" << endl;

    ofstream myfile;
    myfile.open ("Results.csv", ios_base::app);
    myfile << "Length of array: \n" << n << "\n";
    myfile << "Number of test: \n" << testNumber << "\n";
    myfile << "Time taken: \n" << timeInMilliseconds << "\n";
    myfile << "Number of operations: \n" << numOperations << "\n";
    myfile.close();
}
