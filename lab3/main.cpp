/*
 *  - main.cpp -
 * ENSC 251 - Lab Assignment 3
 * July 4, 2019
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
#include "student_lists.hpp"

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

/* int checkToeflScoreRequirement(InternationalStudent internationalStudent)
 * brief: check if the toefl score requirement is met for a given international student
 * pre: internationalStudent - the international student to be tested
 * post: returns 0 if the requirement was not met, 1 if the requirement was met
 */
int checkToeflScoreRequirement(InternationalStudent internationalStudent)
{
    if (internationalStudent.getReading() < 20) return 0;
    if (internationalStudent.getListening() < 20) return 0;
    if (internationalStudent.getSpeaking() < 20) return 0;
    if (internationalStudent.getWriting() < 20) return 0;
    if (internationalStudent.getTotalScore() < 93) return 0;
    return 1;
}

/* int dispMatching(GenericStudent_ListNode* studentHead, string studentSelection, string searchType, string param1, string param2)
 * brief: search and print students in a linked list who matching parameters given (as arguments)
 * pre: *studentHead - pointer to the head of the linked list
        studentSelection - "D" selects only domestic students
                           "I" selects only international students
                           "A" selects all students
        searchType - "FL" searches by first and last name
                     "GR" searches by CGPA and research score
        param1 - in mode "FL": we are searching for students with the same first name as param1
                 in mode "GR": we are searching for students with the same cgpa as param1 (the float is passed as a string)
        param2 - in mode "FL": we are searching for students with the same last name as param2
                 in mode "GR": we are searching for students with the same research score as param2 (the int is being passed as a string)
        Note - if param1 or param2 are "*", that is a wildcard and the search function will ignore that parameter for the search
        e.g. "FL=*,White" will search for any student with the last name "White", regardless of their first name
        Note - this function is not case sensitive, so if the user types "wHITE", "White" will still be a match
 * post: returns the number of students who were found in the linked list using the given parameters
 */
int dispMatching(GenericStudent_ListNode* studentHead, string studentSelection, string searchType, string param1, string param2)
{
    int numStudents = 0;
    GenericStudent_ListNode* searchNode = studentHead;
    // don't bother searching if the parameters don't do anything anyways
    if (studentSelection != "D" && studentSelection != "I" && studentSelection != "A")
    {
        cout << "\nInvalid student selection. Nothing will be printed.\n";
        return 0;
    }
    // search all students
    while(searchNode != NULL)
    {
        // match1 and match2 are true when either the wildcard is present, or if the parameters match
        // either for the domesitc student or for the international student
        int match1 = 0, match2 = 0;
        if (searchType == "GR")
        {
            if (param1 == "*" || searchNode->domesticStudent.getCGPA() == stof(param1) || searchNode->internationalStudent.getCGPA() == stof(param1)) match1 = 1;
            if (param2 == "*" || searchNode->domesticStudent.getResearchScore() == stoi(param2) || searchNode->internationalStudent.getResearchScore() == stoi(param2)) match2 = 1;
        }
        else if (searchType == "FL")
        {
            if (param1 == "*" || !(compareTwoStrings(searchNode->domesticStudent.getFirstName(), param1)) || !(compareTwoStrings(searchNode->internationalStudent.getFirstName(), param1))) match1 = 1;
            if (param2 == "*" || !(compareTwoStrings(searchNode->domesticStudent.getLastName(), param2)) || !(compareTwoStrings(searchNode->internationalStudent.getLastName(), param2))) match2 = 1;
        }
        else
        {
            // don't bother continuing if the user didn't type "FL" or "GR"
            // since the result is 0 anyways
            cout << "\nInvalid search selection. Nothing will be printed.\n";
            break;
        }
        if (match1 && match2)
        {
            // if there's a match
            // initialize a blank domestic student and a blank international student
            DomesticStudent blankDomesticStudent;
            InternationalStudent blankInternationalStudent;
            // we have to make sure that if we wanted only domestic students, then only domestic students show a match
            // because the above code triggers a match for any student, we must filter them now
            if (!(searchNode->internationalStudent == blankInternationalStudent) && (studentSelection == "I" || studentSelection == "A"))
            {
                cout << setw(5) << left << ++numStudents;
                cout << searchNode->internationalStudent;
            }
            else if (!(searchNode->domesticStudent == blankDomesticStudent) && (studentSelection == "D" || studentSelection == "A"))
            {
                cout << setw(5) << left << ++numStudents;
                cout << searchNode->domesticStudent;
            }
        }
        searchNode = searchNode->nextNode;
    }
    return numStudents;
}

