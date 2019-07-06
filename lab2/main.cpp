/*
 *  - main.cpp -
 * ENSC 251 - Lab Assignment 2
 * June 21, 2019
 * Judd Foster
 * 301377893
 */

// include standard libraries
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
// include user defined libraries
#include "student.hpp"
#include "domesticstudent.hpp"
#include "toeflscore.hpp"
#include "internationalstudent.hpp"
#include "studentsort.hpp"

using namespace std;


/* ifstream fileOpen(string fname)
 * brief: open a file
 * pre: fname takes a string to the path of the file
 * post: returns the handle to the file that was opened
 */
ifstream fileOpen(string fname)
{
    ifstream file(fname);
    if(!file.is_open())
    {
        cout << "Unable to open file " << fname << ". Terminating" << endl;
        exit(-1);
    }
    return file;
}

/* int countLines(ifstream& file)
 * brief: count the lines in a file
 * pre: file is passed by reference and is the handle to the file that we count lines from
 * post: returns the number of lines in the file
 */
int countLines(ifstream& file)
{
    int i = 0;
    string line;
    while(getline(file, line)) i++;
    // reset the position in the file for the user
    file.clear();
    file.seekg(0, ios::beg);
    getline(file, line);
    return i;
}

int main()
{
    // initialize user selections for student and sorting type
    string studentSelection, sortingSelection, line;
    // use the same file for both domestic students and international students
    // since only one is open at a time
    ifstream file;
    // output to the user
    cout << "Please select which group you would like to sort:\nDomestic Students (D)  International Students(I)  Overall Sort (O)\n";
    cin >> studentSelection;
    // if the student type was not overall sorting type then we need to know the sorting type
    if (studentSelection != "O")
    {
        cout << "Please enter what you would like to sort by:\nFirst Name (F)  Last Name (L)  CGPA (G)  Research Score (R)  Province (P)  Country (C)\nOr any combination of the above.\n";
        cin >> sortingSelection;
    }
    // sort domestic students
    if (studentSelection == "D" || studentSelection == "O")
    {
        file = fileOpen("domestic-stu.txt");
        int numDomesticStudents = countLines(file) - 1;
        // declare some dynamic memory to the exact size of the number of students in the file
        DomesticStudent *DomesticStudents = new DomesticStudent[numDomesticStudents];
        // read the data from each file line into the DomesticStudents (this uses the user defined >> operator in DomesticStudent library)
        int i = 0;
        while(getline(file, line))
        {
            istringstream ss(line);
            ss >> DomesticStudents[i++];
        }
        // if overall sorting, sort by CGPA, then research score, then province
        if (studentSelection == "O") sortingSelection = "GRP";
        // sort the data
        sortBy(DomesticStudents, numDomesticStudents, sortingSelection, "ascending");
        // print out the results
        cout << "\n\nSorted DomesticStudent Array:\n\n";
        for (int i = 0; i < numDomesticStudents; i++)
        {
            cout << setw(5) << left << i+1 << DomesticStudents[i];
        }
        // do some cleanup
        file.close();
    	delete [] DomesticStudents;
    }
    // sort domestic students
    if (studentSelection == "I" || studentSelection == "O")
    {
        file = fileOpen("international-stu.txt");
        int numInternationalStudents = countLines(file) - 1;
        // declare some dynamic memory to the exact size of the number of students in the file
        InternationalStudent *InternationalStudents = new InternationalStudent[numInternationalStudents];
        // filtered international students contains only the students who passed the minimum toefl score requirements
        InternationalStudent *filteredInternationalStudents = new InternationalStudent[numInternationalStudents];
        // read the data from each file line into the DomesticStudents (this uses the user defined >> operator in DomesticStudent library)
        int i = 0;
        while(getline(file, line))
        {
            istringstream ss(line);
            ss >> InternationalStudents[i++];
        }
        // if overall sorting, sort by CGPA, then research score, then province
        if (studentSelection == "O") sortingSelection = "GRC";
        // sort the data
        sortBy(InternationalStudents, numInternationalStudents, sortingSelection, "ascending");
        // filter out the international students who didn't make the minimum toefl score requirements
        // but only filter when overall sorting
        int filteredIndex = 0;
        if (studentSelection == "O")
        {
            for (int j = 0; j < numInternationalStudents; j++)
            {
                if (InternationalStudents[j].getTotalScore() >= 93
                &&  InternationalStudents[j].getReading() >= 20
                &&  InternationalStudents[j].getListening() >= 20
                &&  InternationalStudents[j].getSpeaking() >= 20
                &&  InternationalStudents[j].getWriting() >= 20)
                {
                    filteredInternationalStudents[filteredIndex++] = InternationalStudents[j];
                }
            }
        }
        else
        {
            filteredInternationalStudents = InternationalStudents;
            filteredIndex = numInternationalStudents;
        }
        // print out the results
        cout << "\n\nSorted InternationalStudent Array:\n\n";
        for (int i = 0; i < filteredIndex; i++)
        {
            cout << setw(5) << left << i+1 << filteredInternationalStudents[i];
        }
        // do some cleanup
        file.close();
        if (filteredInternationalStudents != InternationalStudents) delete[] filteredInternationalStudents;
        delete [] InternationalStudents;
    }

    return 0;
}
