#include <iostream>

using namespace std;

int max(int,int);
void print(int);

int main()
{
    int a , b;
    cout << " Please enter numbers: " << endl;
    cin >> a >> b;
    int result = max (a, b);
    print (result);

    return 0;
}
int max(int first, int second)
{
    int result;
    if(first > second)
    {
        result = first;
    }
    else
    {
        result = second;
    }
    return result;
}
void print(int number)
{
    cout << number << endl;
}


