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

         //Constructor de Movimiento
        String(String&& other) noexcept{

            //Robamos los datos
            size = other.size;
            Data = other.Data;
            
            //Los datos del anterior objeto fueron eliminados
            other.size = 0;
            other.Data = nullptr;

            std::cout<<"Moved!"<<std::endl;
        }

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

        //Constructor para lvalues
        Entity(const String &name):m_name(name){
        }

        //Nuevo constructor para rvalues
        Entity(String &&name):m_name((String&&)name){
        }

        void PrintName(){
            m_name.Print();
        }
};

int main(){
    
    
    Entity entity("Hola");
    entity.PrintName();
    
    

    return 0;
}
