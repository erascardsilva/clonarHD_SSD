/*
Clonar HD | SSD | Pendriver no linux
Criado por Erasmo Cardoso
*/
#include <iostream>
#include <string.h>
#include <cstdlib>
//variaveis universais
std::string hdant , hdnova, veloc;
int opcao, confirma;

//funçoes
void menu(){

    std::cout<<"                    --------------------------------------------------\n";
    std::cout<<"                    |       Clonar HD|SSD|Partição   no LINUX        |\n";
    std::cout<<"                    --------------------------------------------------\n";
}

// litagem de unidades na maquina
void listar(){
    std::cout<<"----------------                                ---------------------"<<std::endl;
    std::cout << "                          Listar Unidades                          "<<std::endl;
    system("lsblk");
    std::cout<<"-----------                                             -------------"<<std::endl;

}
// organiza unidade a ser clonada
void organ(){
    std::cout << " Coloque a letra da hd origem !!"<<std::endl;
    std::cin >> hdant;
    std::cout << " Coloque a letra da hd de destino !!"<<std::endl;
    std::cin >> hdnova;
    do{
    std::cout << "--------------------- Velocidade ------------- "<<std::endl;
    std::cout << "| 1) PENDRIVER                                |"<<std::endl;
    std::cout << "| 2) HD                                       |"<<std::endl;
    std::cout << "| 3) SSD                                      |"<<std::endl;
    std::cout << "-----------------------------------------------"<<std::endl;
    std::cin >> opcao;

        switch (opcao){
            case 1 :
                veloc = "10M";
                break;
            case 2 :
                veloc = "500M";
                break;
            case 3 :
                veloc = "1G";
                break;
            default :
                system("clear");
                std::cout << "      -----------Opção Invalida-------------    "<<std::endl;
                std::cout << "      -----------Tente novamente------------    "<<std::endl;
        }
    }while (opcao <1 || opcao > 3);
}
    // executa comando dd para clonar
void clonar(){
//   adaptação para system aceitar string em vez de char no system
    std::string clon = "sudo dd if=/dev/" +hdant+ " of=/dev/"+hdnova+ " bs="+veloc+" conv=noerror status=progress";
    std::cout<< clon;
    std::system(clon.c_str());
    std::cout<<"\n";
    std::cout<<"    ------------    FIM!!!    ------------------      ";
}

// Verificação visual se esta tudo correto antes de clonar
void confir(){

    std::cout <<"HD origem  : "<<hdant<<std::endl;
    std::cout <<"HD destino : "<<hdnova<<std::endl;
    std::cout <<"sudo dd if=/dev/"<<hdant<<" of=/dev/"<<hdnova<<"  bs="<<veloc<<" conv=notrunc, noerro "<<std::endl;
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


// funções
int main(){
    menu();
    listar();
    organ();
    confir();

    return 0;

}
