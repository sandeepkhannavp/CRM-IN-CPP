/* Interface class
Handles table interface and user inputs */

#include <bits/stdc++.h>
#include "cust_table.h"
#include "lead_table.h"
using namespace std;

class interface
{
public:
    // Pointer to customer table - all input actions will affect this table
    cust_table &customer_table;
    lead_table &leads_table;
    map<string, vector<string>> salesrep;

    interface(cust_table &i_cust_table, lead_table &i_lead_table)
        : customer_table(i_cust_table), leads_table(i_lead_table){};

    void show_interface();
    int make_choice();
    void show_options();
    void handle_add_cust();
    void handle_update_cust();
    void handle_delete_cust();
    void handle_add_lead();
    void handle_update_lead();
    void handle_delete_lead();
    void add_cus_lead();
    void showlead__options();
    void handle_add_salesrep();
    void print_salesrep();
    void show_salesoptions();
    void add_feedback();
};