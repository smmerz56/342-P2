// An IntSet object takes in integers and creates a bool array. The size of
// the array will the largest of the integers + 1.
#include "intset.h"
#include <assert.h>

// --------------------------------------------------------------------------
// Constructor
// Defualt constructor for IntSet class
IntSet::IntSet(int a, int b, int c, int d, int e)
{
   size = a >= b ? a : b;
   size = c > size ? c : size;
   size = d > size ? d : size;
   size = e > size ? e : size;

   if(size < 0) {
      size = 0;
      arrayPtr = new bool[size + 1];
      for(int i = 0; i < size + 1; i++) {
         arrayPtr[i] = false;
      }
   } else {
      arrayPtr = new bool[size + 1];
      for(int i = 0; i < size + 1; i++) {
         arrayPtr[i] = false;
      }
      if(a >= 0) {
         arrayPtr[a] = true;
      }
      if(b >= 0) {
         arrayPtr[b] = true;
      }
      if(c >= 0) {
         arrayPtr[c] = true;
      }
      if(d >= 0) {
         arrayPtr[d] = true;
      }
      if(e >= 0) {
         arrayPtr[e] = true;
      }
   }
}
// --------------------------------------------------------------------------
// Copy constructor
// Copy constructor for IntSet class
IntSet::IntSet(const IntSet& setToCopy)
{
   size = setToCopy.size;
   arrayPtr = new bool[size + 1];

   for(int i = 0; i < size + 1; i++) {
      arrayPtr[i] = setToCopy.arrayPtr[i];
   }
}
// --------------------------------------------------------------------------
// Destructor
// Destructor for IntSet class
IntSet::~IntSet()
{
   delete[] arrayPtr;
   arrayPtr = nullptr; 
}
// --------------------------------------------------------------------------
// isInSet
// Checks to see if value is in the set
bool IntSet::isInSet(int x)
{
   if(x >= 0 && x < size + 1) {
      return arrayPtr[x];
   }
   return false;
}
// --------------------------------------------------------------------------
// IsEmpty
// Checks to see if set is empty
bool IntSet::isEmpty()
{
   for(int i = 0; i < size + 1; i++) {
      if(arrayPtr[i] == true) {
         return false;
      }
   }
   return true;
}
// --------------------------------------------------------------------------
// Remove
// Removes the value from the set
bool IntSet::remove(int a)
{
   if(a >= 0 && a <= size) {
      arrayPtr[a] = false;
      return true;
   } else {
      return false;
   }
}

// --------------------------------------------------------------------------
// Insert
// Inserts the value in the set
bool IntSet::insert(int a)
{
   if(a >= 0) {
      if(a < size) {
         arrayPtr[a] = true;
      } else {
         bool* temp = arrayPtr;
         arrayPtr = new bool[a + 1];

         for(int i = 0; i < size + 1; i++) {
            arrayPtr[i] = temp[i];
         }
         for(int j = size + 1; j < a + 1; j++) {
            arrayPtr[j] = false;
         }
         size = a;
         arrayPtr[a] = true;
         delete[] temp;
         temp = nullptr;
      }
      return true;
   } else {
      return false;
   }
}
// --------------------------------------------------------------------------
// operator==
// Determines if the two sets are equal
bool IntSet::operator==(const IntSet& rightSide) const
{
   if(size > rightSide.size || size < rightSide.size) {
      return false;
   } else {
      for(int i = 0; i < size + 1; i++) {
         if(arrayPtr[i] != rightSide.arrayPtr[i]) {
            return false;
         }
      }
   }
   return true;
}

// --------------------------------------------------------------------------
// operator!=
// Bool inequality operator determines if the two sets are not equal
bool IntSet::operator!=(const IntSet& rightSide) const
{
   if(size > rightSide.size || size < rightSide.size) {
      return true;
   } else {
      for(int i = 0; i < size + 1; i++) {
         if(arrayPtr[i] != rightSide.arrayPtr[i]) {
            return true;
         }
      }
   }
   return false;
}

