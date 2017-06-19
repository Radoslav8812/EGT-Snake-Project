#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	map<int, int, less<int> > counters;
	map<int, int>::iterator it;

	int arr[] = { 2, 5, 79, 66, 55, 2, 66, 5, 66, 1 };

	vector<int> occur(&arr[0], &arr[0] + 10);

	for (int i = 0; i < 10; i++) {
		int key = arr[i];
		it = counters.find(key);
		if (it != counters.end()) {

			counters[key]++;
		} else {

			counters[key] = 1;
		}

	}
	vector<int>::iterator itv;
	cout << "Number " << " " << "Occurences" << endl;
	for (it = counters.begin(); it != counters.end(); it++) {

		cout << it->first << "\t " << it->second << endl;
	}
	for (unsigned int i = 0; i < occur.size(); i++) {
		if (counters[occur[i]] % 2 != 0) {
			occur.erase(occur.begin() + i);
			i--;
		}
	}
	for ( unsigned int i = 0; i < occur.size(); i++) {
		cout << occur[i] << " ";

	}

	return 0;
}
