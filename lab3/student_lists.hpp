/*
 *  - student_lists.hpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

// multiple inclusion prevention
#ifndef STUDENT_LISTS_HPP
#define STUDENT_LISTS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "student.hpp"
#include "domesticstudent.hpp"
#include "toeflscore.hpp"
#include "internationalstudent.hpp"

// Generic student list can hold both types of students, this makes the main
// code way easier to implement because everyone can go in the same list from
// the start
class GenericStudent_ListNode
{
public:
    // domestic student type
    DomesticStudent domesticStudent;
    // international student type
    InternationalStudent internationalStudent;
    // link to the next node
    GenericStudent_ListNode *nextNode;
    /* GenericStudent_ListNode()
     * brief: constructor for class GenericStudent_ListNode, initializes the
              nextNode to NULL pointer
     * pre: nothing
     * post: nothing
     */
    GenericStudent_ListNode();
private:
};

/* int compareFirstNameGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
 * brief: generic compare for the first names of two students in a GenericStudent_ListNode
          - Note the two students being compared can be of different types
 * pre: *s1 - pointer to the first node to be compared
        *s2 - pointer to the second node to be compared
 * post: returns -1 if student 1's first name is less (alphabetically) than student 2's
         returns 0 if the two countries are the same
         returns 1 if student 1's first name is greater (alphabetically) than student 2's
 */
int compareFirstNameGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
/* int compareLastNameGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
 * brief: generic compare for the last names of two students in a GenericStudent_ListNode
          - Note the two students being compared can be of different types
 * pre: *s1 - pointer to the first node to be compared
        *s2 - pointer to the second node to be compared
 * post: returns -1 if student 1's last name is less (alphabetically) than student 2's
         returns 0 if the two countries are the same
         returns 1 if student 1's last name is greater (alphabetically) than student 2's
 */
int compareLastNameGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
/* int compareCGPAGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
 * brief: generic compare for the CGPAs of two students in a GenericStudent_ListNode
          - Note the two students being compared can be of different types
 * pre: *s1 - pointer to the first node to be compared
        *s2 - pointer to the second node to be compared
 * post: returns -1 if student 1's CGPA is less than student 2's
         returns 0 if the two countries are the same
         returns 1 if student 1's CGPA is greater than student 2's
 */
int compareCGPAGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
/* int compareResearchScoreGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
 * brief: generic compare for the research scores of two students in a GenericStudent_ListNode
          - Note the two students being compared can be of different types
 * pre: *s1 - pointer to the first node to be compared
        *s2 - pointer to the second node to be compared
 * post: returns -1 if student 1's CGPA is less than student 2's
         returns 0 if the two countries are the same
         returns 1 if student 1's CGPA is greater than student 2's
 */
int compareResearchScoreGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
/* int compareLocationsGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
 * brief: generic compare for the provinces/countries of two students in a GenericStudent_ListNode
          - Note the two students being compared can be of different types, but the country and province
          - are sorted the same, e.g. BC will always come before China
 * pre: *s1 - pointer to the first node to be compared
        *s2 - pointer to the second node to be compared
 * post: returns -1 if student 1's province/country is less (alphabetically) than student 2's
         returns 0 if the two countries are the same
         returns 1 if student 1's province/country is greater (alphabetivally) than student 2's
 */
int compareLocationsGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
/* int compareStudentTypesGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);
 * brief: tells us which node should be prioritized, if it has an international student, it
          will have less priority then a node with a domestic student
 * pre: *s1 - pointer to the first node to be compared
        *s2 - pointer to the second node to be compared
 * post: returns -1 if student 1 is an international student and student 2 is a domestic student
         returns 0 if the two students are both domestic students or both international students
         returns 1 if student 1 is an domestic student and student 2 is an international student
 */
int compareStudentTypesGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2);

#endif
