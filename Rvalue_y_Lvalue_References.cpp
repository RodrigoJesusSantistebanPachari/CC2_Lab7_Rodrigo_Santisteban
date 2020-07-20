#include<iostream>

//Usamos rvalue reference
void PrintValue(int &&value){
    std::cout<<"You are using an rvalue reference: "<<std::endl;
    std::cout<<value<<std::endl;
}

//Usamos lvalue reference
void PrintValue(const int &value){
    std::cout<<"You are using an lvalue reference: "<<std::endl;
    std::cout<<value<<std::endl;
}

int main(){
    int a = 4;
    int b = 5;
    PrintValue(a);      //a es un lvalue
    PrintValue(a+b);    //a+b es un rvalue

    return 0;
}
