/*
 *  - student.cpp -
 * ENSC 251 - Lab Assignment 2
 * June 21, 2019
 * Judd Foster
 * 301377893
 */

// make sure to include the hpp file for the declarations; this file will be
// actually implementing the functions in the class
#include "student.hpp"

using namespace std;

// ****************** Student Class ****************** //

// ****************** Get and Set functions for Student Class ****************** //
string Student::getFirstName() const
{
    return this->firstName;
}

void Student::setFirstName(string s)
{
    this->firstName = s;
}

string Student::getLastName() const
{
    return this->lastName;
}

void Student::setLastName(string s)
{
    this->lastName = s;
}

float Student::getCGPA() const
{
    return this->CGPA;
}

void Student::setCGPA(float c)
{
    this->CGPA = c;
}

int Student::getResearchScore() const
{
    return this->researchScore;
}

void Student::setResearchScore(int rs)
{
    this->researchScore = rs;
}

// ****************** Constructor for InternationalStudent Class ****************** //

Student::Student()
{
    this->setFirstName("");
    this->setLastName("");
    this->setCGPA(0.0);
    this->setResearchScore(0);
}

// ****************** End InternationalStudent Class ****************** //

// ****************** Common functions used by both DomesticStudent and InternationalStudent ****************** //

int compareTwoInts(int n1, int n2)
{
    if (n1 > n2) return 1;
    if (n1 < n2) return -1;
    return 0;
}

int compareTwoFloats(float n1, float n2)
{
    if (n1 > n2) return 1;
    if (n1 < n2) return -1;
    return 0;
}

int compareTwoStrings(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++) if (s1[i] >= 'a' && s1[i] <= 'z') s1[i] -= ('a'-'A');
    for (int i = 0; i < s2.size(); i++) if (s2[i] >= 'a' && s2[i] <= 'z') s2[i] -= ('a'-'A');
    return s1.compare(s2);
}

// ****************** Friend functions of Student Class ****************** //

int compareCGPA(Student student1, Student student2)
{
    return compareTwoFloats(student1.CGPA, student2.CGPA);
}

int compareResearchScore(Student student1, Student student2)
{
    return compareTwoInts(student1.researchScore, student2.researchScore);
}

int compareFirstName(Student student1, Student student2)
{
    return compareTwoStrings(student1.firstName, student2.firstName);
}

int compareLastName(Student student1, Student student2)
{
    return compareTwoStrings(student1.lastName, student2.lastName);
}
