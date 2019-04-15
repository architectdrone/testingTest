
#include <stdio.h>
#include <string>
#include "test.h"
#include "LinkedListOfInts.h"
#include <iostream>
using namespace std;

int message(bool passed, string msg)
{
  int toReturn;
  if (passed == true)
  {
    cout << "[ ] ";
    toReturn = 0;
  }
  else
  {
    cout << "[X] ";
    toReturn = 1;
  }
  cout << msg << endl;
  return toReturn;
}

void TestSuite::testAll()
{
  printf("Hello! Items marked [ ] succeeded, and the statement associated with them is true, whereas [X] did not succeed.");
  int numErrors = 0;
  numErrors+=testInit();
  numErrors+=testAddBack();
  numErrors+=testAddFront();
  numErrors+=testAddMultiple();
  numErrors+=testRemoving();
  numErrors+=testOrdering();
  cout << "There were " << numErrors << " errors." << endl;
}

int TestSuite::testInit()
{
  printf("\nPerforming tests on new list.\n");
  LinkedListOfInts myList;

  int toReturn = 0;

  bool emptyOnInit = myList.isEmpty();
  toReturn+=message(emptyOnInit, "The list is empty when it is initialized, according to .isEmpty().");
  bool sizeIsZeroOnInit = (myList.size() == 0);
  toReturn+=message(sizeIsZeroOnInit, "The list has zero elements when it is initialized, according to .size().");
  return toReturn;
}

int TestSuite::testAddBack()
{
  printf("\nPerforming tests on adding one element to back of the list.\n");
  LinkedListOfInts myList;
  myList.addBack(3);

  int toReturn = 0;

  bool notEmptyOnAdd = (!(myList.isEmpty()));
  toReturn+=message(notEmptyOnAdd, "The list is not empty when an element is added, according to .isEmpty().");
  bool sizeIsOneOnAdd = (myList.size() == 1);
  toReturn+=message(sizeIsOneOnAdd, "The list has one element when it is initialized, according to .size().");
  bool elementIsPresent = myList.search(3);
  toReturn+=message(elementIsPresent, "The element that we added is present, according to .search().");
  bool nonElementIsNotPresent = !(myList.search(4));
  toReturn+=message(nonElementIsNotPresent, "An element that we did not add is not present, according to .search().");

  myList.removeFront();
  printf("  (Removing an element from front...)\n");
  bool emptyOnInit = myList.isEmpty();
  toReturn+=message(emptyOnInit, "The list is empty, according to .isEmpty().");
  bool sizeIsZeroOnInit = (myList.size() == 0);
  toReturn+=message(sizeIsZeroOnInit, "The list has zero elements, according to .size().");

  myList.addBack(3);
  myList.removeBack();
  printf("  (Adding, then removing an element from the back)\n");
  emptyOnInit = myList.isEmpty();
  toReturn+=message(emptyOnInit, "The list is empty, according to .isEmpty().");
  sizeIsZeroOnInit = (myList.size() == 0);
  toReturn+=message(sizeIsZeroOnInit, "The list has zero elements, according to .size().");

  return toReturn;
}

int TestSuite::testAddFront()
{
  printf("\nPerforming tests on adding one element to back of the list.\n");
  LinkedListOfInts myList;
  myList.addFront(3);

  int toReturn = 0;

  bool notEmptyOnAdd = (!(myList.isEmpty()));
  toReturn+=message(notEmptyOnAdd, "The list is not empty when an element is added, according to .isEmpty().");
  bool sizeIsOneOnAdd = (myList.size() == 1);
  toReturn+=message(sizeIsOneOnAdd, "The list has one element when it is initialized, according to .size().");
  bool elementIsPresent = myList.search(3);
  toReturn+=message(elementIsPresent, "The element that we added is present, according to .search().");
  bool nonElementIsNotPresent = !(myList.search(4));
  toReturn+=message(nonElementIsNotPresent, "An element that we did not add is not present, according to .search().");

  myList.removeFront();
  printf("  (Removing an element from front...)\n");
  bool emptyOnInit = myList.isEmpty();
  toReturn+=message(emptyOnInit, "The list is empty, according to .isEmpty().");
  bool sizeIsZeroOnInit = (myList.size() == 0);
  toReturn+=message(sizeIsZeroOnInit, "The list has zero elements, according to .size().");

  myList.addFront(3);
  myList.removeBack();
  printf("  (Adding, then removing an element from the back)\n");
  emptyOnInit = myList.isEmpty();
  toReturn+=message(emptyOnInit, "The list is empty, according to .isEmpty().");
  sizeIsZeroOnInit = (myList.size() == 0);
  toReturn+=message(sizeIsZeroOnInit, "The list has zero elements, according to .size().");

  return toReturn;
}

