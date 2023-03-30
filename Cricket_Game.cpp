#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<limits>
#include<vector>

using namespace std;

class Player
{  
    public : 
    string name;
    int id;
    int runs_scored;
    int balls_played;
    int balls_bowled;
    int runs_given;
    int wickets_taken; 
    Player();                      //default constructor
    
}; 
Player :: Player()
{
    runs_scored = 0;
    balls_bowled = 0;
    balls_played = 0;
    runs_given = 0;
    wickets_taken = 0;
} 
class Team
{  
    public : 
    string name;
    int total_runs_scored;
    int wickets_lost;
    int total_balls_balled;
    vector<Player> players;       //it also means that a Team class will contain some number of Players class which connects both the classes

   // this vector is type of players class which means it can store numbers of Player classs in just like an array
   Team();

    
};  
Team :: Team()
{
    total_runs_scored = 0;
    wickets_lost = 0;
    total_balls_balled = 0;
}
class Game
{  
    public :
    
    bool is_first_innings;     //either it will be true or false

    Team TeamA,TeamB;       //creation of object of class Team

    Team *batting_team,*bowling_team;          //creation of object pointer of class Team

    Player *batsman,*bowler;         //creation of object pointer of class Player 

    string players[11];
    int players_per_team;
    int max_balls;
    int total_players; 
    Game();
    void Welcome();
    void show_all_players();
    int taking_integer_input();
    void select_players();
    void select_players_display();
    bool validate_selected_player(int);
    void show_team_players();
    void toss();
    void Toss_choice(Team);
    void start_first_innings();
    void initialize_players();
    void play_innings();
    void bat();
    bool validate_innings_score();
    void show_game_scorecard();
    void start_second_innings();
    void comparision();
    void final_scorecard();

};  
Game :: Game()
{
    is_first_innings = false;
    TeamA.name = "Team-A";          
    TeamB.name = "Team-B";
    //as soon as game starts the team names will be assigned from above loc
    players_per_team = 4;
    max_balls = 6;
    total_players = 11;
    players[0] = "Rawte";
    players[1] = "Shukla";
    players[2] = "Patel";
    players[3] = "Puse";
    players[4] = "Jain";
    players[5] = "Dubey";
    players[6] = "Sharma";
    players[7] = "Mourya";
    players[8] = "Rathor";
    players[9] = "Bhadoriya";
    players[10] = "Barasker";
}
void Game :: Welcome()
{
    
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"---------------------------       ~ Developed by PRANSHU RAWTE      -----------------------------"<<endl<<endl;
    cout<<"==================================Welcome to Virtual Cricket Game ================================"<<endl<<endl;
    cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-Instructions=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"|   1. Create 2 teams (Team-A and Team-B with 4 players each) from a given pool of 11 players .   |"<<endl<<"|   2. Lead the toss and decide the choice of play.                                               |       "<<endl<<"|   3. Each Innings will be of 6 balls                                                            | "<<endl;
    cout<<"|                                                                                                 |"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
    cout<<"Press Enter to Continue"<<endl;

    cin.ignore();                           // stops the screen untill user presses ENTER   
    
    
}
void Game :: show_all_players()
{
cout<<"....................................    Pool of Players    ........................................"<<endl<<endl;
    for(int i =0 ; i<11 ; i++)
    {
    cout<<"                                       ["<<i<<"] "<<players[i]<<"                 "<<endl;  
    }
    cout<<"...................................................................................................."<<endl;

    cout<<"Press Enter to Continue"<<endl;
    cin.ignore();                     // stops the screen untill user presses ENTER
}
int Game :: taking_integer_input()
{
    int n;
    //if the user enters an non-inter value so the expression inside the condition statement becomes false , 
    //and then it becomes true by boolean NOT and the while loop gets executed
    while (!(cin>>n))      
    {
        cin.clear();         //if an error occurs when taking the input from cin,then an error flag is set and future attempts to get input will fail. That's why you need cin.clear() to get rid of the error flag;

    
        cin.ignore(numeric_limits<streamsize>::max(),'\n');             //Also, the input which failed will be sitting in some sort of buffer. When you try to get input again, it will read the same input in the buffer and it will fail again. That's why you need this loc .It takes out all characters from the buffer but stops if it encounters a newline (\n). 

        cout<<"Invalid Input ! Please try again with valid input : "<<endl;
    }
    return n;
    }

