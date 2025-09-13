#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct stGameInfo {
    
    int rounds = 0;
    int playerwin =0 ; 
    int computerwin = 0;
    int draw = 0;        
};
enum enchoice { rock = 1 , paper=2 , scissors = 3 
} ;

enchoice Choice( int num ){    
    switch ((enchoice) num){
        
        case enchoice :: rock :
               return enchoice :: rock;
               
       case  enchoice :: paper:
              return enchoice :: paper ;
              
       case enchoice ::  scissors :
              return enchoice :: scissors ;        
    }    
}

string ImprovePlayerChoice ( short choice ){
    choice = (enchoice ) choice ;
    if (choice == enchoice :: rock)
        return "rock";
    else if (choice == enchoice :: paper)
        return "paper";
     else 
         return "scissors";             
}

int randint (int from , int to ){
    
    return rand ()%( to - from +1)+from ;        
}

string computerchoice (string cards[]){
        
    return cards[randint(0,2)];
}

short ReadCard (){
    
    int card =0;
    cout <<"\n__________ player choice __________"<< endl << endl ;
    
    do {
        cout <<" enter a choice \n 1.rock \n paper \n 3.scissors (1-3):";
        cin >> card ;            
    }while (card <1 || card >3);
    
    cout <<"___________________________________\n" ;
    return card ;
}

string WhoWin (stGameInfo &GameInfo ,string playerchoice, string compchoice ){
   
    if (playerchoice== compchoice ){
        return "No Winner";
    }
    else {
                    
                if (playerchoice == "rock" && compchoice == "paper" ){
                    GameInfo.computerwin++;
                    return "Computer";
                }
                         
                else if (playerchoice == "paper" &&compchoice == " scissors" ){
                    GameInfo.computerwin++;
                    return "Computer";                    
                }                        
                else if (playerchoice== "scissors"&&compchoice == "rock"){
                    GameInfo.computerwin++;
                    return "Computer";      
                }                   
   }   
   GameInfo.playerwin++;
   return "Player";         
}

short ReadRounds (stGameInfo& GameInfo ,string msg){
    do {
        cout << msg ;
        cin >> GameInfo.rounds;
    }while (GameInfo.rounds <1);
    
    return GameInfo.rounds; 
    
}



void PrintRoundInfo (stGameInfo& GameInfo ,short counter , short playerchoice , string compchoice ){
    
    cout <<"\n__________ ROUND [ "<< counter <<" ] __________\n";
    
    cout <<"\n player choice : "<< ImprovePlayerChoice (playerchoice);
    cout <<"\n computer choice: "<< compchoice <<endl;
    cout <<"\n round winner: [ "<< WhoWin(GameInfo , ImprovePlayerChoice (playerchoice), compchoice) <<" ]\n"; 
    
}


void StarRound (stGameInfo& GameInfo ){
    string cards[3] = {"rock", "paper","scissors"};
    
    ReadRounds( GameInfo," how many rounds you are want to play? : ");
    short playercard =0;
    string compchoice ;
    short counter = 1;
    while (counter <GameInfo.rounds+1){
         
       playercard = ReadCard(); 
       compchoice =computerchoice(cards);
     
      PrintRoundInfo(GameInfo , counter, playercard, compchoice);
                         
        counter++;
    }
    counter= 1;
}

string FinallWinner (stGameInfo& GameInfo){
    
  
    if (GameInfo.playerwin > GameInfo.computerwin)
        return "Player";
   else if ( GameInfo.playerwin < GameInfo.computerwin)
       return "Computer";
   else  if (GameInfo.playerwin == GameInfo.computerwin)
       return "No Winner";
    else return "No Winner";
}

void PrintResult(stGameInfo& GameInfo ){
    cout <<"\n_____________________________________\n";
    cout <<"             GAME OVER                 ";
    cout <<" \n_____________________________________\n";
    cout <<" \n__________ GAME RESULT __________\n";
    
    
    cout <<" Game rounds : "<<GameInfo.rounds <<endl;
    cout <<" player win time : "<<GameInfo.playerwin << endl;
    cout << " computer win time : "<< GameInfo.computerwin << endl ;
    cout <<" Draw time : "<< GameInfo.draw<<endl;
    cout <<" Finall Winner : "<< FinallWinner (GameInfo) << endl;
     
}

void cleardata (stGameInfo & GameInfo){
    
    GameInfo.rounds = 0 ;
    GameInfo.playerwin = 0 ;
    GameInfo.computerwin = 0 ;
    GameInfo.draw = 0 ;
}

void StartGame(){
           
    stGameInfo GameInfo ;
    short moregame = 0 ;
    do {
        cleardata(GameInfo);
        system("clear");       
        StarRound(GameInfo);
        PrintResult(GameInfo);
        
        cout <<" you want to play new round? (0/1): ";
        cin >>moregame ;
    }while (moregame > 0);
           
}
int main(){
    
    srand((unsigned)time(NULL));
        
    StartGame();
    return 0; 
}