int TestSuite::testAddMultiple()
{
  printf("\nTest adding multiple elements to the list.\n");
  int toReturn = 0;

  printf("  (Adding 50 elements, using add front)\n");
  LinkedListOfInts listA;
  for (int i = 0; i < 50; i++)
  {
    listA.addFront(i);
  }

  toReturn+=message(listA.search(3), "Element that should be in the list, is in the list.");
  toReturn+=message(!listA.search(-30), "Element that shouldn't be in the list, is not in the list.");
  toReturn+=message(listA.size() == 50, "50 elements are present");
  toReturn+=message(!listA.isEmpty(), "It isn't empty.");

  printf("  (Adding 50 elements, using add back)\n");
  LinkedListOfInts listB;
  for (int i = 0; i < 50; i++)
  {
    listB.addBack(i);
  }

  toReturn+=message(listB.search(3), "Element that should be in the list, is in the list.");
  toReturn+=message(!listB.search(-30), "Element that shouldn't be in the list, is not in the list.");
  toReturn+=message(listB.size() == 50, "50 elements are present.");
  toReturn+=message(!listB.isEmpty(), "It isn't empty.");

  printf("  (Adding 50 elements, using add front and back)\n");
  LinkedListOfInts listC;
  for (int i = 0; i < 25; i++)
  {
    listC.addBack(i);
  }
  for (int i = 25; i < 50; i++)
  {
    listC.addFront(i);
  }

  toReturn+=message(listC.search(3), "Element that should be in the list, is in the list.");
  toReturn+=message(!listC.search(-30), "Element that shouldn't be in the list, is not in the list.");
  toReturn+=message(listC.size() == 50, "50 elements are present.");
  toReturn+=message(!listC.isEmpty(), "It isn't empty.");

  return toReturn;

}

int TestSuite::testRemoving()
{
  printf("\nTest removing elements.\n");
  int toReturn = 0;

  LinkedListOfInts listA;
  printf("  (Remove an element from the back of an empty list.)\n");
  listA.removeBack();
  toReturn+=message(listA.isEmpty(), "The list is empty.");
  toReturn+=message(listA.size() == 0, "The list has zero elements.");

  LinkedListOfInts listB;
  printf("  (Remove an element from the front of an empty list.)\n");
  listB.removeFront();
  toReturn+=message(listB.isEmpty(), "The list is empty.");
  toReturn+=message(listB.size() == 0, "The list has zero elements.");

  LinkedListOfInts listC;
  printf("  (Add an element, and then remove it.)\n");
  listC.addBack(4);
  toReturn+=message(!listC.isEmpty(), "The list isn't empty, before removal.");
  toReturn+=message(listC.size() == 1, "The size is correct.");
  listC.removeFront();
  toReturn+=message(listC.isEmpty(), "The list is empty after removing both elements.");

  return toReturn;
}

int TestSuite::testOrdering()
{
  printf("\nTest that the correct ordering is preserved with addFront and addBack.\n");
  int toReturn = 0;

  LinkedListOfInts listA;
  for (int i = 0; i < 50; i++)
  {
    listA.addBack(i);
  }
  printf("  (Create a list of 50 elements, and add certain elements to the front and back)\n");

  listA.addFront(9001);
  toReturn+=message(listA.toVector()[0] == 9001, "Element was added to the front of the list.");
  listA.addBack(777);
  toReturn+=message(listA.toVector()[51] == 777, "Element was added to the back of the list.");
  listA.removeBack();
  toReturn+=message(listA.toVector()[50] == 49, "Element was removed from the back of the list.");
  listA.removeFront();
  toReturn+=message(listA.toVector()[0] == 0, "Element was removed from the front of the list.");
  
  return toReturn;
}
