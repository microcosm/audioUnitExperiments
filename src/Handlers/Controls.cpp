#include "Controls.h"

string Controls::report() {
    stringstream report;
    report << "CONTROLS" << endl
    << endl << "LEFT/RIGHT: Switch presets"
    << endl << "UP/DOWN:    Switch notes"
    << endl << "SPACE:      Start/stop playing"
    << endl << "u:          Show UI"
    << endl << "s:          Save preset";
    return report.str();
}