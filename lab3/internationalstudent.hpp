/*
 *  - internationalstudent.hpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

// multiple inclusion prevention
#ifndef INTERNATIONALSTUDENT_HPP
#define INTERNATIONALSTUDENT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "student.hpp"
#include "toeflscore.hpp"

using namespace std;

// this class shares properties with the Student class above since it's a child
// class but it also has new members unique to InternationalStudent only
class InternationalStudent : public Student
{
public:
    /* string getCountry() const
     * brief: get function for the students country, declared as const
     * pre: nothing
     * post: returns the country for this particular student
     */
    string getCountry() const;
    /* void setCountry(string s)
     * brief: set function for the students country
     * pre: the string to set this students country to
     * post: nothing
     */
    void setCountry(string c);
    /* ToeflScore getToeflScore() const;
     * brief: get function for the students Toefl score, declared as const
     * pre: nothing
     * post: returns the ToeflScore object for this particular student
     */
    ToeflScore getToeflScore() const;
    /* void setToeflScore(ToeflScore t)
     * brief: **overloaded** set function for the students Toefl score
     * pre: the ToeflScore object to set this students ToeflScore to
     * post: nothing
     */
    void setToeflScore(ToeflScore t);
    /* void setToeflScore(int reading, int listening, int speaking, int writing)
     * brief: **overloaded** set function for the ToeflScore object
     * pre: individual reading, listening, speaking and writing values to set this students ToeflScore to
     * post: nothing
     */
    void setToeflScore(int reading, int listening, int speaking, int writing);
    /* int getReading() const
     * brief: get function for the ToeflScore's reading parameter
     * pre: nothing
     * post: returns the reading parameter of the ToeflScore associated with this student
     */
    int getReading() const;
    /* void setReading(int r)
     * brief: set function for the ToeflScore's reading parameter
     * pre: the value to set the reading parameter to
     * post: nothing
     */
    void setReading(int r);
    /* int getListening() const
     * brief: get function for the ToeflScore's listening parameter
     * pre: nothing
     * post: returns the listening parameter of the ToeflScore associated with this student
     */
    int getListening() const;
    /* void setListening(int l)
     * brief: set function for the ToeflScore's listening parameter
     * pre: the value to set the listening parameter to
     * post: nothing
     */
    void setListening(int l);
    /* int getSpeaking() const
     * brief: get function for the ToeflScore's speaking parameter
     * pre: nothing
     * post: returns the speaking parameter of the ToeflScore associated with this student
     */
    int getSpeaking() const;
    /* void setSpeaking(int s)
     * brief: set function for the ToeflScore's speaking parameter
     * pre: the value to set the speaking parameter to
     * post: nothing
     */
    void setSpeaking(int s);
    /* int getWriting() const
     * brief: get function for the ToeflScore's writing parameter
     * pre: nothing
     * post: returns the writing parameter of the ToeflScore associated with this student
     */
    int getWriting() const;
    /* void setWriting(int w)
     * brief: set function for the ToeflScore's writing parameter
     * pre: the value to set the writing parameter to
     * post: nothing
     */
    void setWriting(int w);
    /* int getTotalScore() const
     * brief: get function for the total ToeflScore
     * pre: nothing
     * post: returns the sum of all the parameters of the ToeflScore associated with this student
     */
    int getTotalScore() const;
    /* friend ostream& operator << (ostream& outs, const InternationalStudent &object)
     * brief: extraction operator for InternationalStudent class
     * pre: nothing
     * post: sends out data from the InternationalStudent object in the following order
             1. first name
             2. last name
             3. province
             4. CGPA
             5. research score
             6. ToeflScore reading score
             7. ToeflScore listening score
             8. ToeflScore speaking score
             9. ToeflScore writing score
     */
    friend ostream& operator << (ostream& outs, const InternationalStudent &object);
    /* friend istream& operator >> (istream &ins,  InternationalStudent &object)
     * brief: insertion operator for InternationalStudent class
     * pre: puts data from a stream into the InternationalStudent object in the following order
             1. first name
             2. last name
             3. province
             4. CGPA
             5. research score
             6. ToeflScore reading score
             7. ToeflScore listening score
             8. ToeflScore speaking score
             9. ToeflScore writing score
     * post: nothing
     */
    friend istream& operator >> (istream &ins, InternationalStudent &object);

    friend bool operator == (InternationalStudent student1, InternationalStudent student2);
    /* friend int compareProvince(InternationalStudent student1, InternationalStudent student2)
     * brief: compare two students countries
     * pre: student1 - the first student to compare
            student2 - the second student to compare
     * post: returns -1 if student 1's country is less (alphabetically) than student 2's
             returns 0 if the two countries are the same
             returns 1 if student 1's country is greater (alphabetically) than student 2's
     */
    friend int compareCountry(InternationalStudent student1, InternationalStudent student2);
    /* InternationalStudent()
     * brief: constructor for class InternationalStudent, initializes all values to 0 or ""
     * pre: nothing
     * post: nothing
     */
    InternationalStudent();
    /* InternationalStudent(string firstName, string lastName, string countryProvince, float cgpa, int researchScore, int readingScore, int listeningScore, int speakingScore, int writingScore)
     * brief: constructor for class InternationalStudent, initializes all values to those given
     * pre: firstName - the first name of the new student
            lastName - the last name of the new student
            country - the country of the new student
            cgpa - the cgpa of the new student
            researchScore - the research score of the new student
            readingScore - the reading score of the new student
            listeningScore - the listening score of the new student
            speakingScore - the speaking score of the new student
            writingScore - the writing score of the new student
     * post: nothing
     */
    InternationalStudent(string firstName, string lastName, string country, float cgpa, int researchScore, int readingScore, int listeningScore, int speakingScore, int writingScore);

private:
    // declare the actual variables as private so that the main program can't
    // access them and overwrite by accident
    ToeflScore toeflScore;
    string country;
};

#endif
