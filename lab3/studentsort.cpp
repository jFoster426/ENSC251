/*
 *  - studentsort.cpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

// make sure to include the hpp file for the declarations; this file will be
// actually implementing the functions in the class
#include "studentsort.hpp"

using namespace std;

GenericStudent_ListNode* sortedMerge(GenericStudent_ListNode* a, GenericStudent_ListNode* b, char type, string order)
{
    GenericStudent_ListNode* result = NULL;
    int ascending = -1;
    // if the type is not specifically "ascending", then sort in descending order
    if (order == "ascending") ascending = 1;
    // catch to make sure we have a base case, if one of the lists has reached the end
    if (a == NULL) return b;
    if (b == NULL) return a;
    // compareXXXGeneric functions automatically detect which type of student is in this node
    if (((type == 'F') && (compareFirstNameGeneric(a, b) * ascending > 0))
    ||  ((type == 'L') && (compareLastNameGeneric(a, b) * ascending > 0))
    ||  ((type == 'G') && (compareCGPAGeneric(a, b) * ascending > 0))
    ||  ((type == 'R') && (compareResearchScoreGeneric(a, b) * ascending > 0))
    ||  ((type == 'P' || type == 'C') && (compareLocationsGeneric(a, b) * ascending > 0))
    ||  ((type == 'X') && (compareStudentTypesGeneric(a, b) > 0)))
    {
        result = b;
        result->nextNode = sortedMerge(a, b->nextNode, type, order);
    }
    else
    {
        result = a;
        result->nextNode = sortedMerge(a->nextNode, b, type, order);
    }
    return result;
}

void frontBackSplit(GenericStudent_ListNode* source, GenericStudent_ListNode** frontPtr, GenericStudent_ListNode** backPtr)
{
    // split the source list into two, frontPtr points to the first half, backPtr points to the second half
    GenericStudent_ListNode* fast;
    GenericStudent_ListNode* slow;
    slow = source;
    fast = source->nextNode;
    while (fast != NULL)
    {
        fast = fast->nextNode;
        if (fast != NULL)
        {
            slow = slow->nextNode;
            fast = fast->nextNode;
        }
    }
    (*frontPtr) = source;
    (*backPtr) = slow->nextNode;
    slow->nextNode = NULL;
}

// sorts the linked list by changing next pointers (not data)
void mergeSort(GenericStudent_ListNode** studentHeadPtr, char type, string order)
{
    GenericStudent_ListNode* studentHead = (*studentHeadPtr);
    GenericStudent_ListNode* a;
    GenericStudent_ListNode* b;
    // catch to see if we tried to send it a null ptr, or if the linked list has
    // only one node, then we can't sort!
    if ((studentHead == NULL) || (studentHead->nextNode == NULL)) return;
    // split the list into two
    frontBackSplit(studentHead, &a, &b);
    // call this function recursively, it splits the list up into two's until it
    // can't anymore
    mergeSort(&a, type, order);
    mergeSort(&b, type, order);
    // sort the linked list, and re-point the head back to the head after sorting,
    // since it might have changed if there is a new head assigned
    *studentHeadPtr = sortedMerge(a, b, type, order);
}

void sortBy(GenericStudent_ListNode** studentHeadPtr, string type, string order)
{
    // repeat single sort for all the characters in the string
    // do it backwards so the first chat the user types has the highest priority
    for (int i = sizeof(type) - 1; i >= 0; i--) mergeSort(studentHeadPtr, type[i], order);
}
