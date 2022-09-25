#include "Interface.h"


void changePage(){
  cout<<endl;
  cout<<endl;
  cout<<endl;
  cout << "********************************************************************"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<endl;
}
void start(){
  cout<< "-*-*-*-*-*-*-* Welcome to Aesthetic Worlde *-*-*-*-*-*-*-"<<endl;
  cout << endl;
  cout << "¬ Escribe cualquier caracter y luego presiona ENTER para comenzar" <<endl;
  string x;
  cin >> x;
  changePage();
  int mode = selectDifficulty();
  if(mode != 0){
    string wordToGuess = generateWord(mode);
    Game game = Game();
    game.playGame(wordToGuess);
    
  }
    
    
  else{
    quit();
  }
  
  
  
  
}