#include <iostream>
#include "Pipe.hpp"





int main()
{
        try 
    {
        MyPipe new_pipe("ifconfig wlp0s20f3"); 
        new_pipe.pipe_command();
        std::cout << new_pipe.print_output() << std::endl;
        new_pipe.search_pipe("inet");
        if(new_pipe.search_pipe("inet"))
        {
            std::cout << "/* message */" << std::endl;
        }
        
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return 1;
    }
 





    return 0;
}