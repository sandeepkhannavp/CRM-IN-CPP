#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include "lead_table.h"

int lead_table::get_max_id()
{
  return hashtable.end()->first;
}
/*int lead_table::get_max_id()
{
  int max_id = 0;
  for (auto it = hashtable.begin(); it != hashtable.end(); ++it)
  {
    if (it->second.id > max_id)
    {
      max_id = it->second.id;
    }
  }
  return max_id;
} */

void lead_table::print_table(int n_rows)
{
  // Main Header
  cout << std::left << "|" << std::setw(85) << std::setfill('-') << "-"
       << "|" << endl
       << "|" << std::setw(85) << std::setfill(' ') << " "
       << "|" << endl
       << "|" << std::setw(85) << "Customer Management System"
       << "|" << endl
       << "|" << std::setw(85) << std::setfill(' ') << " "
       << "|" << endl;

  // Start headers line
  cout << "|" << std::setw(5) << std::setfill('=') << "="
       << "|" << std::setw(20) << "="
       << "|" << std::setw(15) << "="
       << "|" << std::setw(10) << "="
       << "|" << std::setw(15) << "="
       << "|" << std::setw(15) << "="
       << "|" << std::setfill(' ') << endl;

  // Column headers
  std::cout << std::left
            << "|" << std::setw(5) << "ID"
            << "|" << std::setw(20) << "Name"
            << "|" << std::setw(15) << "City"
            << "|" << std::setw(10) << "State"
            << "|" << std::setw(15) << "Last Visit"
            << "|" << std::setw(15) << "Phone number"
            << "|" << endl
            << "|" << std::setw(5) << std::setfill('=') << "="
            << "|" << std::setw(20) << "="
            << "|" << std::setw(15) << "="
            << "|" << std::setw(10) << "="
            << "|" << std::setw(15) << "="
            << "|" << std::setw(15) << "="
            << "|" << std::setfill(' ') << endl;
  int iter = 0;
  // Print table rows
  for (auto it = hashtable.begin(); it != hashtable.end(); ++it, ++iter)
  {
    if (iter == n_rows)
    {
      cout << "Showing " + std::to_string(iter) + " of " + std::to_string(hashtable.size()) + " customers." << endl;
      break;
    }
    cout << std::left
         << "|" << std::setw(5) << it->first
         << "|" << std::setw(20) << it->second.name
         << "|" << std::setw(15) << it->second.city
         << "|" << std::setw(10) << it->second.state
         << "|" << std::setw(15) << it->second.format_date()
         << "|" << std::setw(15) << "+91" + std::to_string(it->second.phonenumber)
         << "|" << endl
         << "|" << std::setw(5) << std::setfill('-') << "-"
         << "|" << std::setw(20) << "-"
         << "|" << std::setw(15) << "-"
         << "|" << std::setw(10) << "-"
         << "|" << std::setw(15) << "-"
         << "|" << std::setw(15) << "-"
         << "|"
         << std::setfill(' ')
         << endl;
  }
  if (iter >= hashtable.size())
  {
    cout << "Showing all customers" << endl;
  }
}

void lead_table::write_data()
{
  // Use of stream to output to filename, truncate before writing
  std::ofstream ofs;
  // Open stream with trunc option to erase old data
  ofs.open(lead_table::filename, ofstream::trunc);
  for (auto it = hashtable.begin(); it != hashtable.end(); ++it)
  {
    // Write each item in cust table to csv
    ofs << it->first << ',';
    ofs << it->second.name << ',';
    ofs << it->second.city << ',';
    ofs << it->second.state << ',';
    ofs << it->second.last_visit << ',';
    ofs << it->second.phonenumber;
    ofs << endl;
  }
  ofs.close();
}

void lead_table::read_data()
{
  std::ifstream ifs;
  std::string line;
  ifs.open(lead_table::filename, ios::in);
  while (std::getline(ifs, line))
  {
    std::stringstream ss(line);
    std::string id, name, city, state, last_visit, phone_number;

    std::getline(ss, id, ',');
    std::getline(ss, name, ',');
    std::getline(ss, city, ',');
    std::getline(ss, state, ',');
    std::getline(ss, last_visit, ',');
    std::getline(ss, phone_number, ',');

    lead cust(std::stoi(id), name, std::stoi(last_visit), std::stoi(phone_number), city, state);
    lead_table::insert_row(std::stoi(id), cust);
  }
}