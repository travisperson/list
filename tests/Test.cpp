#include "Test.h"

//  Name           - TestCase
//  Description    - Default Constructor
//  Input          -
//  Preconditions  -
//  Postconditions -
//______________________________________________________________________________
TestCase::TestCase (std::string caseName)
{
    this->caseName_        = caseName;
    this->failures_        = 0;
    this->successes_    = 0;
    this->testCount_    = 0;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "[" << this->caseName_ << "] - Test Case" << std::endl;

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
TestCase::test (std::string testName, std::string message, int result)
{
    this->testCount_++;

    if (result)
    {
        this->successes_++;
        std::cout << "   o - [" << testName << "] - " << message << std::endl;
    }
    else
    {
        this->failures_++;
        std::cout << "   x - [" << testName << "] - " << message << std::endl;
    }
}

//  Name           - test
//  Description    - runs a test, and prints statments accordingly
//  Input          - Test name and result of test
//  Preconditions  -
//  Postconditions -
//______________________________________________________________________________
void
TestCase::test (std::string testName, int result)
{
    this->testCount_++;

    if (result)
    {
        this->successes_++;
        std::cout << "   o - [" << testName << "]" << std::endl;
    }
    else
    {
        this->failures_++;
        std::cout << "   x - [" << testName << "]" << std::endl;
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
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Test Case Results [" << this->caseName_ << "]" << std::endl;
    std::cout << "  Successes   - " << this->successes_ << std::endl;
    std::cout << "  Failures    - " << this->failures_  << std::endl;
    std::cout << std::endl;
    std::cout << "Total Tests - "   << this->testCount_ << std::endl;
    std::cout << std::endl;
    std::cout << "=======================================================" << std::endl;
    std::cout << std::endl;
}
