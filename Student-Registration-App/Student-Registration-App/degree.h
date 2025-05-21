#pragma once

#include <string>

// enumerated data type for security, network, software
enum DegreeProgram {
    SECURITY,
    NETWORK,
    SOFTWARE,
    NONE
};

static const char* degreeProgramStrings[] = {
    "SECURITY", 
    "NETWORK", 
    "SOFTWARE", 
    "NONE" 
};