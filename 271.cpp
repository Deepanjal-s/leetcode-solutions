#include <iostream>
#include <vector>

int main(){
    std::vector<std::string> str = {"my","name","is","deepanjal","shukla"};
    std::vector<std::string> has;
    std::vector<std::string> dhas;
    
    for(auto st : str){
        has.push_back(st);
        has.push_back("#");
    }

    for(auto st : str){
        if(st != "#"){
            dhas.push_back(st);
        }
    }

    for(auto st : str){
        std::cout << " " << st;
    }
    
    return 0;
}
