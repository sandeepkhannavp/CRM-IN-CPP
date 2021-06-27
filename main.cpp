#include <bits/stdc++.h>
#include <map>
#include "interface.hpp"
using namespace std;

int main()
{
    string username, password;
    string admin1 = "Sandeep";
    string admin2 = "Dharun";
    string pass1 = "admin1";
    string pass2 = "admin2";
    map<string, string> userpass;
    userpass.emplace(admin1, pass1);
    userpass.emplace(admin2, pass2);
    map<string, string>::iterator itr;
    // Initialize the customer table
    cout << "Enter the username: ";
    cin >> username;
    cout << "Enter the password: ";
    bool access = false;
    cin >> password;
    for (itr = userpass.begin(); itr != userpass.end(); ++itr)
    {
        if (itr->first == username && itr->second == password)
            access = true;
    }
    if (access == true)
    {
        cust_table table("cust_data.csv");
        lead_table ltable("lead_data.csv");
        // Create an interface object
        interface main_menu(table, ltable);
        // Run the main interface process
        main_menu.show_interface();
        return 0;
    }
}
