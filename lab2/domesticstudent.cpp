/*
 *  - domesticstudent.cpp -
 * ENSC 251 - Lab Assignment 2
 * June 21, 2019
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
    outs << setw(14) << left << object.getFirstName() << " " << setw(18) <<  left << object.getLastName();
    outs << setw(10) << left << object.getProvince();
    outs << setw(6) << left << object.getCGPA();
    outs << setw(4) << left << object.getResearchScore() << endl;
    return outs;
}

istream& operator >> (istream &ins, DomesticStudent &object)
{
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

// ****************** Constructor for DomesticStudent Class ****************** //

DomesticStudent::DomesticStudent()
{
    this->setProvince("");
}

// ****************** Friend functions for DomesticStudent Class ****************** //

int compareProvince(DomesticStudent student1, DomesticStudent student2)
{
    return compareTwoStrings(student1.province, student2.province);
}

// ****************** End DomesticStudent Class ****************** //
