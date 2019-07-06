/*
 *  - toeflscore.hpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
 * Judd Foster
 * 301377893
 */

// multiple inclusion prevention
#ifndef TOEFLSCORE_HPP
#define TOEFLSCORE_HPP

#include <iostream>
#include <string>

using namespace std;

// this class holds the reading, writing, speaking, etc. values for the
// InternationalStudent class, it makes it more organized
class ToeflScore
{
public:
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
    /* ToeflScore()
     * brief: constructor for class ToeflScore, initializes all values to 0
     * pre: nothing
     * post: nothing
     */
    ToeflScore();

private:
    // declare the actual variables as private so that the main program can't
    // access them and overwrite by accident
    int reading;
    int listening;
    int speaking;
    int writing;
};

#endif
