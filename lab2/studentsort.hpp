/*
 *  - studentsort.hpp -
 * ENSC 251 - Lab Assignment 2
 * June 21, 2019
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

/* void singleSort(DomesticStudent* DomesticStudents, int num, char type, string order)
 * brief: sorts an array of type DomesticStudent by a single type, in either ascending or descending order
 * pre: DomesticStudent *DomesticStudents - pointing to the base of an array of type DomesticStudent
                                            note DomesticStudents is updated with the final sorted array
        int num - number of elements in the DomesticStudents array
        char type - "F" for first name
                    "L" for last name
                    "G" for CGPA
                    "R" for research score
                    "P" for province
        string order - either "ascending" or "descending"
 * post: nothing
 */
void singleSort(DomesticStudent *DomesticStudents, int num, char type, string order);
/* void singleSort(InternationalStudent* InternationalStudents, int num, char type, string order)
 * brief: sorts an array of type DomesticStudent by a single type, in either ascending or descending order
 * pre: InternationalStudent *InternationalStudents - pointing to the base of an array of type DomesticStudent
                                                      note InternationalStudents is updated with the final sorted array
        int num - number of elements in the InternationalStudents array
        char type - "F" for first name
                    "L" for last name
                    "G" for CGPA
                    "R" for research score
                    "C" for country
        string order - either "ascending" or "descending"
 * post: nothing
 */
void singleSort(InternationalStudent *InternationalStudents, int num, char type, string order);
/* void sortBy(DomesticStudent* DomesticStudents, int num, char type, string order)
 * brief: sorts an array of type DomesticStudent by multiple types, in either ascending or descending order
 * pre: DomesticStudent *DomesticStudents - pointing to the base of an array of type DomesticStudent
                                            note DomesticStudents is updated with the final sorted array
        int num - number of elements in the DomesticStudents array
        char type - "F" for first name
                    "L" for last name
                    "G" for CGPA
                    "R" for research score
                    "P" for province
                    "GPR" will sort by CGPA, then will sort the same CGPA by province, then will sort the remaining by research score
        string order - either "ascending" or "descending"
 * post: nothing
 */
void sortBy(DomesticStudent *DomesticStudents, int num, string type, string order);
/* void sortBy(InternationalStudent* InternationalStudents, int num, char type, string order)
 * brief: sorts an array of type DomesticStudent by multiple types, in either ascending or descending order
 * pre: InternationalStudent *InternationalStudents - pointing to the base of an array of type DomesticStudent
                                                      note InternationalStudents is updated with the final sorted array
        int num - number of elements in the InternationalStudents array
        char type - "F" for first name
                    "L" for last name
                    "G" for CGPA
                    "R" for research score
                    "C" for country
                    "GCR" will sort by CGPA, then will sort the same CGPA by country, then will sort the remaining by research score
        string order - either "ascending" or "descending"
 * post: nothing
 */
void sortBy(InternationalStudent *InternationalStudents, int num, string type, string order);

#endif
