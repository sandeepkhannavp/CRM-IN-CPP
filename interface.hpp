
#include "interface.h"

void interface::handle_add_cust()
{
    std::string name, city, state;
    int last_visit, total_sales;
    int last_id = customer_table.get_max_id();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter Customer first and last name: ";
    std::getline(cin, name);
    cout << "Enter Customer City: ";
    std::getline(cin, city, '\n');
    cout << "Enter Customer State: ";
    std::getline(cin, state, '\n');
    cout << "Enter Customer's Last Visit (YYYYMMDD): ";
    cin >> last_visit;
    cout << "Enter Customer's Total Sales: ";
    cin >> total_sales;
    customer new_cust(last_id + 1, name, last_visit, total_sales, city, state);
    // The id of the new customer should be the max existing ID incremented by 1
    customer_table.insert_row(last_id + 1, new_cust);
}

void interface::handle_add_lead()
{
    std::string name, city, state;
    int last_visit, phone_number;
    int last_id = leads_table.get_max_id();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter lead's first and last name: ";
    std::getline(cin, name);
    cout << "Enter lead's City: ";
    std::getline(cin, city, '\n');
    cout << "Enter lead's State: ";
    std::getline(cin, state, '\n');
    cout << "Enter lead's Last Visit (YYYYMMDD): ";
    cin >> last_visit;
    cout << "Enter lead's Phone number: ";
    cin >> phone_number;
    lead new_lead(last_id + 1, name, last_visit, phone_number, city, state);
    // The id of the new customer should be the max existing ID incremented by 1
    leads_table.insert_row(last_id + 1, new_lead);
}

void interface::handle_add_salesrep()
{
    string name, tname;
    int n;
    vector<string> temp;
    cout << "Enter the name of the sales rep : ";
    cin >> name;
    leads_table.print_table(leads_table.get_max_id());
    cout << "Enter the number of leads you would like to add: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of the lead: ";
        cin >> tname;
        temp.push_back(tname);
    }
    salesrep.emplace(name, temp);
}

// deleting a customer from the table
void interface::handle_delete_cust()
{
    int delete_id;
    cout << "Enter customer ID to delete: ";
    cin >> delete_id;
    // Search table for the id
    auto search = customer_table.hashtable.find(delete_id);
    // If the id is found then carry out process else warn user
    if (search != customer_table.hashtable.end())
    {
        cout << "Found customer ID " << search->first << " with the following information: " << endl;
        cout << "Name: " << search->second.name << endl;
        cout << "City: " << search->second.city << endl;
        cout << "State: " << search->second.state << endl;
        cout << "Last Visit: " << search->second.format_date() << endl;
        cout << "Total Sales: $" << search->second.total_sales << endl;
        cout << "Are you sure you want to delete this customer? (Y or N)";
        string ans;
        cin >> ans;
        if (ans == "Y")
        {
            customer_table.hashtable.erase(search->first);
            cout << "Customer deleted." << endl;
        }
        else
        {
            cout << "Customer not deleted." << endl;
        }
    }
    else
    {
        cout << "No customer ID " + std::to_string(delete_id) + " exists." << endl;
    }
}

void interface::handle_delete_lead()
{
    int delete_id;
    cout << "Enter lead's ID to delete: ";
    cin >> delete_id;
    // Search table for the id
    auto search = leads_table.hashtable.find(delete_id);
    // If the id is found then carry out process else warn user
    if (search != leads_table.hashtable.end())
    {
        cout << "Found customer ID " << search->first << " with the following information: " << endl;
        cout << "Name: " << search->second.name << endl;
        cout << "City: " << search->second.city << endl;
        cout << "State: " << search->second.state << endl;
        cout << "Last Visit: " << search->second.format_date() << endl;
        cout << "Phone number: +91 " << search->second.phonenumber << endl;
        cout << "Are you sure you want to delete this lead? (Y or N)";
        string ans;
        cin >> ans;
        if (ans == "Y")
        {
            leads_table.hashtable.erase(search->first);
            cout << "lead deleted." << endl;
        }
        else
        {
            cout << "lead not deleted." << endl;
        }
    }
    else
    {
        cout << "No lead ID " + std::to_string(delete_id) + " exists." << endl;
    }
}

