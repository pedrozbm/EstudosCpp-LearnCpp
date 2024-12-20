#include <iostream>

// write your add function template here
template <typename T>
T soma(T x, T y){
return x + y ; 
}

int main()
{
	std::cout << soma(2, 4)<< '\n';
	std::cout << soma(1.2, 3.4) << '\n';	
	int aux{0};
	for (int i = 0; i < 5; i++)
	{	
		std::cout << aux << "\n";
		aux += 5;
	}
	
	return 0;
}