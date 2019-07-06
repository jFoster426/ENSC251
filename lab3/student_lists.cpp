/*
 *  - student_lists.cpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

#include "student_lists.hpp"

// ****************** Defualt constructors ****************** //

GenericStudent_ListNode::GenericStudent_ListNode()
{
    this->nextNode = NULL;
}

// ****************** Comparing functions that can compare different types of students ****************** //

int compareFirstNameGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2)
{
    string str1, str2;
    // use blank domestic and international students so that we can test which type of student is stored
    // in the GenericStudent_ListNode node
    DomesticStudent blankDomesticStudent;
    InternationalStudent blankInternationalStudent;
    if (s1->domesticStudent == blankDomesticStudent) str1 = s1->internationalStudent.getFirstName();
    if (s1->internationalStudent == blankInternationalStudent) str1 = s1->domesticStudent.getFirstName();
    if (s2->domesticStudent == blankDomesticStudent) str2 = s2->internationalStudent.getFirstName();
    if (s2->internationalStudent == blankInternationalStudent) str2 = s2->domesticStudent.getFirstName();
    return compareTwoStrings(str1, str2);
}

int compareLastNameGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2)
{
    string str1, str2;
    // use blank domestic and international students so that we can test which type of student is stored
    // in the GenericStudent_ListNode node
    DomesticStudent blankDomesticStudent;
    InternationalStudent blankInternationalStudent;
    if (s1->domesticStudent == blankDomesticStudent) str1 = s1->internationalStudent.getLastName();
    if (s1->internationalStudent == blankInternationalStudent) str1 = s1->domesticStudent.getLastName();
    if (s2->domesticStudent == blankDomesticStudent) str2 = s2->internationalStudent.getLastName();
    if (s2->internationalStudent == blankInternationalStudent) str2 = s2->domesticStudent.getLastName();
    return compareTwoStrings(str1, str2);
}

int compareCGPAGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2)
{
    float n1, n2;
    // use blank domestic and international students so that we can test which type of student is stored
    // in the GenericStudent_ListNode node
    DomesticStudent blankDomesticStudent;
    InternationalStudent blankInternationalStudent;
    if (s1->domesticStudent == blankDomesticStudent) n1 = s1->internationalStudent.getCGPA();
    if (s1->internationalStudent == blankInternationalStudent) n1 = s1->domesticStudent.getCGPA();
    if (s2->domesticStudent == blankDomesticStudent) n2 = s2->internationalStudent.getCGPA();
    if (s2->internationalStudent == blankInternationalStudent) n2 = s2->domesticStudent.getCGPA();
    return compareTwoFloats(n1, n2);
}

int compareResearchScoreGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2)
{
    int n1, n2;
    // use blank domestic and international students so that we can test which type of student is stored
    // in the GenericStudent_ListNode node
    DomesticStudent blankDomesticStudent;
    InternationalStudent blankInternationalStudent;
    if (s1->domesticStudent == blankDomesticStudent) n1 = s1->internationalStudent.getResearchScore();
    if (s1->internationalStudent == blankInternationalStudent) n1 = s1->domesticStudent.getResearchScore();
    if (s2->domesticStudent == blankDomesticStudent) n2 = s2->internationalStudent.getResearchScore();
    if (s2->internationalStudent == blankInternationalStudent) n2 = s2->domesticStudent.getResearchScore();
    return compareTwoInts(n1, n2);
}

int compareLocationsGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2)
{
    string str1, str2;
    // use blank domestic and international students so that we can test which type of student is stored
    // in the GenericStudent_ListNode node
    DomesticStudent blankDomesticStudent;
    InternationalStudent blankInternationalStudent;
    if (s1->domesticStudent == blankDomesticStudent) str1 = s1->internationalStudent.getCountry();
    if (s1->internationalStudent == blankInternationalStudent) str1 = s1->domesticStudent.getProvince();
    if (s2->domesticStudent == blankDomesticStudent) str2 = s2->internationalStudent.getCountry();
    if (s2->internationalStudent == blankInternationalStudent) str2 = s2->domesticStudent.getProvince();
    return compareTwoStrings(str1, str2);
}

int compareStudentTypesGeneric(GenericStudent_ListNode* s1, GenericStudent_ListNode* s2)
{
    // use blank domestic and international students so that we can test which type of student is stored
    // in the GenericStudent_ListNode node
    DomesticStudent blankDomesticStudent;
    InternationalStudent blankInternationalStudent;
    if (s1->domesticStudent == blankDomesticStudent && s2->internationalStudent == blankInternationalStudent) return 1;
    if (s1->internationalStudent == blankInternationalStudent && s2->domesticStudent == blankDomesticStudent) return -1;
    // they are of the same type, so they are equal weighting
    return 0;
}
