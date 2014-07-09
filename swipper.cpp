#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>

void swapSlow (int & a, int &b)
{
    int tmp1 = a, tmp2 = b;
    a = tmp2;
    b = tmp1;
}

void swapFast1 (int & a, int &b)
{
    int tmp1 = a;
    a = b;
    b = tmp1;
}


namespace {
void swapFast1 (int & a, int &b)
{
    int tmp1 = a;
    a = b;
    b = tmp1;
}
}

int sum(int (*b)[4])
{
   using std::cout;
   using std::endl;
   int res = 0;
   
   for (int i=0; i<3; ++i)
      for (int j = 0; j<4; ++j)
         {
            //cout << b[i][j] << endl; 
            res += b[i][j];
         }
   return res;
}

/* int sumAuto(int b[][4])
{
   using std::cout;
   using std::endl;
   int res = 0;
   
   for (auto &i : *b)
      for (auto &j : i)
         {
            cout << b << endl; 
            res += b[i][j];
         }
   return res;
} */

int betterSumAuto(const int *arr[4], const int * end[4])
{
   using std::cout;
   using std::endl;
   int res = 0;
   
   while ( arr < end )
      res += *arr++;
   return res;
}



int main()
{

   using std::cout;
   using std::endl;
   using std::cin;
   using std::string;
   int x = 5, y = 4;
   cout << " x = " << x << "\t\ty = " << y << endl;
   cout << " Swapping...." << endl;
   swapSlow( x, y );
   cout << " x = " << x << "\t\ty = " << y << endl;
   cout << " Swapping Fast1...." << endl;
   ::swapFast1( x, y );
   cout << " x = " << x << "\t\ty = " << y << endl;

   /*
   * testing automatic iteration in c++11
   */
   // int arr[100] {1,2,3,4,5,6};
   // for (auto n : arr)
        // cout<<n<<endl;
   // std::string inStr;
   // cout << "please enter your surname :" << endl;
   // cin >> inStr;
   // for (auto &c : inStr)
        // c = toupper(c);
   // cout << "Your surname is : " << inStr << endl;
    
   /*
   * see the impact of sizeof in initialization: pointer to an array is array of arrays
   */
   // char a[4] = {'A','B','C','\0'};
   // char  (*p)[4] = &a; 
   
   // cout << " Value followed by random memory : " << endl;
   // for (int i=0; i<3;++i)
      // cout << p[i] << endl;
      
   // cout << " Actual value : " << *p << endl;
   
   // cout << " Actual value : " << p[0][2] << endl;

   /* arrays of arrays and dereferencing, sizeof continued...
   */
   int b[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}
   };
   
   //cout << "The numbers are :" << endl;
   int s = sum( b );
   cout << "Total is :" << s;
   
   int r = betterSumAuto( b, b + 3 );
   cout << "Other total :" << r;
   
   return EXIT_SUCCESS;
}
