#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

/* 
- overloaded cast operator
- initializer list
- copy constructor
- assignment operator
- destructor
- const and reference members
- constexpr
*/
constexpr int INITIAL_TOTAL = 0;
constexpr int ASPECTS_DEFAULT = 5;

using std::cout;
using std::endl;
using std::cin;

class Thing
{
   //friend declarations for Thing
   friend std::string concatNames( Thing & inT );
   
   //static members of thing
   static int numberOfThings;
   
   //private members of Thing
   std::string label;
   const int parts = INITIAL_TOTAL;
   const int len;
   std::vector<std::string> names;
   //std::initializer_list x;
   //public members of Thing
   public:
      Thing() ;
      explicit Thing( const char *inN ) ;
      Thing( std::initializer_list<std::string> initNames ) ;
      Thing( const char *inN, std::initializer_list<std::string> initNames ) ;
      Thing( const Thing & rhs ): Thing() {
         cout << "Copying a Thing labelled "<< label << "..." << endl;
      }
      Thing & operator = (const Thing & rhs)
      {
         cout << " assignment copy operator called on " << label << " ..." << endl;
         if ( this == &rhs )
            return *this;
         cout << " guard not true " << label << " ..." << endl;
         label = rhs.label;
         names = rhs.names;
         return *this;
      }
      Thing & operator = (Thing && rhs)
      {
         cout << " Move assignment copy operator called on " << label << " ..." << endl;
         if ( this == &rhs )
            return *this;
         cout << " guard not true " << label << " ..." << endl;
         label = rhs.label;
         names = rhs.names;
         rhs.label.clear();
         rhs.names.clear();
         return *this;
      }
      Thing(Thing && rhs ): Thing()
      {
         cout << "Moving a Thing labelled "<< label << "..." << endl;
         rhs.label.clear();
         rhs.names.clear();
      }
      std::string getLabel(){    std::string res; res = label; return res;}
      ~Thing();
      void printNames();
      
};

int Thing::numberOfThings = INITIAL_TOTAL;

//declaration of non member catNames
std::string concatNames( Thing & inT )
{
   std::string res = "Names :" ;
   for ( auto n = inT.names.begin(); n != inT.names.end(); ++n )
      res += *n + "," ;
   return res;
}


Thing::Thing( const char *inN ): label(inN), len(6)
{
   cout << " Default Constructor for Thing labelled " << label << " is called ..." << "there are " << numberOfThings << "things" << endl;
   numberOfThings++;
}

Thing::Thing( std::initializer_list<std::string> initNames ): Thing ("Initialized_Thing")
{
   cout << " Default Constructor for Thing labelled " << label << " is called ..." << "there are " << numberOfThings << "things" << endl;
   cout << " list initializing " << label << " is called ..." << "there are " << numberOfThings << "things" << endl;
   for ( auto n = initNames.begin(); n != initNames.end(); ++n )
      names.push_back(*n);
}

Thing::Thing( const char *inN, std::initializer_list<std::string> initNames ): Thing (inN)
{
   cout << " list initializing " << label << " is called ..." << endl;
   for ( auto n = initNames.begin(); n != initNames.end(); ++n )
      names.push_back(*n);

}

Thing::Thing(): label("no_name"), len(6)
{
   cout << " Default Constructor for Thing labelled " << label << " is called ..." << "there are " << numberOfThings << "things" << endl;
   numberOfThings++;
}

Thing::~Thing()
{
   cout << " Default Destructor for Thing labelled " << label << " is called ..." << "there are " << numberOfThings << "things" << endl;
   numberOfThings--;
}

void Thing::printNames()
{
   cout << "List of names in this thing( " << label << " ): "  << "there are " << numberOfThings << "things" << endl;
   for ( auto n = names.begin(); n != names.end(); ++n )
      cout << *n << endl;
}


int main()
{
   Thing d = Thing( "dog" );
   Thing r = d;
   Thing s { "onr", "dfhtwo", "thvhree", "fsdfhour" };
   Thing m = static_cast<Thing>( "man" );
   
   //testing move
   m = std::move(s);
   cout << "man is now a : " << m.getLabel() << endl;
   cout << "m:" << concatNames ( m ) << endl;
   cout << "s:" << concatNames ( s ) << endl;
   
   return EXIT_SUCCESS;
}
