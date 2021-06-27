#include "lead.h"
#include <string>

std::string lead::format_date()
{
    std::string date = std::to_string(lead::last_visit);
    std::string date_form = date.substr(0,4) + "-" + date.substr(4,2) + "-" + date.substr(6,2);
    return date_form;
}