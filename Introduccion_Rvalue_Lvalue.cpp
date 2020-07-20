#include<iostream>

//Esta funcion puede recibir valores lvalue y rvalue
void PrintValue(int x){
    std::cout<<x<<std::endl;
}

//Esta funcion retorna un rvalue
int GetValue(){
    return 10;
}

int main(){
	
    //lvalue     rvalue
    int x    =      7     ;
    // Decir 7=x sería incorrecto, porque un rvalue es un valor temporal
    
    //lvalue      lvalue
    int y    =      x;
    //Un lvalue puede guardar el valor de otro lvalue

    //lvalue       rvalue
    int z    =      x+y;
    //x+y es un rvalue, puesto que esta suma es un valor temporal

    //lvalue       rvalue
    int a    =     GetValue();
    //La función es un rvalue, retorna un valor temporal

    PrintValue(5);    //Le estamos pasando un rvalue como parámetro a esta función
    PrintValue(a);    //Le estamos pasando un lvalue como parámetro a esta función
    
    return 0;
}
