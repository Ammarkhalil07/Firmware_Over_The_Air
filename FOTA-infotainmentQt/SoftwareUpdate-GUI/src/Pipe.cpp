#include "Pipe.hpp"

MyPipe::MyPipe(std::string cmd):pipecmd(cmd){
    std::cout << "Pipe constructor" << std::endl;
}


std::string MyPipe::pipe_command()
{

    /****************Buffer to save output in it*******************/
    std::array<char, 256> buffer;
    /****************Result will have buffer output*******************/
    std::string result;

    /****************Unique Ptr is used for RAII*******************/

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(pipecmd.c_str(), "r"), pclose);
    // FILE * pipe1= popen(cmd.c_str(), "r");
    /******************Check if pipe is nullptr pointing to addr 0*********************************************/
    if (pipe==nullptr) {
        throw std::runtime_error("popen() failed!");
    }

    /******************Get lines from pipe by using fgets **  get() will return pointer of pipe*******************************************/

    while (fgets(buffer.data(), 256, pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string MyPipe::print_output()
{
    output= pipe_command();

    return output;

}

int MyPipe::search_pipe(const std::string& word)
{   output= pipe_command();
    int found=0;
    if(output.find(word) !=std::string::npos)
    {
        std::cout<<"found"<<std::endl;
        found =1;
    }
    else
    {
        /***************Throw err and get it by try & catch if happened*********************/
        // throw std::runtime_error("not found");
        found=0;

    }
    return found;
}

MyPipe::~MyPipe(){std::cout << "Pipe Destructor" << std::endl;}
