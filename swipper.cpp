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

class DFOC
{
   public:
      virtual double operator()( double x ) = 0;
};

class ClHalf: public DFOC
{
   public:
      virtual double operator()( double x )
      {
         return x/2;
      }
};

class ClSqr: public DFOC
{
   public:
      virtual double operator()( double x )
      {
         return x*x;
      }
};

class ClModulo3: public DFOC
{
   public:
      virtual double operator()( double x )
      {
         return x - (static_cast< int >( x/3 ) )*3;
      }
};


double half (double d)
{
   return d/2;
}

double sqr (double d)
{
   return d*d;
}

double modulo3 (double d)
{
   return d - (static_cast< int >( d/3 ) )*3;
}

typedef double (*dblFp_t)(double);


dblFp_t doubleFuncOutput ( dblFp_t inFunc )
{
   using std::cout;
   using std::endl;
   cout << "Received function does this to 8.0 : " << 
   inFunc ( 8.0 ) << endl;
   return inFunc;
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
/* 
int betterSumAuto(const int *arr[4], const int * end[4])
{
   using std::cout;
   using std::endl;
   int res = 0;
   
   while ( arr < end )
      res += *arr++;
   return res;
}

 */

int main()
{

   using std::cout;
   using std::endl;
   using std::cin;
   using std::string;

   dblFp_t actions[] = {
      half,
      sqr,
      modulo3
   };
   
   dblFp_t p = sqr;
   
   cout << " p is able to square 10 " << p ( 10 ) << endl;
   
   cout << " action 1 on 10 is halfing : " << actions[ 0 ]( 10 ) << endl;
   cout << " action 2 on 10 is squaring : " << actions[ 1 ]( 10 ) << endl;
   cout << " action 3 on 10 is modulo 3 : " << actions[ 2 ]( 10 ) << endl;
   cout << " sqr of 2 : " << doubleFuncOutput ( sqr )( 2 ) << endl;

   ClHalf h;
   ClSqr s;
   ClModulo3 m;
   
   cout << " ClHalf on 10 is halfing : " << h( 10 ) << endl;
   cout << " ClSqr on 10 is squaring : " << s( 10 ) << endl;
   cout << " ClModulo3 on 10 is modulo 3 : " << m( 10 ) << endl;
   
   DFOC *choices[3] {&h, &s, &m};

   cout << " choices 1 on 10 is halfing : " << (*choices[ 0 ])( 10 ) << endl;
   cout << " choices 2 on 10 is squaring : " << (*choices[ 1 ])( 10 ) << endl;
   cout << " choices 3 on 10 is modulo 3 : " << (*choices[ 2 ])( 10 ) << endl;
   
/* DFOC (&reactions)[3] { h,  s,  m};
   
   cout << " reactions 1 on 10 is halfing : " << reactions[ 0 ]( 10 ) << endl;
   cout << " reactions 2 on 10 is squaring : " << reactions[ 1 ]( 10 ) << endl;
   cout << " reactions 3 on 10 is modulo 3 : " << reactions[ 2 ]( 10 ) << endl; */
   
   auto lFHalf = [] ( double x ) { return x/2; };
   auto lFCube = [] ( double x ) { return x*x*x; };
   auto lFModulo7 = [] ( double x ) { return x - (static_cast< int >( x/7 ) )*7; };
   cout << " lFHalf of 23 should half 23 : " << lFHalf ( 23 ) << endl;
   cout << " lFCube of 23 should give cube of  23 : " << lFCube ( 23 ) << endl;
   cout << " lFModulo7 of 23 should be 23 modulo 7: " << lFModulo7 ( 23 ) << endl;
   
   dblFp_t lpHalf = lFHalf;
   dblFp_t lpCube = lFCube;
   dblFp_t lpModulo7 = lFModulo7;

   cout << " lpHalf = lFHalf of 23 should half 23 : " << lpHalf ( 23 ) << endl;
   
   
   dblFp_t lambdaActions[] = {
      lpHalf,
      lpCube,
      lpModulo7
   };
   cout << " lambdaActions 1 on 10 is halfing : " << lambdaActions[ 0 ]( 10 ) << endl;
   cout << " lambdaActions 2 on 10 is Cubing : " << lambdaActions[ 1 ]( 10 ) << endl;
   cout << " lambdaActions 3 on 10 is modulo 7 : " << lambdaActions[ 2 ]( 10 ) << endl;
   cout << " cube of 6 : " << doubleFuncOutput ( lpCube )( 6 ) << endl;
   
   /*
   int x = 5, y = 4;
   cout << " x = " << x << "\t\ty = " << y << endl;
   cout << " Swapping...." << endl;
   swapSlow( x, y );
   cout << " x = " << x << "\t\ty = " << y << endl;
   cout << " Swapping Fast1...." << endl;
   ::swapFast1( x, y );
   cout << " x = " << x << "\t\ty = " << y << endl; 
   */
   
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
/*
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

*/
   
   
   return EXIT_SUCCESS;
}
