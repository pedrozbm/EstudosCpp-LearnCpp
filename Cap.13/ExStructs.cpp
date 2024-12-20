#include <iostream>

struct Publicidade{

    int anuncios_assistidos;
    float porcentagem_cliques;
    double ganho_medio_por_anuncio; 
};

void printPublicidade(Publicidade &site){
    std::cout << "Anuncios assistidos: " << site.anuncios_assistidos << '\n';
    std::cout << "Porcentagem de usuarios que clicou no anunco: " << site.porcentagem_cliques << '\n';
    std::cout << "Ganhos medios por anuncio: " << site.ganho_medio_por_anuncio << '\n';
    
    std::cout << "Ganho diario: " << ((site.ganho_medio_por_anuncio * site.anuncios_assistidos) * site.porcentagem_cliques)/100;
}

int main(){
    Publicidade site{15, 85.4, 2.64};
    printPublicidade(site);

}
