#include "LedDriver.h"

Basic_Character_Devices::Basic_Character_Devices(std::string devicePath):PATH(devicePath){}

void Basic_Character_Devices::WriteFile(std::string message)
{
    fileDescriptor.open(PATH, std::ios::out);

    message = message + "\n";

    fileDescriptor.write(message.c_str(), message.size());

    fileDescriptor.close();
}

std::string Basic_Character_Devices::ReadFile(void)
{
    std::string result;

    fileDescriptor.open(PATH);

    std::getline (fileDescriptor, result);

    fileDescriptor.close();

    return result;
}
