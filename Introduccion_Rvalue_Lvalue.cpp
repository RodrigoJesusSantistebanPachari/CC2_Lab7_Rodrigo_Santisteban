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
    // Decir 7=x ser�a incorrecto, porque un rvalue es un valor temporal
    
    //lvalue      lvalue
    int y    =      x;
    //Un lvalue puede guardar el valor de otro lvalue

    //lvalue       rvalue
    int z    =      x+y;
    //x+y es un rvalue, puesto que esta suma es un valor temporal

    //lvalue       rvalue
    int a    =     GetValue();
    //La funci�n es un rvalue, retorna un valor temporal

    PrintValue(5);    //Le estamos pasando un rvalue como par�metro a esta funci�n
    PrintValue(a);    //Le estamos pasando un lvalue como par�metro a esta funci�n
    
    return 0;
}
