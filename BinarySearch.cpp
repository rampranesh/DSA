/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

int
binarySearch (std::vector < int >&toSearch, int x)
{
  int low = 0, high = toSearch.size (), mid = 0;

  while (low <= high)
    {
      mid = (low + high) / 2;
      if (toSearch[mid] == x)
	return mid;
      else if (toSearch[mid] > x)
	high = mid - 1;
      else if (toSearch[mid] < x)
	low = mid + 1;
    }
  return -1;
}

int
binarySearchRecursive (std::vector < int >&toSearch, int low, int high,
		       int toFind)
{
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (toSearch[mid] == toFind)
    return mid;
  else if (toSearch[mid] > toFind)
    binarySearchRecursive (toSearch, low, mid - 1, toFind);
  else if (toSearch[mid] < toFind)
    binarySearchRecursive (toSearch, mid + 1, high, toFind);
}

int
main ()
{
  std::vector < int >searchEntries
  {
  1, 2, 4, 5, 3, 6};
  std::sort (searchEntries.begin (), searchEntries.end ());
  cout << binarySearch (searchEntries, 2) << endl;
  cout << binarySearchRecursive (searchEntries, 0, searchEntries.size (), 2);
  return 0;
}
