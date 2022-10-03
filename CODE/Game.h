#ifndef GAME_H
#define GAME_H
#include "LinkedList.h"

string easyWords[30] =   {"ALA","CAE","DON","FEA","EMU","HAY","LEE","MIO","ORO","UVA","ARES","ADAN","BAÑO","COCO","GATO","HUBO","IZAS","LIMA","IBAN","BOYA","HUYAN","ACUNA","ARCOS","AZOTE","BACAN","AYUDA","ARUÑO","BEBES","BORRE","BRUTA"};
    string mediumWords[30] = {"ACUÑA","ADOPTA","AFGANA","AFLOJO","BAMBUS","BALBOA","AÑEJOS","ATUNES","CAÑADA","CESTOS","DISECAR","DESPOJO","ENCARTA","ENIGMA","ESPINA","FLORIDA","FUSILES","GROSERA","HAYAMOS","HERMOSA","ABDUZCAN","ATASQUES","BARBADOS","BELGRADO","BELLACOS","CANONICA","CELEBRES","CIRCULOS","DEPORTES","DEMORGAN"};
    string hardWords[30] = {"ABERTURAS","ELECTRICA","EMBARAZARSE","FILIPINAS","FLAMANTES","GIJARROS","GUATEMALA","HABRIAMOS","HOMOLOGAS","IMAGINATE","ACADEMICAS","DECREPITAS","DESINTEGRE","FAMILIARES","FINALISTAS","GENTILICIAS","HERVIDEROS","IDOLATRICO","INEXORABLE","ACCIONISTAS","BIBLIOFILAS","CALCULABLES","CARTERISTAS","DEFRAUDADOR","DESBAUTIZAR","ELECTORALES","ENVENENADOR","FILOSOFADOR","FUTBOLISTAS","GRABARIAMOS"};
    string godWords[30] = {"ABSOLUTISTAS","AFLOJAMIENTOS","DAMNIFICADORA","AMETRALALDORES","CERTIFICADORES","ELECTROLIZADOR","CONFECCIONADORA","CHECOSLOVAQUIA","DESPPILFARRADORA","AUTOMARGINACION","DECODIFICADORES","INVESTIGACIONES","COSTARRIQUEÑISMOS","SEMITRANSPARENTES","VOLUNTARIOSAMENTE","ARISTOCRATICAMENTE","NACIONALSOCIALISTA","TRANSANTEPENULTIMOS","AEROTRANSPORTAREMOS","INTUTOCIONALIZARON","DESCAPITALIZANDOLAS","CONSTITUCIONALISTICAMENTE","OTORRINOLARINGOLOGO","ELECTROENCEFALOGRAFISTA","ESTERNOCLEIDOMASTOIDEO","ELECTROENCEFALOGRAMA","EXTRATERRITORIALIDAD","INTERDISCIPLINARIDAD","METALINGUISTICAMENTE","SEUDOHERMAFRODITISMO"};

class Game{
  protected:
    int attemps = 6;
    
  public:
    Game(){}
    LinkedList askWord(int a, string toGuess){
    cout << "Intentos disponibles: " << a << endl; 
    string w;
    cin >> w;
    while(w.length() != toGuess.length()){
      cout << "Por favor ingrese una palabra de " << toGuess.length() << " letras" << endl;
      cin >> w;
    } 
    for(int i = w.length()-1; i>=0; i--){
      if((w[i] >= 65)&&(w[i]<= 92)){
        continue;
      }
      else{
         w[i] = w[i]-32;
      }  
    }

    LinkedList list = LinkedList();
    list = list.createLinkedList(w, w.length());
    return list;
    
    
  }

  void changePage(){
  cout<<endl;
  cout<<endl;
  cout<<endl;
  cout << "********************************************************************"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<endl;
}
    
  void playGame(string w){
      bool check;
      LinkedList toGuess = LinkedList();
      toGuess = toGuess.createLinkedList(w, w.length());
      while (this->attemps != 0){
        
      changePage();
        cout<<"Longitud de la palabra: " << toGuess.getLength() << endl;
        LinkedList word = askWord(this->attemps,w);
        word = word.compareList(word, toGuess, word.getHead());
        if(this->attemps != 1){
        word = word.compareList2(word, toGuess, word.getHead());
          word.printLinkedList();
        }
        ;
        cout << endl;
        if (word.verifyLinkedList())
        {
          check = true;
          break;
        }
        else{
          if(this->attemps == 1){
            word = word.loseLinkedList(word.getHead());
            word.printLinkedList();
            cout << endl;
          }
          check=false;
          this->attemps=this->attemps - 1;
          }
      }
    if (check)
    {
      cout<<"-*-*-*-*-*-*FELICIDADES, HAS ADIVINADO LA PALABRA*-*-*-*-*-*-"<<endl;
    }
    else {
        cout << endl;
        cout << "-*-*-*-*-*-*INTENTOS FINALIZADOS, LA PALABRA ERA: " << w << "*-*-*-*-*-*-" << endl;
        cout << "GAME OVER" << endl;
    }
  }
};



#endif