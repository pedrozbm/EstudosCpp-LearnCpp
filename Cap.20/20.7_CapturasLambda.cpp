//Uma boa explicação de uso 
// https://pt.stackoverflow.com/questions/270895/fun%C3%A7%C3%B5es-lambda-em-c-quando-utilizar-e-quais-as-vantagens

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

int main()
{
  std::array<std::string, 4> arr{ "apple", "banana", "walnut", "lemon" };

  std::cout << "search for: ";

  std::string search{};
  std::cin >> search;

// Lambdas podem acessar somente objetos constexpr e var globais e locais estaticos
  // clausula de captura @search                    vvvvvv
  auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string str) {
    return str.find(search) != std::string::npos;
  }) };
  // Quando uma lambda é executada, a lambda obtem sua propria variavel clonada
  // chamada search

  if (found == arr.end())
  {
    std::cout << "Not found\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}