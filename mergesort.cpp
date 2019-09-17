#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge



    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    /* your code here */

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

//function 1 body
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){

    if (left == right){
        return;
    }

    int middle = (left + right) / 2; //find  middle of the vector

    mergeSort(a, tmp, left, middle); //Sorts left hand side (including center value)
    mergeSort(a, tmp, middle + 1, right); //Sorts right hand side

    mergeSortedLists(a, tmp, left, middle, right); //Sorts previously sorted lists
}

//function 2 body
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right){

}


