/*
 *  - studentsort.hpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

// multiple inclusion prevention
#ifndef STUDENTSORT_HPP
#define STUDENTSORT_HPP

#include <iostream>
#include "studentsort.hpp"
#include "student.hpp"
#include "domesticstudent.hpp"
#include "internationalstudent.hpp"
#include "student_lists.hpp"

/* DomesticStudent_ListNode* sortedMerge(DomesticStudent_ListNode* a, DomesticStudent_ListNode* b, char type, string order);
 * brief:
 * pre:
 * post:
 */

GenericStudent_ListNode* sortedMerge(GenericStudent_ListNode* a, GenericStudent_ListNode* b, char type, string order);

/* void frontBackSplit(DomesticStudent_ListNode* source, DomesticStudent_ListNode** frontPtr, DomesticStudent_ListNode** backPtr);
 * brief: splits a linked list into two halves
 * pre:
 * post:
 */

void frontBackSplit(GenericStudent_ListNode* source, GenericStudent_ListNode** frontPtr, GenericStudent_ListNode** backPtr);

/* void void mergeSort(DomesticStudent_ListNode** headRef, char type, string order);
 * brief: sorts a liked list with data of type DomesticStudent by a single type, in either ascending or descending order
 * pre: DomesticStudent_ListNode** headRef - pointing to the head of a linked list of type DomesticStudent
                                           - note that mergeSort doesn't change the data but rather the pointers (it reorders the list)
        int num - number of elements in the DomesticStudents array
        char type - "F" for first name
                    "L" for last name
                    "G" for CGPA
                    "R" for research score
                    "P" for province
        string order - either "ascending" or "descending"
 * post: nothing
 */

void mergeSort(GenericStudent_ListNode** studentHeadPtr, char type, string order);

/* void sortBy(DomesticStudent* DomesticStudents, int num, char type, string order)
 * brief: sorts an array of type DomesticStudent by multiple types, in either ascending or descending order
 * pre: DomesticStudent *DomesticStudents - pointing to the base of an array of type DomesticStudent
                                            note DomesticStudents is updated with the final sorted array
        char type - "F" for first name
                    "L" for last name
                    "G" for CGPA
                    "R" for research score
                    "P" for province
                    "GPR" will sort by CGPA, then will sort the same CGPA by province, then will sort the remaining by research score
        string order - either "ascending" or "descending"
 * post: nothing
 */

void sortBy(GenericStudent_ListNode** studentHeadPtr, string type, string order);

#endif
