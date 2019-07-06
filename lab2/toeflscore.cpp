/*
 *  - toeflscore.cpp -
 * ENSC 251 - Lab Assignment 2
 * June 21, 2019
 * Judd Foster
 * 301377893
 */

// make sure to include the hpp file for the declarations; this file will be
// actually implementing the functions in the class
#include "toeflscore.hpp"

using namespace std;

// ****************** ToeflScore Class ****************** //

// ****************** Get and Set functions for ToeflScore Class ****************** //

int ToeflScore::getReading() const
{
    return this->reading;
}

void ToeflScore::setReading(int r)
{
    this->reading = r;
}

int ToeflScore::getListening() const
{
    return this->listening;
}

void ToeflScore::setListening(int l)
{
    this->listening = l;
}

int ToeflScore::getSpeaking() const
{
    return this->speaking;
}

void ToeflScore::setSpeaking(int s)
{
    this->speaking = s;
}

int ToeflScore::getWriting() const
{
    return this->writing;
}

void ToeflScore::setWriting(int w)
{
    this->writing = w;
}

int ToeflScore::getTotalScore() const
{
    int total = 0;
    total += this->reading;
    total += this->listening;
    total += this->speaking;
    total += this->writing;
    return total;
}

// ****************** Constructor for ToeflScore Class ****************** //

ToeflScore::ToeflScore()
{
    this->setReading(0);
    this->setListening(0);
    this->setSpeaking(0);
    this->setWriting(0);
}

// ****************** End ToeflScore Class ****************** //
