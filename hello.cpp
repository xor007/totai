/** @hello.cpp - Test Mingw Compiler
* This is just a test that the compiler works, type hello or ./hello to execute
*/

//#include <cstdlib>
#include <iostream>

/** @brief
* Entry point for professional hello world
* @return only `EXIT_SUCCESS` (int)
*/

void jfoXit(void)
{
    std::cout << "Say why?" << std::endl;
}

int main()
{
    using std::cout;
    using std::endl;
    cout << "Hello World new" << endl;
    std::operator << ( std::operator << ( cout,"Ho\n" ), "Ha\n" );
    atexit (jfoXit);
    
   unsigned u = 11; // start the loop one past the first element we want to print
   while (u > 0) {
      --u; // decrement first, so that the last iteration will print 0
      std::cout << u << std::endl;
   }
   return EXIT_SUCCESS;
}
