#ifndef __lead_table_H_INCLUDED__
#define __lead_table_H_INCLUDED__

#include <iostream>
#include "table.h"
#include "lead.hpp"

using namespace std;

class lead_table : public table<int, lead>
{
public:
  std::string filename;

  // Constructor - assign params and fill table with data on class creation
  lead_table(std::string i_filename)
      : filename(i_filename)
  {
    lead_table::read_data();
  };
  // Destructor - save the data to local db and empty out in memory table
  ~lead_table()
  {
    write_data();
    hashtable.clear();
  }
  // Member functions
  void print_table(int n_rows);
  void read_data();
  void write_data();
  int get_max_id();
  int get_total_sales();
};

// Because this class inherits from a template class, we include class definitions script at bottom
#include "lead_table.hpp"

#endif