// Function to handle updating customer
void interface::handle_update_cust()
{
    int update_id;
    cout << "Enter customer ID to update: ";
    cin >> update_id;
    // Search for customer to update - if found carry out aciton else warn user
    auto search = customer_table.hashtable.find(update_id);
    if (search != customer_table.hashtable.end())
    {
        std::string name, city, state;
        int last_visit, total_sales;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Found customer ID " << search->first << endl;
        cout << "Enter updated name: (Currently: " << search->second.name << "): ";
        std::getline(cin, name);
        cout << "Enter updated city: (Currently: " << search->second.city << "): ";
        std::getline(cin, city);
        cout << "Enter updated state: (Currently: " << search->second.state << "): ";
        std::getline(cin, state);
        cout << "Enter updated last visit as YYYYMMDD (Currently: " << search->second.last_visit << "): ";
        cin >> last_visit;
        cout << "Enter updated total sales (Currently: " << search->second.total_sales << "): ";
        cin >> total_sales;
        search->second.name = name;
        search->second.city = city;
        search->second.state = state;
        search->second.last_visit = last_visit;
        search->second.total_sales = total_sales;
        cout << "Customer " << search->first << " updated." << endl;
    }
    else
    {
        cout << "No customer ID " + std::to_string(update_id) + " exists." << endl;
    }
}

void interface::handle_update_lead()
{
    int update_id;
    cout << "Enter lead ID to update: ";
    cin >> update_id;
    // Search for customer to update - if found carry out aciton else warn user
    auto search = leads_table.hashtable.find(update_id);
    if (search != leads_table.hashtable.end())
    {
        std::string name, city, state;
        int last_visit, phone_no;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Found lead ID " << search->first << endl;
        cout << "Enter updated name: (Currently: " << search->second.name << "): ";
        std::getline(cin, name);
        cout << "Enter updated city: (Currently: " << search->second.city << "): ";
        std::getline(cin, city);
        cout << "Enter updated state: (Currently: " << search->second.state << "): ";
        std::getline(cin, state);
        cout << "Enter updated last visit as YYYYMMDD (Currently: " << search->second.last_visit << "): ";
        cin >> last_visit;
        cout << "Enter updated phone number (Currently: " << search->second.phonenumber << "): ";
        cin >> phone_no;
        search->second.name = name;
        search->second.city = city;
        search->second.state = state;
        search->second.last_visit = last_visit;
        search->second.phonenumber = phone_no;
        cout << "Lead " << search->first << " updated." << endl;
    }
    else
    {
        cout << "No Lead ID " + std::to_string(update_id) + " exists." << endl;
    }
}

void interface::print_salesrep()
{
    cout << "\n\n";
    cout << "The leads assigned to sales rep's: \n";
    for (auto it = salesrep.begin(); it != salesrep.end(); it++)
    {
        cout << "Sales rep'name : " << it->first << endl;
        cout << "Leads assigned: \n";
        for (auto p : it->second)
        {
            cout << p << " , ";
        }
        cout << endl;
    }
    cout << endl;
}


//  showing options menu to user
void interface::show_options()
{
    cout << "What would you like to do?" << endl;
    cout << "1 - Add Customer" << endl
         << "2 - Update Customer" << endl
         << "3 - Show Customers Table" << endl
         << "4 - Delete Customer" << endl
         << "5 - Show total sales" << endl
         << "6 - Exit Program" << endl;
}

void interface::showlead__options()
{
    cout << "What would you like to do?" << endl;
    cout << "1 - Add Lead" << endl
         << "2 - Update Lead" << endl
         << "3 - Show Leads Table" << endl
         << "4 - Delete Lead" << endl
         << "5 - Make lead a Customer" << endl
         << "6 - Exit" << endl;
}

void interface::show_salesoptions()
{
    cout << "What would you like to do: " << endl;
    ;
    cout << "1 - Assign sales rep to Lead" << endl
         << "2 - Print Details:  " << endl
         << "3 -Exit\n";
}

int interface::make_choice()
{
    int c;
    cout << "1 - Customers" << endl;
    cout << "2 - Leads" << endl;
    cout << "3- Assign leads to sales rep" << endl;
    cout << "Enter your choice: ";
    cin >> c;
    return c;
}

