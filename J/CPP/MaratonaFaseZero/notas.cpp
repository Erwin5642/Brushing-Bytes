#include <iostream>
using namespace std;
//string
#include <string>

//map
#include <map>

//stack
#include <stack>

//algorithm
#include <algorithm>

// To sort the given vector.
sort(first_iterator, last_iterator)
//Retorna void 

// To sort the given container/vector in descending order
sort(first_iterator, last_iterator, greater<int>())
//Retorna void 

// To reverse a vector. ( if ascending -> descending  OR  if descending -> ascending) 
reverse(first_iterator, last_iterator) 
//Retorna void 

// To find the maximum element of a vector.
max_element (first_iterator, last_iterator)
//Retorna ponteiro para o maior elemento

// To find the minimum element of a vector.
min_element (first_iterator, last_iterator)
//Retorna ponteiro para o menor elemento

// Does the summation of vector elements
accumulate(first_iterator, last_iterator, initial value of sum) 
//Retorna o valor da soma dos elementos

//To count the occurrences of x in vector.
count(first_iterator, last_iterator,x) 
//Retorna o numero de vezer que x aparece

// Returns an iterator to the first occurrence of x in vector and points to 
//last address of vector ((name_of_vector).end()) if element is not present in vector.
find(first_iterator, last_iterator, x) 

// Tests whether x exists in sorted vector or not.
binary_search(first_iterator, last_iterator, x) 
//Retorna falso ou verdadeiro

// returns an iterator pointing to the first element in 
//the range [first,last) which has a value not less than ‘x’.
lower_bound(first_iterator, last_iterator, x) 

// returns an iterator pointing to the first element 
// in the range [first,last) which has a value greater than ‘x’. 
upper_bound(first_iterator, last_iterator, x) 


//          Some Manipulating Algorithms

// This erases selected element in vector and shifts and resizes the vector elements accordingly.
arr.erase(position to be deleted) 

// This erases the duplicate occurrences in sorted vector in a single line.
arr.erase(unique(arr.begin(),arr.end()),arr.end()) 

// It returns the distance of desired position from the first 
// iterator.This function is very useful while finding the index. 
distance(first_iterator,desired_position) 

