#include "SummarySheets.hpp"

SummarySheets::SummarySheets() {
    this->name = "Summary Sheets";
}

SummarySheets::~SummarySheets() {
    
}

string SummarySheets::getRules() {
    return rules;
}

string SummarySheets::getName() {
    return name;
}