/* void addNode(GenericStudent_ListNode** headPtr, DomesticStudent tmpStudent)
 * brief: add a new node to the linked list
 * pre: **headPtr - a pointer to the pointer of the linked list, use a double pointer
        so that we can modify where the head pointer actually points
        tmpStudent - the student that we wish to add to the list
 * post: nothing
 */
void addNode(GenericStudent_ListNode** headPtr, DomesticStudent tmpStudent)
{
    GenericStudent_ListNode* newHead = new GenericStudent_ListNode;
    newHead->domesticStudent = tmpStudent;
    newHead->nextNode = (*headPtr);
    (*headPtr) = newHead;
}

/* void addNode(GenericStudent_ListNode** headPtr, InternationalStudent tmpStudent)
 * brief: add a new node to the linked list
 * pre: **headPtr - a pointer to the pointer of the linked list, use a double pointer
        so that we can modify where the head pointer actually points
        tmpStudent - the student that we wish to add to the list
 * post: nothing
 */
void addNode(GenericStudent_ListNode** headPtr, InternationalStudent tmpStudent)
{
    GenericStudent_ListNode* newHead = new GenericStudent_ListNode;
    newHead->internationalStudent = tmpStudent;
    newHead->nextNode = (*headPtr);
    (*headPtr) = newHead;
}

/* int deleteNode(GenericStudent_ListNode** studentHead, string studentType, string firstName, string lastName)
 * brief: delete a node from the linked list
 * pre: **studentHead - a pointer to the pointer of the linked list, use a double pointer
        so that we can modify where the head pointer actually points
        studentType - passing "D" makes it possible to only remove domestic students
                      passing "I" makes it possible to only remove international students
                      passing "A" makes it possible to remove all students, regardless of their type
 * post: returns the number of students who were deleted from the list
 */
int deleteNode(GenericStudent_ListNode** studentHead, string studentType, string firstName, string lastName)
{
    GenericStudent_ListNode* searchNode = (*studentHead);
    int numStudents = 0;
    // satisfy initial case then carry on
    // this is different because it moves the head pointer
    if (((studentType == "D" || studentType == "A")
    && searchNode->domesticStudent.getFirstName() == firstName
    && searchNode->domesticStudent.getLastName() == lastName)
    || ((studentType == "I" || studentType == "A")
    && searchNode->internationalStudent.getFirstName() == firstName
    && searchNode->internationalStudent.getLastName() == lastName))
    {
        // match found
        GenericStudent_ListNode* currNode = searchNode;
        GenericStudent_ListNode* nextNode = searchNode->nextNode;
        // move head to next node
        (*studentHead) = nextNode;
        // delete it
        delete currNode;
        numStudents++;
    }
    // do the rest of the nodes
    while (searchNode->nextNode != NULL)
    {
        if (((studentType == "D" || studentType == "A")
        && searchNode->nextNode->domesticStudent.getFirstName() == firstName
        && searchNode->nextNode->domesticStudent.getLastName() == lastName)
        || ((studentType == "I" || studentType == "A")
        && searchNode->nextNode->internationalStudent.getFirstName() == firstName
        && searchNode->nextNode->internationalStudent.getLastName() == lastName))
        {
            // match found
            GenericStudent_ListNode* currNode = searchNode->nextNode;
            GenericStudent_ListNode* nextNode = searchNode->nextNode->nextNode;
            // delete reference to this node, free it from memory
            delete currNode;
            searchNode->nextNode = nextNode;
            numStudents++;
        }
        // this is a catch for the end case
        if (searchNode->nextNode != NULL) searchNode = searchNode->nextNode;
    }
    return numStudents;
}

