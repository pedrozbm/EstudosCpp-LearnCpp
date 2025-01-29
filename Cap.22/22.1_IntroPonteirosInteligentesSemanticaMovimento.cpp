#include <iostream>
#include <memory>
// Considere uma função na qual usamos alocação dinamica


void someFunction(){
    *Resource ptr = new Resource();

    delete ptr;
}

int main(){

}