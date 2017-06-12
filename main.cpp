#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector <int> findMostFrequent (std::vector <int> ints, int n)
{
    map <int,int>  countNumbers; /// key - number , value - kolko puti se sreshta vuv vektora
    for (int i = 0; i < (int)ints.size(); i++)
    {
        int number = ints[i];
        if (countNumbers.find(number) == countNumbers.end())
        {
            countNumbers[number] = 1;
        }
        else
        {
            countNumbers[number] = countNumbers[number] + 1;
        }
    }
    /// 23 -3, 56-1, 77-3, 44-1, 55-1 , 5-1 ....
    int maxCount = 0;
    map <int,int>:: iterator it;
    for (it = countNumbers.begin(); it != countNumbers.end(); it++)
    {
        int val =  it -> second; /// broikata
        if (val > maxCount)
        {
            maxCount = val;
        }
    }
 /// prehvurlqme v drug map chislata , koito se sreshtat v maxCount !:

 vector <int> numbersMaxCount;
    for (it = countNumbers.begin(); it != countNumbers.end(); it++)
    {
        int key = it -> first;
        int val =  it -> second;
        if (val == maxCount)
        {
            numbersMaxCount.push_back(it -> first);
        }
    }
    vector <int> result;

    for (int i =0; i < n; i++)
    {
        result.push_back(numbersMaxCount[i]);
    }

    return result;
}


int main()
{


   ///3ti primer
    int d[15] = {23, 56, 77, 23, 44, 55, 77, 23, 5, 8, 9, 0, 77, 9, 9};
    vector <int> digits (d, d + 15);

    vector <int> nDigits = findMostFrequent(digits, 3); /// koi sa 3te ot nai 4esto sreshtani cifti .
        for (int i = 0; i < (int)nDigits.size(); i++)
        {
            cout << nDigits.at(i) << " ";
        }

    return 0;
}
