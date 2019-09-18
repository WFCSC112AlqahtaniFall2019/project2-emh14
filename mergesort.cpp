/* Ethan Harrison
 * CSC 112
 * Project 2
 * MergeSort
 * */

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
    cout << "Enter integer for seed: " << endl;
    cin >> seed;
    cout << "Enter integer for vector length: " << endl;
    cin >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    cout << endl << "Beginning Unit Test." << endl;
    vector<int> unit_v = {5, 4, 1, 2, 3}; //unit test main vector

    //print test vector
    cout << "Unit Test Original Vector: " << endl;
    for(int i = 0; i < unit_v.size(); i++) {
        cout << unit_v.at(i) << '\t';
    }

    vector<int> unit_t = {0, 0, 0, 0, 0}; //unit test temporary vector
    mergeSort(unit_v, unit_t, 0, unit_v.size()-1);
    for(int i = 1; i < unit_v.size(); i++) {
        assert(unit_v.at(i-1) <= unit_v.at(i));
    }

    //print test vector after sort
    cout << endl << "Expecting: " << endl << "1\t2\t3\t4\t5" << endl << "Got: " << endl;
    for(int i = 0; i < unit_v.size(); i++) {
        cout << unit_v.at(i) << '\t';
    }

    cout << endl << "End of Unit Test." << endl << endl;

    // initialize and print input
    cout << "Original vector: " << endl;
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t, 0, v.size()-1);

    // print output
    cout << "Sorted vector: " << endl;
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

    int tempIndex = left; //Used populate temporary vector

    //Assigning temp variables for left side
    int l = left;
    int lEnd = middle;

    //Assigning temp variables for right side
    int r = middle + 1;
    int rEnd = right;

    //Iterate
    while (l <= lEnd && r <= rEnd){
        if(a.at(l) <= a.at(r)){//if the left value is less, put it in new vector
            tmp.at(tempIndex) = a.at(l);
            tempIndex++;
            l++;
        }
        else{//if the right value is less, put it in new vector
            tmp.at(tempIndex) = a.at(r);
            tempIndex++;
            r++;
        }
    }

    //Copy the vector until it reaches the end
    //Since one of the following will have already hit the end, only one while loop will run
    while (l <= lEnd){
        tmp.at(tempIndex) = a.at(l);
        tempIndex++;
        l++;
    }
    while(r <= rEnd){
        tmp.at(tempIndex) = a.at(r);
        tempIndex++;
        r++;
    }

    //Take data from temp vector and put it back into a
    tempIndex = left; //Reset index
    while (tempIndex <= right){
        a.at(tempIndex) = tmp.at(tempIndex);
        tempIndex++;
    }
}