void Game :: select_players()
{
    select_players_display();
    for (int i = 0; i < players_per_team; i++)
    {
        //Creation of Team-A
        TeamASelection:
        cout<<"Select player "<<i+1<<" of Team-A - "<<endl;

        int Player_index_teamA = taking_integer_input();    

        //validation of correct index value given by the user 
        if(Player_index_teamA < 0 || Player_index_teamA >10 )  
        {
            cout<<"Please select from the given players "<<endl;
            goto TeamASelection;
        }
        else if(!(validate_selected_player(Player_index_teamA)))
        {
            cout<<"Player has already been selected. Please choose another player"<<endl;
            goto TeamASelection;
        }
        else
        {
        Player Team_A_Player ;          //object created of class Player 

        Team_A_Player.id = Player_index_teamA;          //unique id given to the attribute of the object 

        Team_A_Player.name = players[Player_index_teamA];         //players[] is a string array defined in class Game ,and the respective index value of players will be assigned to the 'name' attribute of the object of the Team class

        TeamA.players.push_back(Team_A_Player);                   //here we are pushing Team_A_Player which is an object of class Player into  'players' which is a vector attribute( which is of class Players type ) of object TeamA of class Team
        }
        
    }  

    for (int i = 0; i < players_per_team; i++)
    {
        //Creation of Team-B
        TeamBSelection:
        cout<<"Select player "<<i+1<<" of Team-B - "<<endl;

        int Player_index_teamB = taking_integer_input();      

        //validation of correct index value given by the user 
        if(Player_index_teamB < 0 || Player_index_teamB > 10)
        {
            cout<<"Please select from the given players"<<endl;
            goto TeamBSelection;
        }
        else if(!(validate_selected_player(Player_index_teamB)))
        {
            cout<<"Player has already been selected. Please choose another player"<<endl;
            goto TeamBSelection;
        }
        else
        {
        Player Team_B_Player ;          //object created of class Player 

        Team_B_Player.id = Player_index_teamB;          //unique id given to the attribute of the object 

        Team_B_Player.name = players[Player_index_teamB];         //players[] is a string array defined in class Game ,and the respective index value of players will be assigned to the 'name' attribute of the object of the Team class

        TeamB.players.push_back(Team_B_Player);                   //here we are pushing Team_B_Player which is an object of class Player into  'players' which is a vector attribute( which is of class Players type ) of object TeamB of class Team 
        }
    
    }
    
}
void Game :: select_players_display()
{
    cout<<"------------------------------------------------------"<<endl;
    cout<<"|===============Create Team-A and Team-B==============|"<<endl;
    cout<<"------------------------------------------------------"<<endl;

}
bool Game :: validate_selected_player(int index)
{
    /*this function tells wether the selected player is already in any team or not  , if the player is already in a team this function returns false and is the player is not in any team , then the function returns true  */

    int n;
    vector<Player> players;
    players = TeamA.players;        //assigning all players of TeamA into players as it is of Player type 
    n = players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].id == index)
        {
            return false;
        }
    }
    players = TeamB.players;        //assigning all players of TeamB into players as it is of Player type 
    n = players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].id == index)
        {
            return false;
        }
    }
    return true; 
}
void Game :: show_team_players()
{
    cout<<"===========Team-A==========         =============Team-B==========="<<endl;
    cout<<"|                         |         |                            |"<<endl;
    for(int i = 0; i<players_per_team;i++)
    {
    cout<<"|\t["<<i<<"] "<<TeamA.players[i].name<<"\t  |   \t    |    \t["<<i<<"] "<<TeamB.players[i].name<<"\t |"<<endl;
    }
    cout<<"---------------------------         ------------------------------"<<endl;
}
void Game :: toss()
{   
    cout<<endl<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"|============ Let's Toss ==============|"<<endl;
    cout<<"---------------------------------------"<<endl<<endl;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');        //to clear the buffer memory otherwise the screen won't hold and cin.ignore(); won't work
    cout<<"Press enter to toss the coin"<<endl;
    cin.ignore();
    cout<<"Tossing the coin....."<<endl<<endl;

    srand(time(NULL));
    int random_value = rand() %2;    //0 or 1 
    switch(random_value)
    {
        case 0:
        cout<<"Team-A won the toss"<<endl<<endl;
        Toss_choice(TeamA);
        break;

        case 1:
        cout<<"Team-B won the toss"<<endl<<endl;
        Toss_choice(TeamB);
        break;
    }
}
void Game ::Toss_choice(Team toss_winner_team)
{
    cout<<"Enter 1 to bat or 2 to ball first "<<endl
        <<"1. Bat"<<endl
        <<"2. Bowl"<<endl;

    int toss_input = taking_integer_input();

    switch (toss_input)
    {
    //BATTING CONDITION

    case 1:         
        cout<<toss_winner_team.name<<" won the toss and choose to bat"<<endl;

        if (toss_winner_team.name.compare("Team-A") == 0)    //if Team-A is the toss winner
        {
            batting_team = &TeamA;
            bowling_team = &TeamB;
        }
        else           //if Team-B is the toss winner
        {
            batting_team = &TeamB;
            bowling_team = &TeamA;
        }
        break;

    //BOWLING CONDITION    
    case 2:
        cout<<toss_winner_team.name<<" won the toss and choose to bowl"<<endl;

        if (toss_winner_team.name.compare("Team-A") == 0)    //if Team-A is the toss winner
        {
            bowling_team = &TeamA;
            batting_team = &TeamB;
        }
        else           //if Team-B is the toss winner
        {
            bowling_team = &TeamB;
            batting_team = &TeamA;
        }
        break;
    default:
        cout<<"Invalid Input. Please try agaian :"<<endl<<endl;
        Toss_choice(toss_winner_team);   //when there is a wrong input from the user i.e. other than 1 or 2 , we do recursion here and call this function again fort kaing the input again
        break;
    }
}
void Game :: start_first_innings()
{
    cout<<endl;
    cout<<"\t\t||| FIRST INNINGS STARTS |||"<<endl<<endl;
    is_first_innings = true;

    initialize_players();
}
void Game :: initialize_players()
{
    //Initializing the batsman and the bowler with the 0th index players of their respective teams
    batsman = &batting_team->players[0];
    bowler = &bowling_team->players[0];

    cout<<batting_team->name<<" - "<<batsman->name<<" is batting"<<endl;
    cout<<bowling_team->name<<" - "<<bowler->name<<" is bowling"<<endl<<endl;
}
void Game :: play_innings()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for (int i = 0; i < max_balls; i++)
    {
        cout<<"Press Enter to bowl"<<endl;
        getchar();
        cout<<"Bowling..."<<endl;
        bat();


        //this checks wether the innings is over or not which will be in two condition :-
        //1.when all players of the batting team are out 
        //2.when the bowling team has bowled all the balls
        if (!(validate_innings_score()))   
        {
            break;
        }
    }

}
void Game :: bat()
{
    srand(time(NULL));
    int runs_scored = rand() % 7;    //will give number from 0 to 6

    //Updating batting team and batsman score
    batsman->runs_scored = batsman->runs_scored + runs_scored;
    batting_team->total_runs_scored = batting_team->total_runs_scored + runs_scored;
    batsman->balls_played = batsman->balls_played + 1;

    //Updating bowling team and bowler
    bowler->balls_bowled = bowler->balls_bowled + 1;
    bowling_team->total_balls_balled = bowling_team->total_balls_balled + 1;
    bowler->runs_given = bowler->runs_given + runs_scored;

    if (runs_scored != 0)     //if run scored are 1,2,3,4,5 or 6
    {
        cout<<bowler->name<<" to "<<batsman->name<<" "<<runs_scored<<" runs !"<<endl<<endl;
        show_game_scorecard();
    }
    else             //else batsman scored run = 0 , then he is OUT
    {
        cout<<bowler->name<<" to "<<batsman->name<<" OUT!"<<endl<<endl;
        batting_team->wickets_lost = batting_team->wickets_lost + 1;
        bowler->wickets_taken = bowler->wickets_taken + 1;


        show_game_scorecard();

        int next_player_index = batting_team->wickets_lost;
        batsman = &batting_team->players[next_player_index];

        
    }
}
bool Game :: validate_innings_score()
{   //if this function returns false , means the validation fails , then the current innnings will end

    if(is_first_innings)         //when it is 1st innings
    {
        if (batting_team->wickets_lost == players_per_team || bowling_team->total_balls_balled == max_balls)
        {
            cout<<"\t\t||| FIRST INNING ENDS |||"<<endl<<endl;
            cout<<batting_team->name<<" "<<batting_team->total_runs_scored<<" - "<<batting_team->wickets_lost<<" ("<<bowling_team->total_balls_balled<<")"<<endl;

            cout<<bowling_team->name<<" needs "<<batting_team->total_runs_scored+1<<" runs to win the match"<<endl;

            return false;
        }
    }
    else                 //when it is 2nd innings
    {
        if ((batting_team->wickets_lost == players_per_team || bowling_team->total_balls_balled == max_balls))
        {
            cout<<"\t\t||| SECOND INNING ENDS |||"<<endl<<endl;

            cout<<batting_team->name<<" "<<batting_team->total_runs_scored<<" - "<<batting_team->wickets_lost<<" ("<<bowling_team->total_balls_balled<<")"<<endl;
        }
        
    }
    return true;
}
void Game :: show_game_scorecard()
{
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<"\t"<<batting_team->name<<" "<<batting_team->total_runs_scored<<" "<<batting_team->wickets_lost<<" ("<<bowling_team->total_balls_balled<<")   |   "<<batsman->name<<" "<<batsman->runs_scored<<" ("<<batsman->balls_played<<")    |    "<<      bowler->name<<" "<<bowler->balls_bowled<<" - "<<bowler->runs_given<<" - "<<bowler->wickets_taken<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;

}
void Game :: start_second_innings()
{
    cout<<endl;
    cout<<"\t\t||| SECOND INNINGS STARTS |||"<<endl<<endl;
    is_first_innings = false;

    Team *temp;
    temp = batting_team;
    batting_team = bowling_team;
    bowling_team = temp;

    initialize_players();

}
void Game :: comparision()
{
    cout<<endl<<endl;
    if (TeamA.total_runs_scored>TeamB.total_runs_scored)
    {
        cout<<"\t\t\tTeam-A WON THE MATCH"<<endl<<endl;
    }
    else if(TeamA.total_runs_scored==TeamB.total_runs_scored)
    {
        cout<<"\t\t\tMATCH HAS BEEN TIED"<<endl<<endl;
    }
    else
    {
        cout<<"\t\t\tTeam-B WON THE MATCH"<<endl<<endl;
    }
    cout<<"\t\t\t||| MATCH ENDS |||\t\t"<<endl<<endl;

    final_scorecard();

}
void Game :: final_scorecard()
{

    //scorecard of Team A 
    cout<<TeamA.name<<" "<<TeamA.total_runs_scored<<" - "<<TeamA.wickets_lost<<" ("<<TeamB.total_balls_balled<<")"<<endl;

    cout<<"============================================================="<<endl;
    cout<<"|   PLAYER                 BATTING                 BOWLING  |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;

     for(int i = 0; i<players_per_team;i++)
    {
    cout<<"|["<<i<<"] "<<TeamA.players[i].name<<"\t\t    "<<TeamA.players[i].runs_scored<<"("<<TeamA.players[i].balls_played<<")"<<"\t\t    "<<TeamA.players[i].balls_bowled<<"-"<<TeamA.players[i].runs_given<<"-"<<TeamA.players[i].wickets_taken<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    }
    cout<<"============================================================="<<endl<<endl<<endl;

    //scorecard of team B
    cout<<TeamB.name<<" "<<TeamB.total_runs_scored<<" - "<<TeamB.wickets_lost<<" ("<<TeamA.total_balls_balled<<")"<<endl;

    cout<<"============================================================="<<endl;
    cout<<"|   PLAYER                 BATTING                 BOWLING  |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;

     for(int i = 0; i<players_per_team;i++)
    {
    cout<<"|["<<i<<"] "<<TeamB.players[i].name<<"\t\t    "<<TeamB.players[i].runs_scored<<"("<<TeamB.players[i].balls_played<<")"<<"\t\t    "<<TeamB.players[i].balls_bowled<<"-"<<TeamB.players[i].runs_given<<"-"<<TeamB.players[i].wickets_taken<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    }
    cout<<"============================================================="<<endl;
}
int main()
{  
    Game game;
    game.Welcome();
    game.show_all_players();
    game.select_players();
    game.show_team_players();
    game.toss();
    game.start_first_innings();
    game.play_innings();
    game.start_second_innings();
    game.play_innings();
    game.comparision();


    return 0;
}  



