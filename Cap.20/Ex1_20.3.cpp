#include <iostream>
#include <vector>
int fatorial(int n){
    if(n<=0)
      return 1;
    
    return fatorial(n - 1) *n;    
}
int main(){
    for(int i=0; i<=7; ++i)
       std::cout << fatorial(i) <<'\n';
}