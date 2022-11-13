/*
Clonar HD | SSD | Pendriver no linux
Criado por Erasmo Cardodo
*/
#include <iostream>
#include <string.h>
#include <cstdlib>
//variaveis universais
std::string hdant , hdnova;

//funçoes
void menu(){

    std::cout<<"                        --------------------------------------------------\n";
    std::cout<<"                        |       Clonar HD|SSD|Partição   no LINUX        |\n";
    std::cout<<"                        --------------------------------------------------\n";
}

// litagem de unidades na maquina
void listar(){
    std::cout << "              Listar HDS           "<<std::endl;
    system("lsblk" );
}
// organiza unidade a ser clonada
void organ(){
    std::cout << " Coloque a letra da hd origem !!"<<std::endl;
    std::cin >> hdant;
    std::cout << " Coloque a letra da hd de destino !!"<<std::endl;
    std::cin >> hdnova;
}
// executa comando dd para clonar
void clonar(){
//   adaptação para system aceitar string em vez de char no system
    std::string teste = "sudo dd if=/dev/" +hdant+ " of=/dev/"+hdnova+ " bs=64K conv=noerror,sync";
    std::cout<< teste;
    std::system(teste.c_str());

}

// Verificação visual se esta tudo correto antes de clonar
void confir(){
    int confirma;
    std::cout <<"HD origem  : "<<hdant<<std::endl;
    std::cout <<"HD destino : "<<hdnova<<std::endl;
    std::cout <<"sudo dd if=/dev/"<<hdant<<" of=/dev/"<<hdnova<<" bs=64K conv=noerror,sync"<<std::endl;
    std::cout <<"Confirma ?  1 para sim !!! "<<std::endl;
    std::cin >>confirma;

    if (confirma == 1){
            system("clear");
            clonar();

    }else{
        system("clear");
        system("./hd");
        };

}


int main(){
    menu();
    listar();
    organ();
    confir();

    return 0;

}
