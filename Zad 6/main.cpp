#include <iostream>
#include <map>
using namespace std;
///6. Write a program that finds in a given array of integers how
///many times each of them presents.
///Example: array = {3, 4, 4, 2, 3, 3, 4, 3, 2}
///2 ->2 times
///3 -> 4 times
///4-> 3 times

int main(){
	map< int , int , less < int > >counters;
	//key:: arr el         value : how many times
	// 4 -20

	map<int , int>::iterator it;
	int arr[] = {2,5,79,66,55,2,66,5,66,1};

	for(int i = 0; i < 10; i++){
		int key =arr[i];
		it = counters.find(key);
		if(it != counters.end()){

		counters[key]++;
		}else{

			counters[key] = 1;
		}
	}
	cout <<"Number " <<" "<< "Occurences"<< endl;
	for(it = counters.begin(); it!=counters.end(); it++){
		cout << it->first <<"\t "<< it->second << endl;
	}

	cout << endl;
   return 0;
}
