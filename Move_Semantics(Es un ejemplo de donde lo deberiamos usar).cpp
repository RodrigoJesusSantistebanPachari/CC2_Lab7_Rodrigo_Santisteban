#include<iostream>
#include<string.h>

//Creamos una clase String
class String{
    private:
        int size;
        char *Data;
    public:
        String() = default;
        String(const char *string){
            size = strlen(string);
            Data = new char[size];
            memcpy(Data, string, size);
            std::cout<<"Created!"<<std::endl;
        }

        //Constructor Copia
        String(const String& other){
            size = other.size;
            Data = new char[size];
            memcpy(Data, other.Data, size);
            std::cout<<"Copied!"<<std::endl;
        }
		
		//Deberiamos implementar un Constructor de Movimiento

        ~String(){
            delete Data;
            std::cout<<"Deleted!"<<std::endl;
        }

        void Print(){
            for(int i=0; i<size; i++){
                std::cout<<Data[i];
            }
            std::cout<<std::endl;
        }
};

//Creamos una clase Entity
class Entity{
    private:
        String m_name;
    public:
        Entity(const String &name):m_name(name){
        }

        void PrintName(){
            m_name.Print();
        }
};

int main(){
    
    //Al crear un Entity, estamos usando el constructor copia, este nos genera 2 String innecesarias que estarán alojadas en el Heap
    Entity entity(String(("Hola")));

    //En vez de usar un Constructor Copia, deberíamos usar un Constructor de Movimiento(En el siguiente archivo he implementado el constructor de movimeinto)
    return 0;
}
