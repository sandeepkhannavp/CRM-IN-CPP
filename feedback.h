#ifndef __cust_table_H_INCLUDED__ 
#define __cust_table_H_INCLUDED__ 
#include <bits/stdc++.h>

class Feedback
{
    public:
        std::string feedback,review;
        void write_feedback();
        Feedback(std::string feed_back,std::string re_view):feedback(feed_back),review(re_view){}
};


#endif