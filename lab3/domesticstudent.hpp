/*
 *  - domesticstudent.hpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

// multiple inclusion prevention
#ifndef DOMESTICSTUDENT_HPP
#define DOMESTICSTUDENT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "student.hpp"

using namespace std;

// this class shares properties with the Student class above since it's a child
// class but it also has new members unique to DomesticStudent only
class DomesticStudent : public Student
{
public:
    /* string getProvince() const
     * brief: get function for the students province, declared as const
     * pre: nothing
     * post: returns the province for this particular student
     */
    string getProvince() const;
    /* void setProvince(string s)
     * brief: set function for the students province
     * pre: the string to set this students province to
     * post: nothing
     */
    void setProvince(string s);
    /* friend ostream& operator << (ostream& outs, const DomesticStudent &object)
     * brief: extraction operator for DomesticStudent class
     * pre: nothing
     * post: sends out data from the DomesticStudent object in the following order
             1. first name
             2. last name
             3. province
             4. CGPA
             5. research score
     */
    friend ostream &operator << (ostream &outs, const DomesticStudent &object);
    /* friend istream& operator >> (istream &ins,  DomesticStudent &object)
     * brief: insertion operator for DomesticStudent class
     * pre: puts data from a stream into the DomesticStudent object in the following order
             1. first name
             2. last name
             3. province
             4. CGPA
             5. research score
     * post: nothing
     */
    friend istream &operator >> (istream &ins,  DomesticStudent &object);

    friend bool operator == (DomesticStudent student1, DomesticStudent student2);
    /* friend int compareProvince(DomesticStudent student1, DomesticStudent student2)
     * brief: compare two students provinces
     * pre: student1 - the first student to compare
            student2 - the second student to compare
     * post: nothing
     */
    friend int compareProvince(DomesticStudent student1, DomesticStudent student2);
    /* DomesticStudent()
     * brief: constructor for class DomesticStudent, initializes all values to 0 or ""
     * pre: nothing
     * post: nothing
     */
    DomesticStudent();
    /* DomesticStudent(string firstName, string lastName, string province, float cgpa, int researchScore)
     * brief: constructor for class DomesticStudent, initializes all values to those given
     * pre: firstName - the first name of the new student
            lastName - the last name of the new student
            province - the province of the new student
            cgpa - the cgpa of the new student
            researchScore - the research score of the new student
     * post: nothing
     */
    DomesticStudent(string firstName, string lastName, string province, float cgpa, int researchScore);

private:
    // declare the actual variables as private so that the main program can't
    // access them and overwrite by accident
    string province;
};

#endif
