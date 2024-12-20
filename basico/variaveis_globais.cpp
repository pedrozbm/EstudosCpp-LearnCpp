#include <iostream>
int value {5};

main(){
using std::cout;
int value {7};
++value;
--(::value);

cout << "abacate" ; 
std::cout << "Local " << value <<'\n';
std::cout<< "Global " << ::value<<'\n';

return 0;
}
