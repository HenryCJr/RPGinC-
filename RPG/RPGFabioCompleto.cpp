#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

typedef struct{
        
        string name;
        string type;
        int life, lifeMax;
        int dmg;
        string skill;
        int skillTime;
        int skillDmg;
        int level;
                             
        }PClasse;
        






int main(int argc, char *argv[]){
    
    PClasse player;
    player.level = 1;
    int play;
    unsigned seed = time(0);
    
    //-------------------------------------------------------------------------------------------------------
    
    string enemie[4] = { "Piratas Fantasmas", "Goblins", "Esqueletos", "Lobos"};
    string camp[4] = { "Praia", "Caverna", "Calabouço", "Floresta"};
    int copas = 0, espadas = 0, paus = 0, ouro = 0;
    
    //-------------------------------------------------------------------------------------------------------
    
    
    cout << "Digite a classe do seu personagem: \n 1 -- Elemental \n 2 -- Paladino \n 3 -- Curador \n 4 -- Berseker \n\n";
    cin>> play;
    
    switch(play){
                 case 1:
                      player.type = "Elemental";
                      player.life = 10;
                      player.lifeMax = 10;
                      player.dmg = 1;
                      player.skill = "Fire Storm";
                      player.skillDmg = 2;
                      break;
                 case 2:
                      player.type = "Paladino";
                      player.life = 12;
                      player.lifeMax = 12;
                      player.dmg = 1;
                      player.skill = "Força Bruta";
                      player.skillDmg = 1;
                      break;
                 case 3:
                      player.type = "Curador";
                      player.life = 10;
                      player.lifeMax = 10;
                      player.dmg = 1;
                      player.skill = "Sopro da vida";
                      player.skillDmg = 2;
                      break;
                 case 4:
                      player.type = "Berseker";
                      player.life = 10;
                      player.lifeMax = 10;
                      player.dmg = 1;
                      player.skill = "Fúria";
                      player.skillDmg = 1;
                      break;
                 
                 }
    cout << "Digite o nome do seu personagem: \n\n";
    cin >> player.name;
    
    cout << "--------------------------------------------------------------------------------";
    
    do{
         int r = rand()%4;
         int q = rand()%4;
         int e = 1+rand()%10;
         int eM = e;
         int eD = 1;
         
         
         
         cout<< " ";
         cout<< player.name;
         cout<< " se encontra em uma ";
         cout<< camp[r];
         cout<< ".\n Quando menos esperava, um grupo de ";
         cout<< e;
         cout << " ";
         cout<< enemie[q];
         cout<< " lhe avista e parte para o ataque.\n Prepare-se: \n\n";
         
         do{
                int d;
                
                cout<<player.name;
                cout<<" ---------- ";
                cout<< enemie[q];
                cout<< "\n";
                
                cout<<player.life;
                cout<< " / ";
                cout<<player.lifeMax;
                cout<< " ---------- ";
                cout<<e;
                cout<< " / ";
                cout<< eM;
                cout<< "\n\n";
                
               // system("PAUSE");
               
               cout<<"1 -- Attack \n2 -- ";
               cout<< player.skill;
               cout<< "\n\n";
               
               cin>>d;
               
               switch(d){
                         
                         case 1:
                              {
                              int cardP = 1+rand()%10;
                              int cardE = 1+rand()%10;
                              
                              if(cardP > cardE){
                                        e -= player.dmg;
                                         player.dmg = 1;
                                         eD = 1;
                                         } else if(cardP < cardE){
                                                player.life -= eD;
                                                player.dmg = 1;
                                                eD = 1;
                                                } else {
                                                       player.dmg++;
                                                       eD++;
                                                       }
                                             
                              cout<<"\n\n";                         
                              cout<< cardP;
                              cout<< " -x- ";
                              cout<< cardE;
                              cout<<"\n\n";
                              player.skillTime--;
                              system("PAUSE");
                              }
                              
                               break;                               
                         case 2:
                              
                              if(player.skillTime <= 0){
                                             
                                             if(player.skill == "Fire Storm"){ e -= player.skillDmg; }
                                             if(player.skill == "Força Bruta"){e-= player.skillDmg; player.life+= player.skillDmg;}
                                             if(player.skill == "Sopro da vida"){player.life += player.skillDmg;}
                                             if(player.skill == "Fúria"){player.life--; player.dmg+= player.skillDmg;}   
                                                  
                              
                              player.skillTime = 3;
                              
                              
                              
                              } else { cout<< "\n\n Skill Ainda está Carregando\n\n";}
                              
                              cout<< "\n\n";
                              
                              break;
                        
                         
                         }
                
                
                if(player.life <= 0){
                               
                               cout<< "\n\nSe Fodeu\n\n";
                               system("PAUSE");
                               return EXIT_SUCCESS;
                               }
                
                
                }while(e > 0);
         
         int n = rand()%4;
         
         switch(n){
                   case 0:
                        copas += eM;
                        
                        break;
                   case 1:
                        espadas += eM;
                        
                        break;
                   case 2:
                        paus += eM;
                        
                        break;
                   case 3:
                        ouro += eM;
                        
                        break;
                   
                   
                   
                   }
         
         
         cout<<"\n ";
         cout<< player.name;
         cout<< " venceu esta rodada e obteve: ";
         cout<< copas;
         cout<< " de vida; ";
         cout<< espadas;
         cout<< " de experiência; ";
         cout<< paus;
         cout<< " de fraqueza; e ";
         cout<< ouro;
         cout<< " de ouro;\n\n";
         
         player.life+=copas;
         copas = 0;
         
         cout << "Deseja acessar a loja? \n 1 -- Sim \n 2 -- Nao\n\n";
         int f;
         int g;
         bool loja = true;
         cin>>f;
         
         switch(f){
                   case 1:
                        for(; loja == true;){
                        cout<<" --------------------------------------------- \n\n";
                        cout<<"O que deseja comprar? \n 1 -- 1 Vida.....1 Ouro \n 2 -- Mais Dano de Skill.....3 Ouro\n\n";
                        cin>> g;
                        if(g == 1){
                             cout<<"Quantas deseja comprar?\n";
                              cin >> g;
                              if(ouro>=g){player.life+=g; ouro-= g;cout<<"\nCompra Efetuada\n\n";}else{cout<<"\n\nNao ha ouro o bastante\n\n";}
                              }else if(g == 2){
                                    if(ouro>=3){player.skillDmg++; ouro-=3; cout<<"\nCompra Efetuada\n\n";}else{cout<<"\n\nNao ha ouro o bastante\n\n";}
                                    
                                    }
                                    cout<<"Deseja comprar outra coisa?\n\n 1 -- Sim \n 2 -- Nao\n\n";
                                    cin>>g;
                                    if(g==1){loja = true;}else{loja = false;}
                                    
                                    
                        }
                        break;
                        default:
                                break;
                   
                   
                   } 
              
         
         system("PAUSE");
         
         
         cout<<"\n\n";
         player.level++;
         
         
         }while(player.level <= 5);
         
         cout << "-------------------------------------Boss---------------------------------------";
    
    do{
        
         int q = rand()%4;
         int e = player.level + 6;
         int eM = e;
         int eD = 1;
         
         
         
         cout<< " ";
         cout<< player.name;
         cout<< " se encontra na Torre dos Vigias";
         //cout<< camp[r];
         cout<< ".\n Quando menos esperava, os Grandes ";
        // cout<< e;
         cout << " ";
         cout<< enemie[q];
         cout<< " lhe avistaram e partiram para o ataque.\n Prepare-se: \n\n";
         
         do{
                int d;
                
                cout<<player.name;
                cout<<" ---------- ";
                cout<< enemie[q];
                cout<< "\n";
                
                cout<<player.life;
                cout<< " / ";
                cout<<player.lifeMax;
                cout<< " ---------- ";
                cout<<e;
                cout<< " / ";
                cout<< eM;
                cout<< "\n\n";
                
               // system("PAUSE");
               
               cout<<"1 -- Attack \n2 -- ";
               cout<< player.skill;
               cout<< "\n\n";
               
               cin>>d;
               
               switch(d){
                         
                         case 1:
                              {
                              int cardP = 1+rand()%10;
                              int cardE = 1+rand()%10;
                              
                              if(cardP > cardE){
                                        e -= player.dmg;
                                         player.dmg = 1;
                                         eD = 1;
                                         } else if(cardP < cardE){
                                                player.life -= eD;
                                                player.dmg = 1;
                                                eD = 1;
                                                } else {
                                                       player.dmg++;
                                                       eD++;
                                                       }
                                             
                              cout<<"\n\n";                         
                              cout<< cardP;
                              cout<< " -x- ";
                              cout<< cardE;
                              cout<<"\n\n";
                              player.skillTime--;
                              system("PAUSE");
                              }
                              
                               break;                               
                         case 2:
                              
                              if(player.skillTime <= 0){
                                             
                                             if(player.skill == "Fire Storm"){ e -= player.skillDmg; }
                                             if(player.skill == "Força Bruta"){e-= player.skillDmg; player.life+= player.skillDmg;}
                                             if(player.skill == "Sopro da vida"){player.life += player.skillDmg;}
                                             if(player.skill == "Fúria"){player.life--; player.dmg+= player.skillDmg;}   
                                                  
                              
                              player.skillTime = 3;
                              } else { cout<< "\n\n Skill Ainda está Carregando\n\n";}
                              
                              cout<< "\n\n";
                              
                              break;
                        
                         
                         }
                
                
                if(player.life <= 0){
                               
                               cout<< "\n\nSe Fodeu\n\n";
                               system("PAUSE");
                               return EXIT_SUCCESS;
                               }
                
                
                }while(e > 0);
         
         int n = rand()%4;
         
         switch(n){
                   case 0:
                        copas += eM;
                        
                        break;
                   case 1:
                        espadas += eM;
                        
                        break;
                   case 2:
                        paus += eM;
                        
                        break;
                   case 3:
                        ouro += eM;
                        
                        break;
                   
                   
                   
                   }
         
         
         cout<<"\n ";
         cout<< player.name;
         cout<< " venceu esta rodada e obteve: ";
         cout<< copas;
         cout<< " de vida; ";
         cout<< espadas;
         cout<< " de experiência; ";
         cout<< paus;
         cout<< " de fraqueza; e ";
         cout<< ouro;
         cout<< " de ouro;\n\n";
         
         player.life+=copas;
         copas = 0;
         
         cout << "Deseja acessar a loja? \n 1 -- Sim \n 2 -- Nao\n\n";
         int f;
         int g;
         bool loja = true;
         cin>>f;
         
         switch(f){
                   case 1:
                        for(; loja == true;){
                        cout<<" --------------------------------------------- \n\n";
                        cout<<"O que deseja comprar? \n 1 -- 1 Vida.....1 Ouro \n 2 -- Mais Dano de Skill.....3 Ouro\n\n";
                        cin>> g;
                        if(g == 1){
                             cout<<"Quantas deseja comprar?\n";
                              cin >> g;
                              if(ouro>=g){player.life+=g; ouro-= g;cout<<"\nCompra Efetuada\n\n";}else{cout<<"\n\nNao ha ouro o bastante\n\n";}
                              }else if(g == 2){
                                    if(ouro>=3){player.skillDmg++; ouro-=3; cout<<"\nCompra Efetuada\n\n";}else{cout<<"\n\nNao ha ouro o bastante\n\n";}
                                    
                                    }
                                    cout<<"Deseja comprar outra coisa?\n\n 1 -- Sim \n 2 -- Nao\n\n";
                                    cin>>g;
                                    if(g==1){loja = true;}else{loja = false;}
                                    
                                    
                        }
                        break;
                        default:
                                break;
                   
                   
                   } 
              
         
         system("PAUSE");
         
         
         cout<<"\n\n";
         player.level++;
         
         
         }while(player.level <= 8);
    
    
    
    
    
    
   
    cout<<"\n\n *-*-*-*-*-*-*-VOCE VENCEU-*-*-*-*-*-*-*";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
