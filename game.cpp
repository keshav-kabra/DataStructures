#include<iostream>
#include<cstring>
// #include<stdlib.h>
// #include<math.h>
// #include<string.h>
using namespace std;
int money = 100;
int play(int bet );
int singleplayer(int bet);
int multiplayer();


int multiplayer()
{
    int no_of_players, m_bid , i, total_amount =0, count =0;
    //1 .deccide number of player to play
    cout<<"\nenter the number of players";
    cin>>no_of_players;
    string* players = new string[no_of_players];
    int* choices = new int[no_of_players];
    //2 collect money from ecah player
    cout<<"\nenter the names";
    for(i=0;i<no_of_players;i++)
    {
        cout<<"\nplayer "<<i+1;
        cin>>players[i];
    }
    cout<<"enter the comman bid";    
    cin>>m_bid;
    total_amount = m_bid * no_of_players;
    cout<<"shuffling cards !!!..\nenter the position of ace card\n";
    for(i=0;i<no_of_players;i++)
    {
        cout<<"\n"<<players[i];
        cin>>choices[i];
    }
    //3 each player select select position 
    //4 print correct position
    
    
    int random_value =  rand()%(3);
    cout<<"correct position is "<<random_value<<"\n";
    for(i=0;i<no_of_players;i++)
    {
        if(choices[i] == random_value +1)
        {
            cout<<players[i]<<"\t";
            count++;
        }
    }
    //5 total money is divided in player who choose correct
    
    cout<<"WON!!\n get "<<total_amount/count<<"\n";
    return 0;

}
int singleplayer(int bet)
{
    cout<<"\nenter the money to bet";
    cin>>bet;
    if(bet<=money) play(bet);
    else cout<<"you only have "<<money<<" bucks!!";
    return 0;
}

int play(int bet)
{
    int selection=0;
    //you need to find position of ace card
    // string cards[] = {"ace","king","queen"};
       cout<<"\nshuffling cards....";
    cout<<"\nselect the  position of ace card in deck of three";
    cin>>selection;
    int random_new = rand();
    int random_value =  rand()%(3);
    cout<<"value of new random function is"<<random_new;
    cout<<"random value is "<<random_value;
    cout<<"\nposition of ace card "<<random_value+1;
    if(random_value+1 == selection) 
    {
         money= money +(3*bet) ;
        cout<<"\nYOU WIN \t BALANCE = "<<money<<"\n";
    }
    else
    {
        money=money-  bet;
        cout<<"\n OOP'S YOU LOOSE \t BALANCE = "<<money<<"\n";
        
      
    }
    return 0;   
}

int main()
{
    cout<<"****** welcome to BETTING WORLD ****\n\n\n";
    int bet, choice;
    while(true)
    {
        if(money == 0)
        {
            cout<<"\nTHANK YOU FOR PLAYING WITH US !!"  ;
            break;
        }
        cout<<"n press 1 to play with CPU\n2 to play with multiplayer\n3 to exit game";
        cin>>choice;
        switch(choice)
        {
            case 1 :
                    singleplayer(bet); 
                    break;
            case 2: multiplayer(); 
                    break;
            case 3:  money =0;
                   
        }
          
            
    }
    return 0;
}