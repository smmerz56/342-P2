// An IntSet object takes in integers and creates a bool array. The size
// of the array will the largest of the integers + 1.

#ifndef INTSET_H
#define iNTSET_H
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// IntSet class:  wrapper for an bool array to keep track of integers with
//    true and false values.
//    - allows inserting and removing of values
//    - allows checking to see if values are in the array or if array is
//      empty.
//    - can find the union, intersection, difference of the sets
//
// Implementation and assumptions:
//    - The user must only enter numbers.
//    - If the user enters negative numbers into a set, they will be
//      ignored.
//    - Size defualts to 1 if user enters only negative/no numbers.
//    - Array elements are dfaulted to false.
//    - Since I havent heard back on the formatting in my assigment 1, Im
//      assuming that by not selecting "use tabs in indentation," setting
//      "columns per indentation level" and "columns per tab character" to
//      3, then using auto-format, my formatting is what you are looking
//      for.
//---------------------------------------------------------------------------

class IntSet
{
   // overloaded <<
   // prints the array
   friend ostream& operator<<(ostream&, const IntSet&);
   // overloaded >>
   // takes in as many ints the user enters until they enter -1
   friend istream& operator>>(istream&, IntSet&);

   public:
   // constructors
   IntSet(int a = -1, int b = -1, int c = -1, int d = -1, int e = -1);
   IntSet(const IntSet&); // copy constructor
   ~IntSet();             // destructor

   bool insert(int a);
   bool remove(int a);
   bool isEmpty();
   bool isInSet(int x);
   // arithmetic operators
   IntSet operator+(const IntSet&) const;
   IntSet operator*(const IntSet&)const;
   IntSet operator-(const IntSet&) const;
   // assignment operators
   IntSet& operator=(const IntSet&);
   IntSet& operator+=(const IntSet&);
   IntSet& operator*=(const IntSet&);
   IntSet& operator-=(const IntSet&);
   // boolean comparison operators
   bool operator==(const IntSet&) const;
   bool operator!=(const IntSet&) const;

   private:
   int size;
   bool* arrayPtr;
};
#endif