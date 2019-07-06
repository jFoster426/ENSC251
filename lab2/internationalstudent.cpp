/*
 *  - Internationalstudent.cpp -
 * ENSC 251 - Lab Assignment 2
 * June 21, 2019
 * Judd Foster
 * 301377893
 */

// make sure to include the hpp file for the declarations; this file will be
// actually implementing the functions in the class
#include "internationalstudent.hpp"

using namespace std;

// ****************** InternationalStudent Class ****************** //

// ****************** Get and Set functions for InternationalStudent Class ****************** //
string InternationalStudent::getCountry() const
{
    return this->country;
}

void InternationalStudent::setCountry(string c)
{
    this->country = c;
}

ToeflScore InternationalStudent::getToeflScore() const
{
    ToeflScore t;
    t.setReading(this->toeflScore.getReading());
    t.setListening(this->toeflScore.getListening());
    t.setSpeaking(this->toeflScore.getSpeaking());
    t.setWriting(this->toeflScore.getWriting());
    return t;
}

void InternationalStudent::setToeflScore(ToeflScore t)
{
    this->toeflScore.setReading(t.getReading());
    this->toeflScore.setListening(t.getListening());
    this->toeflScore.setSpeaking(t.getSpeaking());
    this->toeflScore.setWriting(t.getWriting());
}

void InternationalStudent::setToeflScore(int reading, int listening, int speaking, int writing)
{
    this->toeflScore.setReading(reading);
    this->toeflScore.setListening(listening);
    this->toeflScore.setSpeaking(speaking);
    this->toeflScore.setWriting(writing);
}

int InternationalStudent::getReading() const
{
    return this->toeflScore.getReading();
}

void InternationalStudent::setReading(int r)
{
    this->toeflScore.setReading(r);
}

int InternationalStudent::getListening() const
{
    return this->toeflScore.getListening();
}

void InternationalStudent::setListening(int l)
{
    this->toeflScore.setListening(l);
}

int InternationalStudent::getSpeaking() const
{
    return this->toeflScore.getSpeaking();
}

void InternationalStudent::setSpeaking(int s)
{
    this->toeflScore.setSpeaking(s);
}

int InternationalStudent::getWriting() const
{
    return this->toeflScore.getWriting();
}

void InternationalStudent::setWriting(int w)
{
    this->toeflScore.setWriting(w);
}

int InternationalStudent::getTotalScore() const
{
    int total = 0;
    total += this->toeflScore.getReading();
    total += this->toeflScore.getListening();
    total += this->toeflScore.getSpeaking();
    total += this->toeflScore.getWriting();
    return total;
}

// ****************** Overloaded Operators for InternationalStudent Class ****************** //

ostream& operator << (ostream& outs, const InternationalStudent &object)
{
    outs << setw(14) << left << object.getFirstName() << " " << setw(18) << left << object.getLastName();
    outs << setw(10) << left << object.getCountry();
    outs << setw(6) << left << object.getCGPA();
    outs << setw(4) << left << object.getResearchScore();
    outs << setw(4) << left << object.getReading();
    outs << setw(4) << left << object.getListening();
    outs << setw(4) << left << object.getSpeaking();
    outs << setw(4) << left << object.getWriting();
    outs << object.getTotalScore() << endl;
    return outs;
}

istream& operator >> (istream &ins, InternationalStudent &object)
{
    string s_tmp;
    getline(ins, s_tmp, ',');
    object.setFirstName(s_tmp);
    getline(ins, s_tmp, ',');
    object.setLastName(s_tmp);
    getline(ins, s_tmp, ',');
    object.setCountry(s_tmp);
    getline(ins, s_tmp, ',');
    object.setCGPA(atof(s_tmp.c_str()));
    getline(ins, s_tmp, ',');
    object.setResearchScore(atoi(s_tmp.c_str()));
    getline(ins, s_tmp, ',');
    object.setReading(atoi(s_tmp.c_str()));
    getline(ins, s_tmp, ',');
    object.setListening(atoi(s_tmp.c_str()));
    getline(ins, s_tmp, ',');
    object.setSpeaking(atoi(s_tmp.c_str()));
    getline(ins, s_tmp, ',');
    object.setWriting(atoi(s_tmp.c_str()));
    return ins;
}

// ****************** Constructor for InternationalStudent Class ****************** //

InternationalStudent::InternationalStudent()
{
    this->setCountry("");
}

// ****************** Friend functions of InternationalStudent Class ****************** //

int compareCountry(InternationalStudent student1, InternationalStudent student2)
{
    return compareTwoStrings(student1.country, student2.country);
}

// ****************** End InternationalStudent Class ****************** //
