/*
 *  - Internationalstudent.cpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
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
    // useful to get the toeflScore all at once
    ToeflScore t;
    t.setReading(this->toeflScore.getReading());
    t.setListening(this->toeflScore.getListening());
    t.setSpeaking(this->toeflScore.getSpeaking());
    t.setWriting(this->toeflScore.getWriting());
    return t;
}

void InternationalStudent::setToeflScore(ToeflScore t)
{
    // useful to set all parameters of the toeflScore all at once
    this->toeflScore.setReading(t.getReading());
    this->toeflScore.setListening(t.getListening());
    this->toeflScore.setSpeaking(t.getSpeaking());
    this->toeflScore.setWriting(t.getWriting());
}

void InternationalStudent::setToeflScore(int reading, int listening, int speaking, int writing)
{
    // can also set each parameter of the toeflScore individually
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
    // note the totalScore isn't actually in the object
    // we just sum the values together and return them as the total score
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
    // print out all the object's parameters in this order, formatted
    // insert a new line at the end so that we can keep printing with nice formatting
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
    // intended for use with the files given, so it's easy to read the
    // line of a file then send the line to this function, which will extract
    // all the information and put it in the appropriate locations
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

bool operator == (InternationalStudent student1, InternationalStudent student2)
{
    // need this if we want to compare two students, e.g. comparing an exising
    // student to a blank one
    if (student1.getFirstName() == student2.getFirstName() &&
        student1.getLastName() == student2.getLastName() &&
        student1.getCountry() == student2.getCountry() &&
        student1.getCGPA() == student2.getCGPA() &&
        student1.getResearchScore() == student2.getResearchScore())
    {
        return true;
    }
    return false;
}

// ****************** Constructor for InternationalStudent Class ****************** //

InternationalStudent::InternationalStudent()
{
    // default constructor, if no information is supplied
    // note the only paramter unique to the internationalStudent class is the country
    // so we don't have to worry about initializing firstName, lastName, etc.
    // because the Student class constructor takes care of that for us
    this->setCountry("");
}

InternationalStudent::InternationalStudent(string firstName, string lastName, string country, float cgpa, int researchScore, int readingScore, int listeningScore, int speakingScore, int writingScore)
{
    // constructor for initializing a new student with the given parameters
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setCGPA(cgpa);
    this->setResearchScore(researchScore);
    this->setCountry(country);
    this->setReading(readingScore);
    this->setListening(listeningScore);
    this->setSpeaking(speakingScore);
    this->setWriting(writingScore);
}

// ****************** Friend functions of InternationalStudent Class ****************** //

int compareCountry(InternationalStudent student1, InternationalStudent student2)
{
    return compareTwoStrings(student1.country, student2.country);
}

// ****************** End InternationalStudent Class ****************** //
