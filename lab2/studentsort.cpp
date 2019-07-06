/*
 *  - studentsort.cpp -
 * ENSC 251 - Lab Assignment 2
 * June 21, 2019
 * Judd Foster
 * 301377893
 */

// make sure to include the hpp file for the declarations; this file will be
// actually implementing the functions in the class
#include "studentsort.hpp"

using namespace std;

void singleSort(DomesticStudent* DomesticStudents, int num, char type, string order)
{
    int ascending = -1;
    // if the type is not specifically "ascending", then sort in descending order
    if (order == "ascending") ascending = 1;
    // implement bubble sort algorithm
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num-1; j++)
        {
            if (((type == 'F') && (compareFirstName(DomesticStudents[j], DomesticStudents[j+1]) * ascending > 0))
            ||  ((type == 'L') && (compareLastName(DomesticStudents[j], DomesticStudents[j+1]) * ascending > 0))
            ||  ((type == 'G') && (compareCGPA(DomesticStudents[j], DomesticStudents[j+1]) * ascending > 0))
            ||  ((type == 'R') && (compareResearchScore(DomesticStudents[j], DomesticStudents[j+1]) * ascending > 0))
            ||  ((type == 'P') && (compareProvince(DomesticStudents[j], DomesticStudents[j+1]) * ascending > 0)))
            {
                DomesticStudent tmpStudent;
                tmpStudent = DomesticStudents[j];
                DomesticStudents[j] = DomesticStudents[j+1];
                DomesticStudents[j+1] = tmpStudent;
            }
        }
    }
}

void singleSort(InternationalStudent* InternationalStudents, int num, char type, string order)
{
    int ascending = -1;
    // if the type is not specifically "ascending", then sort in descending order
    if (order == "ascending") ascending = 1;
    // implement bubble sort algorithm
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num-1; j++)
        {
            if (((type == 'F') && (compareFirstName(InternationalStudents[j], InternationalStudents[j+1]) * ascending > 0))
            ||  ((type == 'L') && (compareLastName(InternationalStudents[j], InternationalStudents[j+1]) * ascending > 0))
            ||  ((type == 'G') && (compareCGPA(InternationalStudents[j], InternationalStudents[j+1]) * ascending > 0))
            ||  ((type == 'R') && (compareResearchScore(InternationalStudents[j], InternationalStudents[j+1]) * ascending > 0))
            ||  ((type == 'C') && (compareCountry(InternationalStudents[j], InternationalStudents[j+1]) * ascending > 0)))
            {
                InternationalStudent tmpStudent;
                tmpStudent = InternationalStudents[j];
                InternationalStudents[j] = InternationalStudents[j+1];
                InternationalStudents[j+1] = tmpStudent;
            }
        }
    }
}

void sortBy(DomesticStudent* DomesticStudents, int num, string type, string order)
{
    // repeat single sort for all the characters in the string
    // do it backwards so the first chat the user types has the highest priority
    for (int i = sizeof(type) - 1; i >= 0; i--) singleSort(DomesticStudents, num, type[i], order);
}

void sortBy(InternationalStudent* InternationalStudents, int num, string type, string order)
{
    // repeat single sort for all the characters in the string
    // do it backwards so the first chat the user types has the highest priority
    for (int i = sizeof(type) - 1; i >= 0; i--) singleSort(InternationalStudents, num, type[i], order);
}
