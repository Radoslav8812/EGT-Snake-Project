#include <iostream>

using namespace std;

const int limit = 4;

class safearray
{
   private:
      int arr[limit];

   public:
      int& operator [](int n)
      {
        if(n == limit-1)
        {
           int temp;
           for(int i = 0;i < limit; i++)
           {

              if (arr[n+1] > arr[n])
              {
                 temp = arr[n];
                 arr[n] = arr[n+1];
                 arr[n+1] = temp;
              }
           }
        }
         return arr[n];
         }
};

int main()
{
   safearray sa1;

   for(int j = 0; j < limit; j++)
      sa1[j] = j*10;

   for(int j = 0; j < limit; j++)
   {
      int temp = sa1[j];
      cout << "Element " << j << " is " << temp << endl;
   }

   return 0;
}
