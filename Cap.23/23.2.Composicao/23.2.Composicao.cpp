/*
Em c++ classes e structs podem ter membros de diferentes tipos
podemos chamar então as classes e structs de tipos compostos

A composição é util pois permite criar tipos complexos a partir de 
pequenas partes mais simples e fáceis de gerenciar

Para ser composição:

-> A parte(membro) faz parte do objeto(classe)
-> A parte(membro) só pode pertencer a um objeto(classe) por vez
-> A existencia da parte(membro) é gernciada pelo objeto(classe)
-> A parte(membro) não tem conhecimento da existência do objeto(classe)

As relações de composição são parte-todo, um bom exemplo é um coração de uma pessoa.

O coração é parte do corpo de uma pessoa, A parte em uma composição só pode pertencer
a um objeto por vez. Um coração não pode pertencer a duas pessoas ao mesmo tempo.
Numa relação de composição, o objeto é responsável pela existência das partes. 
Isso significa que a parte é criada quando o obj é criado e destruida
quando o obj é destruido. Por isso a composição as vezes é chamada de relação de morte

Por fim, a parte não tem consciencia do todo, o coração funciona em perfeita
inconsciencia de que faz parte de uma estrutura maior. Isso é chamada
de relação unidirecional.

Observe a onipresente classe Fraction:
*/
class Fraction{
    private:
        int m_denominator;
        int m_numerator;

        public:
        Fraction(int numerator= 0, int denominator= 1): m_numerator{numerator}, m_denominator{denominator}{

        }
};

/*
Denominator e numerator fazem parte de Fraction, eles não podem pertencer a mais de uma fração
simultaneamente.

Variantes:

-> Uma composição pode adiar a criação de algumas partes até que elas sejam necessárias.
Por exemplo uma classe de strinh pode não criar um array dinâmico de caracteres até que 
o usuario atribua a string alguns dados para armazenar.
-> Uma composição pode usar parte do que foi fornecida como entrada, em vez de criar a parte por 
si mesma. 
-> Uma composição pode delegar a destruição de suas partes a algum outro objeto( Por exemplo
a rotina de coleta de lixo)

Vantagens dessa separação:

-> Cada classe indivodual pode ser mantida simples e direta, focada em uma unica tarefa
-> Cada classe é autocontida, portanto pode ser reutilizavel. Poderiamos usar 
point2D em diversas aplicações distintas.
-> A classe externa pode delegar a maior parte do trabalo pesado aos membros, concentrando-se, em 
vez disso na coordenação do fluxo de dados entre eles. Isso ajuda a reduzir a complexidade geral da 
classe externa, pois ela pode delegar tarefas ao seus membros, que já sabem como realizar-las.

Uma boa prática é que cada classe deve ser construida para realizar uma única tarefa. Essa tarefa
deve ser o armazenamento e a manipulação de algum tipo de dado(por exemplo, Point2D, td::string) OU a
coordenação de seus membros (por exemplo, Creature). Idealmente, não ambas.

*/