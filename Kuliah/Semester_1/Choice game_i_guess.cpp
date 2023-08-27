//iostream adalah library standard untuk c++
#include <iostream>

//using namespace std;

//prototype function
int decide (int, int);
void overall(int);

int main(){
    int affection=0, choice;
    affection=decide(choice, affection);
    //decide(choice, affection);

    std::cout<<"fuck\n";
    overall(affection);

    return 0;
}

//parameter formal
int decide (int choice, int affection){
    std::cout<<"Hallo!\n";
    std::cout<<"What's your reaction?\n";
    std::cout<<"1. Bitch!\n";
    std::cout<<"2. Umm, hallo\n";
    std::cout<<"3. Sup!\n";
    std::cout<<"\n";
    std::cin>>choice;
    switch(choice){
        case 1: 
        std::cout<<"Whats your problem cunt?\n";
        affection--;
        break;

        case 2: 
        std::cout<<"tsundere one, eh?\n";
        affection++;
        break;

        case 3: 
        std::cout<<"smooth one, eh?\n";
        affection+2;
        break;

        default: 
        std::cout<<"what?\n";

    }

    return(affection);
}

void overall(int affection){
    
    std::cout<<"\nWell, let's see how's you doing!\n";

    if(affection>0){
        std::cout<<"jake love you, no homo! ofc\n";

    }else if(affection==0){
        std::cout<<"jake is neither like nor hate you!\n";

    }else if(affection<0){
        std::cout<<"jake is fucking hate you, dumbass!\n";

    }

}