void interface::add_cus_lead()
{
    string c;
    int id;
    cout << "Enter the lead id: ";
    cin >> id;
    auto search = leads_table.hashtable.find(id);
    if (search != leads_table.hashtable.end())
    {
        cout << "Found customer ID " << search->first << " with the following information: " << endl;
        cout << "Name: " << search->second.name << endl;
        cout << "City: " << search->second.city << endl;
        cout << "State: " << search->second.state << endl;
        cout << "Last Visit: " << search->second.format_date() << endl;
        cout << "Phone number: +91 " << search->second.phonenumber << endl;
        cout << "Are you sure you want to add this lead to list of customers? (Y or N)";
        string ans;
        cin >> ans;
        if (ans == "Y")
        {
            int last_id = customer_table.get_max_id();
            std::string name, city, state;
            int last_visit, total_sales;
            name = search->second.name;
            city = search->second.city;
            state = search->second.state;
            total_sales = 0;
            cout << "Enter today's date in YYYYMMDD";
            cin >> last_visit;
            customer new_cust(last_id + 1, name, last_visit, total_sales, city, state);
            // The id of the new customer should be the max existing ID incremented by 1
            customer_table.insert_row(last_id + 1, new_cust);
            leads_table.hashtable.erase(search->first);
            cout << "lead made a customer." << endl;
        }
        else
        {
            cout << "Lead not made a customer." << endl;
        }
    }
    else
    {
        cout << "No lead ID " + std::to_string(id) + " exists." << endl;
    }
}
// Function that handles showing user interface
void interface::show_interface()
{
    customer_table.print_table(customer_table.get_max_id());
    int overall;
    do
    {
        cout << "1- To start the CRM\n";
        cout << "2-To exit the CRM\n";
        cin >> overall;
        if (overall == 1)
        {
            int choice;
            int x = make_choice();
            if (x == 1)
            {
                // Run until user quits
                cout << "\n";
                do
                {
                    show_options();
                    cin >> choice;
                    // Add customer
                    if (choice == 1)
                    {
                        handle_add_cust();
                        customer_table.print_table(customer_table.get_max_id());
                    }
                    else if (choice == 2) // Update customer
                    {
                        handle_update_cust();
                    }
                    else if (choice == 3) // Show n rows of table
                    {
                        cout << "Select number of customers to show (Enter '*' to show all): " << endl;
                        string n_show;
                        cin >> n_show;
                        if (n_show == "*")
                        {
                            customer_table.print_table(customer_table.get_max_id());
                        }
                        else
                        {
                            customer_table.print_table(stoi(n_show));
                        }
                        customer_table.write_data();
                    }
                    else if (choice == 4) // Delete customer
                    {
                        handle_delete_cust();
                    }
                    else if (choice == 5)
                    {
                        cout << "Total company sales are: $"
                             << customer_table.get_total_sales() << endl;
                    }
                    else if (choice == 6) // Quit program
                    {
                        continue;
                    }
                    else
                    {
                        cout << "Please enter a number listed from the menu options (1-6)" << endl; // Fail safe
                    }
                } while (choice != 6);
            }
            else if (x == 2)
            {
                do
                {
                    showlead__options();
                    cin >> choice;
                    // Add lead
                    if (choice == 1)
                    {
                        handle_add_lead();
                        //leads_table.print_table(leads_table.get_max_id());
                    }
                    else if (choice == 2) // Update lead
                    {
                        handle_update_lead();
                    }
                    else if (choice == 3) // Show n rows of table
                    {
                        cout << "Select number of Leads to show (Enter '*' to show all): " << endl;
                        string n_show;
                        cin >> n_show;
                        if (n_show == "*")
                        {
                            leads_table.print_table(leads_table.get_max_id());
                        }
                        else
                        {
                            leads_table.print_table(stoi(n_show));
                        }
                        leads_table.write_data();
                    }
                    else if (choice == 4) // Delete lead
                    {
                        handle_delete_lead();
                    }
                    else if (choice == 5)
                    {
                        add_cus_lead();
                    }
                    else if (choice == 6) // Quit program
                    {
                        continue;
                    }
                    else
                    {
                        cout << "Please enter a number listed from the menu options (1-5)" << endl; // Fail safe
                    }
                } while (choice != 6);
            }
            else if (x == 3)
            {
                do
                {
                    show_salesoptions();
                    cin >> choice;
                    if (choice == 1)
                    {
                        handle_add_salesrep();
                    }
                    else if (choice == 2)
                    {
                        print_salesrep();
                    }
                    else if (choice == 3)
                    {
                        continue;
                    }

                } while (choice != 3);
            }
        }
        else if (overall == 2)
            continue;
    } while (overall != 2);
}