#include <iostream>
#include "CommandLine.h"

int main(int argl, char** argc) {
    CommandLine line;
    line.parseCommandLine(argl,argc);

    if(line.has("namen")){
        std::cout<<"Namen \n"<<std::endl;
        auto names=line.get("namen");
        for(auto& name : names.getParams())
            std::cout<<name<<std::endl;
    }
    return 0;
}