#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>

class TestCase
{
    public:

        TestCase (std::string caseName);
        ~TestCase();

        void test (std::string testName, std::string message, int result);
        void test (std::string testName, int result);
        void results ();

    private:

        std::string caseName_;        
        unsigned short failures_;     
        unsigned short successes_;
        unsigned short testCount_;

};

#endif