// --------------------------------------------------------------------------
// operator-=
// Overloaded difference operator finds the difference of two sets and
// assigns the values to the first set
IntSet& IntSet::operator-=(const IntSet& rightSide)
{
   *this = *this - rightSide;

   return *this;
}

// --------------------------------------------------------------------------
// operator*=
// Overloaded intersection operator finds the common values of two sets 
// and assigns the values to the first set
IntSet& IntSet::operator*=(const IntSet& rightSide)
{
   *this = *this * rightSide;

   return *this;
}

// --------------------------------------------------------------------------
// operator+=
// Overloaded sum operator combines two sets and assigns the values to the
// first set
IntSet& IntSet::operator+=(const IntSet& rightSide)
{
   *this = *this + rightSide;

   return *this;
}
// --------------------------------------------------------------------------
// operator-
// Overloaded difference operator returns the difference of two sets
IntSet IntSet::operator-(const IntSet& rightSide) const
{
   IntSet difference;

   delete[] difference.arrayPtr;
   difference.size = size;

   difference.arrayPtr = new bool[difference.size + 1];

   for(int i = 0; i < difference.size + 1; i++) {
      difference.arrayPtr[i] = false;
   }

   for(int j = 0; j < difference.size + 1; j++) {
      if(j > rightSide.size + 1) {
         if(arrayPtr[j] == true) {
            difference.arrayPtr[j] = true;
         }
      } else {
         if(arrayPtr[j] == true && rightSide.arrayPtr[j] == false) {
            difference.arrayPtr[j] = true;
         }
      }
   }
   return difference;
}
// --------------------------------------------------------------------------
// operator*
// Overloaded itersection operator returns the common values of two sets
IntSet IntSet::operator*(const IntSet& rightSide) const
{
   IntSet common;

   delete[] common.arrayPtr;
   common.size = size >= rightSide.size ? rightSide.size : size;

   common.arrayPtr = new bool[common.size + 1];

   for(int i = 0; i < common.size + 1; i++) {
      common.arrayPtr[i] = false;
   }

   for(int j = 0; j < common.size + 1; j++) {
      if(arrayPtr[j] == rightSide.arrayPtr[j]) {
         common.arrayPtr[j] = arrayPtr[j];
      }
   }
   return common;
}

// --------------------------------------------------------------------------
// operator=
// Overloaded assignment operator assigns one set to another
IntSet& IntSet::operator=(const IntSet& rightSide)
{

   if(this != &rightSide) {

      delete[] arrayPtr;

      size = rightSide.size;
      arrayPtr = new bool[size + 1];

      for(int i = 0; i < size + 1; i++) {

         arrayPtr[i] = rightSide.arrayPtr[i];
      }
   }

   return *this;
}
// --------------------------------------------------------------------------
// operator+
// Overloaded union operator returns the union of two sets
IntSet IntSet::operator+(const IntSet& rightSide) const
{
   IntSet combined;

   // delete memory
   delete[] combined.arrayPtr;

   combined.size = size >= rightSide.size ? size : rightSide.size;

   combined.arrayPtr = new bool[combined.size + 1];

   for(int i = 0; i < combined.size + 1; i++) {
      combined.arrayPtr[i] = false;
   }

   for(int k = 0; k < size + 1; k++) {
      if(arrayPtr[k] == true) {
         combined.arrayPtr[k] = true;
      }
   }

   for(int j = 0; j < rightSide.size + 1; j++) {
      if(rightSide.arrayPtr[j] == true) {
         combined.arrayPtr[j] = true;
      }
   }

   return combined;
}
// --------------------------------------------------------------------------
// operator<<
// Overloaded output operator displays the set
ostream& operator<<(ostream& output, const IntSet& set)
{
   output << '{';
   for(int i = 0; i < (set.size) + 1; i++) {
      if(set.arrayPtr[i] == true) {
         output << ' ' << i;
      }
   }

   output << '}';

   return output;
}
// --------------------------------------------------------------------------
// operator>>
// Overloaded input operator inputs numbers into a set
istream& operator>>(istream& input, IntSet& set)
{
   int x = 0;
   input >> x;

   while(x != -1) {
      set.insert(x);
      input >> x;
   }
   return input;
}
