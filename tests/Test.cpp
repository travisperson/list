#include "Test.hpp"

//  Name           - TestCase
//  Description    - Default Constructor
//  Input          -
//  Preconditions  -
//  Postconditions -
//______________________________________________________________________________
TestCase::TestCase (string caseName)
{
    this->caseName_        = caseName;
    this->failures_        = 0;
    this->successes_    = 0;
    this->testCount_    = 0;


    cout << endl;
    cout << endl;
    cout << "=======================================================" << endl;
    cout << endl;
    cout << "[" << this->caseName_ << "] - Test Case" << endl;

}

//  Name           - ~TestCase
//  Description    - Destructore
//  Input          -
//  Preconditions  -
//  Postconditions -
//______________________________________________________________________________
TestCase::~TestCase ()
{
}

//  Name           - test
//  Description    - runs a test, and prints statments accordingly
//  Input          - Test name, message and result of test
//  Preconditions  -
//  Postconditions -
//______________________________________________________________________________
void
TestCase::test (string testName, string message, int result)
{
    this->testCount_++;

    if (result)
    {
        this->successes_++;
        cout << "   o - [" << testName << "] - " << message << endl;
    }
    else
    {
        this->failures_++;
        cout << "   x - [" << testName << "] - " << message << endl;
    }
}

//  Name           - test
//  Description    - runs a test, and prints statments accordingly
//  Input          - Test name and result of test
//  Preconditions  -
//  Postconditions -
//______________________________________________________________________________
void
TestCase::test (string testName, int result)
{
    this->testCount_++;

    if (result)
    {
        this->successes_++;
        cout << "   o - [" << testName << "]" << endl;
    }
    else
    {
        this->failures_++;
        cout << "   x - [" << testName << "]" << endl;
    }
}

//  Name           - results
//  Description    - Prints results of the test case
//  Input          -
//  Preconditions  -
//  Postconditions -
//______________________________________________________________________________
void
TestCase::results ()
{
    cout << endl;
    cout << endl;
    cout << "Test Case Results [" << this->caseName_ << "]" << endl;
    cout << "  Successes   - " << this->successes_ << endl;
    cout << "  Failures    - " << this->failures_  << endl;
    cout << endl;
    cout << "Total Tests - "   << this->testCount_ << endl;
    cout << endl;
    cout << "=======================================================" << endl;
    cout << endl;
}
