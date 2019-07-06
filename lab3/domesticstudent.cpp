/*
 *  - domesticstudent.cpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

#include "domesticstudent.hpp"

using namespace std;

// ****************** DomesticStudent Class ****************** //

// ****************** Get and Set functions for DomesticStudent Class ****************** //

string DomesticStudent::getProvince() const
{
    return this->province;
}

void DomesticStudent::setProvince(string s)
{
    this->province = s;
}

// ****************** Overloaded Operators for DomesticStudent Class ****************** //

ostream& operator << (ostream& outs, const DomesticStudent &object)
{
    // print out all the object's parameters in this order, formatted
    // insert a new line at the end so that we can keep printing with nice formatting
    outs << setw(14) << left << object.getFirstName() << " " << setw(18) <<  left << object.getLastName();
    outs << setw(10) << left << object.getProvince();
    outs << setw(6) << left << object.getCGPA();
    outs << setw(4) << left << object.getResearchScore() << endl;
    return outs;
}

istream& operator >> (istream &ins, DomesticStudent &object)
{
    // intended for use with the files given, so it's easy to read the
    // line of a file then send the line to this function, which will extract
    // all the information and put it in the appropriate locations
    string s_tmp;
    getline(ins, s_tmp, ',');
    object.setFirstName(s_tmp);
    getline(ins, s_tmp, ',');
    object.setLastName(s_tmp);
    getline(ins, s_tmp, ',');
    object.setProvince(s_tmp);
    getline(ins, s_tmp, ',');
    object.setCGPA(atof(s_tmp.c_str()));
    getline(ins, s_tmp, ',');
    object.setResearchScore(atoi(s_tmp.c_str()));
    return ins;
}

bool operator == (DomesticStudent student1, DomesticStudent student2)
{
    // need this if we want to compare two students, e.g. comparing an exising
    // student to a blank one
    if (student1.getFirstName() == student2.getFirstName() &&
        student1.getLastName() == student2.getLastName() &&
        student1.getProvince() == student2.getProvince() &&
        student1.getCGPA() == student2.getCGPA() &&
        student1.getResearchScore() == student2.getResearchScore())
    {
        return true;
    }
    return false;
}

// ****************** Constructor for DomesticStudent Class ****************** //

DomesticStudent::DomesticStudent()
{
    // default constructor, if no information is supplied
    // note the only paramter unique to the domesticStudent class is the province
    // so we don't have to worry about initializing firstName, lastName, etc.
    // because the Student class constructor takes care of that for us
    this->setProvince("");
}

DomesticStudent::DomesticStudent(string firstName, string lastName, string province, float cgpa, int researchScore)
{
    // constructor for initializing a new student with the given parameters
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setProvince(province);
    this->setCGPA(cgpa);
    this->setResearchScore(researchScore);
}

// ****************** Friend functions for DomesticStudent Class ****************** //

int compareProvince(DomesticStudent student1, DomesticStudent student2)
{
    return compareTwoStrings(student1.province, student2.province);
}

// ****************** End DomesticStudent Class ****************** //
