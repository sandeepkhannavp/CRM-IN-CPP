#include "feedback.h"

void Feedback::write_feedback()
{
  std::ofstream fout;
  fout.open("Feedback.txt", std::ios::app);
  fout << review << "\t" << feedback << std::endl;
  fout.close();
}