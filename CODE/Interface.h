#ifndef INTERFACE_H
#define INTERFACE_H
#include "Game.h"
#include <stdio.h>
#include <random>
#include <string>

int selectDifficulty(){
  cout << "-*-*-*-*-*-*-* Por favor selecciona una diificultad -*-*-*-*-*-*-"<<endl;
  cout << endl;
  cout << "¬ Presiona '1' para el modo 🃢Facil🃢 (3-5 words)" <<endl;
  cout << "¬ Presiona '2' para el modo 🃤Intermedio🃤 (6-8 words)" <<endl;
  cout << "¬ Presiona '3' para el modo 🃥Dificil🃥 (9-11 words)" <<endl;
  cout << "¬ Presiona '4' para 🃵GodMode🃵 (12+ words)" <<endl;
  cout << "¬ Presiona cualquier otro caracter para salir"<<endl;
  cout << endl;
  
  string x;
  cin >> x;

  if(x == "1"){
    cout<< "*___SE JUGARA EN MODO FACIL___*"<<endl;
    return stoi(x);
  }
    
  else if(x == "2"){
    cout<< "**__SE JUGARA EN MODO INTERMEDIO__**"<<endl;
    return stoi(x);
  }

  else if(x == "3"){
    cout<< "***_SE JUGARA EN MODO DIFICIL_***"<<endl;
    return stoi(x);
  }

  else if(x == "4"){
    cout<< "****SE JUGARA EN GODMODE... buena suerte****"<<endl;
    return stoi(x);
  }
  
  else{
    return 0;
  }

  
    

}

int random(int low, int high)
{
  random_device rd;
  mt19937 gen(rd());
	uniform_int_distribution<> dist(low, high);
	return dist(gen);
}
void quit(){
  cout << "-*-*-*-*-*-*El programa ha finalizado... vuelva pronto*-*-*-*-*-*-"<<endl;
}


string generateWord(int a){
  int b = random(1,29);
  switch(a){
    case 1:
      return easyWords[b];
      break;
    case 2:
      return mediumWords[b];
      break;
    case 3:
      return hardWords[b];
      break;
    case 4: 
      return godWords[b];
      break;
    case 0:
      return "";
      quit();
      break;
      
  }
}












#endif     