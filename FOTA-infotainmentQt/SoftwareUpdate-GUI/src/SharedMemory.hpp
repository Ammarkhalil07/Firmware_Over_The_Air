#pragma once

/********INCLUDES***********/
#include <boost/interprocess/detail/os_file_functions.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

#include <fcntl.h>

#include <sys/wait.h>
#include <thread>
using namespace boost::interprocess;
/*********************/




class SharedMemory {
public:
    SharedMemory(const std::string& path);
    virtual int write_mem() = 0;
    virtual int read_mem()=0;
    virtual ~SharedMemory();
protected:
    std::string filePath;  // File path used for shared memory operations
private:
    std::ofstream logFile;
    std::streambuf* coutbuf;
};

class WriteSection : public SharedMemory {
public:
    WriteSection(const std::string& path);

    int write_mem();

    int read_mem();

    ~WriteSection();
};

class ReadSection : public SharedMemory
{
    public:
    ReadSection(const std::string& path);

    int read_mem();
    int write_mem();

    ~ReadSection();

};


