#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <fstream>
#include <iostream>

class Basic_Character_Devices
{
private:
    const std::string PATH;
    std::fstream fileDescriptor;

public:
    void WriteFile (std::string message);
    std::string ReadFile (void);
    Basic_Character_Devices(std::string devicePath);
};
#endif // LEDDRIVER_H