int main()
{
    // ********************************* Initialize files and lists ********************************* //
    ifstream file;
    string line;
    GenericStudent_ListNode* domesticStudentHead = NULL;
    // open the domestic file
    file = fileOpen("domestic-stu.txt");
    // discard the formatting line
    getline(file, line);
    // read the rest of the lines in the file
    while(getline(file, line))
    {
        DomesticStudent tmpStudent;
        istringstream ss(line);
        ss >> tmpStudent;
        // add the new student
        addNode(&domesticStudentHead, tmpStudent);
        // sort the new list, every time we add a new node
        sortBy(&domesticStudentHead, "GRP", "descending");
    }
    // close the file because we are done with it
    file.close();
    cout << "DomesticStudent Linked List Initialized.\n";

    GenericStudent_ListNode* internationalStudentHead = NULL;
    // open the international file
    file = fileOpen("international-stu.txt");
    // discard the formatting line
    getline(file, line);
    // read the rest of the lines in the file
    while(getline(file, line))
    {
        InternationalStudent tmpStudent;
        istringstream ss(line);
        ss >> tmpStudent;
        // check minimum toefl score requirements
        if (checkToeflScoreRequirement(tmpStudent))
        {
            // add the new student
            addNode(&internationalStudentHead, tmpStudent);
            // sort the new list, every time we add a new node
            sortBy(&internationalStudentHead, "GRC", "descending");
        }
    }
    // close the file because we are done with it
    file.close();
    cout << "InternationalStudent Linked List Initialized.\n";
    // ********************************* Create generic list that holds all students ********************************* //
    // make a list head that holds everyone
    GenericStudent_ListNode* studentHead = domesticStudentHead;
    // merge the lists
    GenericStudent_ListNode* searchNode = domesticStudentHead;
    while (searchNode->nextNode != NULL) searchNode = searchNode->nextNode;
    searchNode->nextNode = internationalStudentHead;
    // sort everyone according to the modified overall sort (X denotes the modified overall sort)
    sortBy(&studentHead, "GRX", "descending");
    // ********************************* Infinite loop, user can do multiple things during execution ********************************* //
    while (1)
    {
        // ********************************* Prompt user to select action ********************************* //
        cout << "\nWhat would you like to do: Add Node (A), Remove Node (R), Search Existing Nodes (S), Print Nodes (P), Exit (X)\n>> ";
        string typeSelection;
        cin >> typeSelection;
        // ********************************* Close the program ********************************* //
        if (typeSelection == "X") break;
        // ********************************* Add a new student ********************************* //
        else if (typeSelection == "A")
        {
            cout << "\nPlease enter the type of the new student: Domestic student (D), International Student (I)\n>> ";
            string studentType;
            cin >> studentType;
            // paramters to hold the values for the new student
            string firstName, lastName;
            string countryProvince;
            float cgpa;
            int researchScore, readingScore, listeningScore, speakingScore, writingScore;
            // these parameters are common for both types of student
            cout << "\nPlease enter the first name of the new student:\n>> ";
            cin >> firstName;
            cout << "\nPlease enter the last name of the new student:\n>> ";
            cin >> lastName;
            cout << "\nPlease enter the CGPA of the new student:\n>> ";
            cin >> cgpa;
            cout << "\nPlease enter the research score of the new student:\n>> ";
            cin >> researchScore;
            // these paramters are specific to the domestic or international students
            if (studentType == "D")
            {
                cout << "\nPlease enter the province of the new student:\n>> ";
                cin >> countryProvince;
                // initialize a new domestic student with the parameters given
                DomesticStudent tmpStudent(firstName, lastName, countryProvince, cgpa, researchScore);
                // add the node then sort the list again according to the modified overall sort
                addNode(&studentHead, tmpStudent);
                sortBy(&studentHead, "GRP", "descending");
            }
            else if (studentType == "I")
            {
                cout << "\nPlease enter the country of the new student:\n>> ";
                cin >> countryProvince;
                cout << "\nPlease enter the reading score of the new student:\n>> ";
                cin >> readingScore;
                cout << "\nPlease enter the listening score of the new student:\n>> ";
                cin >> listeningScore;
                cout << "\nPlease enter the speaking score of the new student:\n>> ";
                cin >> speakingScore;
                cout << "\nPlease enter the writing score of the new student:\n>> ";
                cin >> writingScore;
                // initialize a new international student with the parameters given
                InternationalStudent tmpStudent(firstName, lastName, countryProvince, cgpa, researchScore, readingScore, listeningScore, speakingScore, writingScore);
                // add the node then sort the list again according to the modified overall sort
                addNode(&studentHead, tmpStudent);
                sortBy(&studentHead, "GRC", "descending");
            }
            else
            {
                cout << "\nYour input was invalid. Please try again.\n";
            }
        }
        // ********************************* Remove a Student ********************************* //
        else if (typeSelection == "R")
        {
            cout << "\nPlease enter the type of the students to be searched: Domestic student (D), International Student (I), All Students (A)\n>> ";
            string studentType;
            cin >> studentType;
            // parameters hold the first and last name of the student to remove
            string firstName, lastName;
            cout << "\nPlease enter the name of the student(s) you wish to delete, separated by a space.\n>> ";
            cin >> firstName >> lastName;
            // delete the students that match the parameters given, and print out how many students were deleted after
            int numStudents = deleteNode(&studentHead, studentType, firstName, lastName);
            cout << "\nDeleted " << numStudents << " student(s)\n";
        }
        // ********************************* Print Students ********************************* //
        else if (typeSelection == "P")
        {
            cout << "\nPlease enter the list you wish to print: Domestic student (D), International Student (I), Merge All Students (A)\n>> ";
            string studentType;
            cin >> studentType;
            // "FL" doesn't matter in this case, the point is to just reuse the function to display everyone
            dispMatching(studentHead, studentType, "FL", "*", "*");
        }
        // ********************************* Search Students ********************************* //
        else if (typeSelection == "S")
        {
            cout << "\nSearch type: Domestic Students (D), International Students (I), All Students (A)\n>> ";
            string studentSelection;
            cin >> studentSelection;
            cout << "\nSearch by: CGPA & ResearchScore (GR=cgpa researchscore), First Name & Last Name(FL=firstname lastname)\n>> ";
            string searchSelection;
            cin >> searchSelection;
            // parse the input
            istringstream ss(searchSelection);
            string searchType, param1, param2;
            getline(ss, searchType, '=');
            if (searchType != "FL" && searchType != "GR")
            {
                cout << "Your input was invalid. Please try again.\n";
                continue;
            }
            getline(ss, param1, ',');
            getline(ss, param2);
            cout << "\nResults:\n\n";
            // show the students who match the user input
            int numStudents = dispMatching(studentHead, studentSelection, searchType, param1, param2);
            // show the number of students who were found
            cout << "\nFound: " << numStudents << " student(s).\n";
        }
        // ********************************* Invalid Input ********************************* //
        else cout << "Your input was invalid. Please try again.\n";
    }
    // end of program, student head isn't required anymore
    // so as we delete the nodes, keep moving the student head forward
    while (studentHead != NULL)
    {
        GenericStudent_ListNode* nodeToDelete = studentHead;
        studentHead = studentHead->nextNode;
        delete nodeToDelete;
    }
    return 0;
}
