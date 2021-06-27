#include <iostream>
#include <fstream>

using namespace std;

class lead {
    public:
        int id;
        string name;
        string city;
        string state;
        int last_visit;
        int phonenumber;

    lead(int i_id,string i_name,int i_last_visit,int i_phone_number=0,string i_city="NULL",string i_state="NULL")
        :id(i_id),
        name(i_name),
        last_visit(i_last_visit),
        phonenumber(i_phone_number),
        city(i_city),
        state(i_state)
    {
    }
    
    void show_customer();
    std::string format_date();
};

