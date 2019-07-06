/*
 *  - student.hpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

// multiple inclusion prevention
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

using namespace std;

// main student class, this is the same for all students, domestic and
// international
class Student
{
public:
    /* string getFirstName() const
     * brief: get function for the students first name, declared as const
     * pre: nothing
     * post: returns the first name for this particular student
     */
    string getFirstName() const;
    /* void setFirstName(string s)
     * brief: set function for the students first name
     * pre: the string to set this students first name to
     * post: nothing
     */
    void setFirstName(string s);
    /* string getLastName() const
     * brief: get function for the students last name, declared as const
     * pre: nothing
     * post: returns the last name for this particular student
     */
    string getLastName() const;
    /* void setLastName(string s)
     * brief: set function for the students last name
     * pre: the string to set this students last name to
     * post: nothing
     */
    void setLastName(string s);
    /* float getCGPA() const
     * brief: get function for the students CGPA, declared as const
     * pre: nothing
     * post: returns the CGPA for this particular student
     */
    float getCGPA() const;
    /* void setCGPA(float c)
     * brief: set function for the students CGPA
     * pre: the string to set this students CGPA to
     * post: nothing
     */
    void setCGPA(float c);
    /* int getResearchScore() const
     * brief: get function for the students research score, declared as const
     * pre: nothing
     * post: returns the research score for this particular student
     */
    int getResearchScore() const;
    /* void setResearchScore(int rs)
     * brief: set function for the students research score
     * pre: the string to set this students CGPA to
     * post: nothing
     */
    void setResearchScore(int rs);
    /* friend int compareCGPA(Student student1, Student student2);
     * brief: compare two students CGPAs
     * pre: student1 - the first student to compare
            student2 - the second student to compare
     * post: nothing
     */
    friend int compareCGPA(Student student1, Student student2);
    /* friend int compareResearchScore(Student student1, Student student2);
     * brief: compare two students research scores
     * pre: student1 - the first student to compare
            student2 - the second student to compare
     * post: nothing
     */
    friend int compareResearchScore(Student student1, Student student2);
    /* friend int compareFirstName(Student student1, Student student2);
     * brief: compare two students first names
     * pre: student1 - the first student to compare
            student2 - the second student to compare
     * post: nothing
     */
    friend int compareFirstName(Student student1, Student student2);
    /* friend int compareLastName(Student student1, Student student2);
     * brief: compare two students last names
     * pre: student1 - the first student to compare
            student2 - the second student to compare
     * post: nothing
     */
    friend int compareLastName(Student student1, Student student2);
    /* Student()
     * brief: constructor for class Student, initializes all values to 0 or ""
     * pre: nothing
     * post: nothing
     */
    Student();

private:
    // declare the actual variables as private so that the main program can't
    // access them and overwrite by accident
    string firstName;
    string lastName;
    float CGPA;
    int researchScore;
};

// functions outside of class but are common to both types of students

/* int compareTwoInts(int n1, int n2)
 * brief: compare two integer values
 * pre: n1 is the first number to compare, n2 is the second number to compare
 * post: returns [-1,0,1] if n1 [<,=,>] n2
 */
int compareTwoInts(int n1, int n2);

/* int compareTwoFloats(float n1, float n2)
 * brief: compare two floating point values
 * pre: n1 is the first number to compare, n2 is the second number to compare
 * post: returns [-1,0,1] if n1 [<,=,>] n2
 */
int compareTwoFloats(float n1, float n2);

/* int compareTwoStrings(string s1, string s2)
 * brief: compare two strings
 * pre: n1 is the first string to compare, n2 is the second stirng to compare
 * post: returns [-1,0,1] if s1 [<,=,>] s2
 */
int compareTwoStrings(string s1, string s2);

#endif
