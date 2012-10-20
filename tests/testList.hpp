#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "../src/List.hpp"

void testList ( void )
{
    TestCase t ("List");

        List<int> l;
        List<int>::iterator it;
        l.insert_front(10);
        t.test ("Inserted 10 to front", "Front should be 10", (l.pHead_->data == 10) );
        l.insert_front(9);
        t.test ("Inserted 9 to front", "Front should be 9", (l.pHead_->data == 9) );

        l.insert_back(11);
        t.test ("Inserted 9 to front", "Front should be 9", (l.pHead_->data == 9) );

        // end() points to node after end
        it = --l.end(); // so we have to remove one from it to get to the last node
        t.test ("Iterator", "end(), value should be 11", (*it == 11) );
        t.test ("Iterator", "-- operator, value should be 10", (*(--it) == 10) );

        it = l.begin();
        t.test ("Iterator", "begin(), value should be 11", (*it == 9) );
        t.test ("Iterator", "++ operator, value should be 10", (*(++it) == 10) );
        l.empty();
        
        t.test ("empty", "size should now be 0", ( l.size() == 0 ) ); 
        t.test ("empty", "and begin should equal end", ( l.begin() == l.end() ) );

    t.results();
    
}

#endif
