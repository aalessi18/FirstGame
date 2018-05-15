#include "Map.hpp"
#include "ReinforcementDie.hpp"
#include "Player.hpp"
#include <cstdlib> // for rand, srand
#include <iostream>
#include "SpecialPower.hpp"
#include "Race.hpp"
#include "MapLoader.hpp"
#include "Tokens.hpp"
#include "SummarySheets.hpp"
#include "VictoryCoin.hpp"
#include "TurnMarker.hpp"
#include <SDL2/SDL.h> //GUI Library
#include <algorithm> // for random device and mt19937
#include <random> // for random device and mt19937
#include <boost/algorithm/string/predicate.hpp> // for boost:iequals
#include "GameSetup.hpp"
#include "Conquering.hpp"
#include "VictoryCoinAssist.hpp"
#include "GamePhase.hpp"
#include "PhaseObserver.hpp"
#include "GameStatisticsObserver.hpp"
#include "TurnMarkerObserver.hpp"
#include "GameStatisticsObserverDecorator.hpp"
#include "VictoryCoinObserver.hpp"
#include "VictoryCoinObserverDecorator.hpp"
#include "PlayerHands.hpp"
#include "PlayerHandsObserver.hpp"
#include "PlayerHandObserverDecorator.hpp"
#include "Strategy.hpp"
#include "Abandoning.hpp"
#include "EnterDecline.hpp"
#include "TroopRedeployment.hpp"

using namespace std;

/* Sorting method to set players in clockwise fashion based on pointiest ears */
bool sortByPlayerNumber(const Player *one, const Player *two){
    return one->Player::getPlayerNumber() < two->Player::getPlayerNumber();
}

/*
 @author: Alexander Alessi
 */

int main() {
    srand(time(0)); // Needed in order to reset dice rolls
    /*
     Need the following two, in order to have different randomized results every time we run the shuffle method
     */
    random_device rd;
    mt19937 g(rd());
    vector<int> arr = {2,3,4,5};
    int numberOfPlayers = 0, firstPlayer;
    vector<Race*> races;
    races.reserve(14);
    vector<SpecialPower*> specialPowers;
    specialPowers.reserve(20);
    vector<int> comboCost = {0,0,0,0,0,0};
    comboCost.reserve(6);
    vector<Token*> tokens;
    vector<int> outsideEdges;
    bool correctInput = false;
    string abandon;
    
    // Following segment is simply adding the different types of strategies inside of a vector
    Aggressive* aggressive = new Aggressive();
    Defensive* defensive = new Defensive();
    Moderate* moderate = new Moderate();
    
    vector<Strategy*> strategies;
    strategies.push_back(aggressive);
    strategies.push_back(defensive);
    strategies.push_back(moderate);
    
    cout << "Welcome to Small World. How many players would you like to play?" << endl;

    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << " player(s)?" << endl;
    }
    
    bool isNumber = false, done = false;
    
    while(done==false)
    {
        try
        {
            cin >> numberOfPlayers;
            if(cin.fail())
                throw "Not a number";
            while(numberOfPlayers<2||numberOfPlayers>5)
            {
                cout << "Please choose a value between 2-5" << endl;
                cin >> numberOfPlayers;
                if(cin.fail())
                    throw "Not a number";
            }
            isNumber=true;
        }
        catch(char const* s)
        {
            cout << s << endl;
            cout << "Please input a number" << endl;
            cin.clear(); //clear bad input flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        }
        if(isNumber==true)
            done=true;
    }

    
    VictoryCoin victoryCoins(numberOfPlayers);
    vector<Player*> players(numberOfPlayers);
    TurnMarker turnMarker(numberOfPlayers);
    
    // Creating the map and loading its content
    Map map;
    MapLoader mapLoader;
    map = mapLoader.readContents(numberOfPlayers,map);
    
    // Setting up everything the game needs on the map
    GameSetup gs;
    map = gs.setUpGame(map, numberOfPlayers, races, specialPowers, tokens);
    
    // Creating players
    for(int i=0;i<numberOfPlayers;i++)
    {
        string name;
        cout << "Player " << i+1 << " enter your name: " << endl;
        players.at(i) = new Player(); //numberOfPlayer times
        players.at(i)->setPlayerNumber(i+1);
        
        // No input mismatch handling since the user can choose to have numbers in their names
        cin >> name;
        players.at(i)->setName(name);
        
        // Asking the user what kind of strategy he would like to follow for this game
        string tempStrategy;
        cout << "Do you want to be an Aggressive, Defensive or Moderate player? If you want a random one, simply write 'Random' " << endl;
        
        cin >> tempStrategy;
        
        while(correctInput==false)
        {
            // No input mismatch in this case, it is being handled with a boolean since there are specific entries that need to be inputted
            if(boost::iequals(tempStrategy, "aggressive"))
            {
                // set strategy
                players.at(i)->setStrategy(new Aggressive);
                cout << players.at(i)->getStrategy()->suggestionForStrategy();
                correctInput = true;
            }
            else if(boost::iequals(tempStrategy, "defensive"))
            {
                // set strategy
                players.at(i)->setStrategy(new Defensive);
                cout << players.at(i)->getStrategy()->suggestionForStrategy();
                correctInput = true;
            }
            else if(boost::iequals(tempStrategy, "moderate"))
            {
                // set strategy
                players.at(i)->setStrategy(new Moderate);
                cout << players.at(i)->getStrategy()->suggestionForStrategy() << endl;
                correctInput = true;
            }
            else if(boost::iequals(tempStrategy, "random"))
            {
                // Generate a random strategy
                shuffle(strategies.begin(), strategies.end(), g);
                
                players.at(i)->setStrategy(strategies.at(0));
                cout << players.at(i)->getStrategy()->suggestionForStrategy() << endl;
                correctInput = true;
            }
            else
            {
                cout << "Please choose a strategy provided." << endl;
                cin >> tempStrategy;
            }
        }
        correctInput = false;
    }
    
    // This is where the game will keep looping until the last turn
    
    shuffle(races.begin(), races.end(), g);
    shuffle(specialPowers.begin(), specialPowers.end(), g);
    
    cout << "Players: " << endl;
    for(int i=0;i<players.size();i++)
    {
        cout << "Player #" << i+1 << " " << players.at(i)->getName() << endl;
    }
    
    // Feature to choose which player starts first
    done=false;
    isNumber=false;
    
    cout << "Enter the number of the player who has the pointiest ears:" << endl;
    
    while(done==false)
    {
        try
        {
            cin >> firstPlayer;
            if(cin.fail())
                throw "Not a number";
            while(firstPlayer<1 ||firstPlayer>numberOfPlayers)
            {
                cout << "Please choose a value between 1 and " << numberOfPlayers<< endl;
                cin >> firstPlayer;
                if(cin.fail())
                    throw "Not a number";
            }
            isNumber=true;
        }
        catch(char const* s)
        {
            cout << s << endl;
            cout << "Please input a number" << endl;
            cin.clear(); //clear bad input flag
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        }
        if(isNumber==true)
            done=true;
    }
    
    for(int i=0;i<players.size();i++)
    {
        if(players.at(i)->getPlayerNumber()==firstPlayer)
        {
            cout << players.at(i)->getName() << " will be the first player." << endl;
            int temp = 1, tempIndex=i;
            players.at(i)->setPlayerNumber(temp);
            while((i+1)<players.size())
            {
                players.at(i+1)->setPlayerNumber(++temp);
                i++;
            }
            i=0;
            while(i<tempIndex)
            {
                players.at(i)->setPlayerNumber(++temp);
                i++;
            }
            break;
        }
    }
    
    // This sorts the order of the vector in order to have the players in clockwise order
    sort(players.begin(), players.end(), sortByPlayerNumber);

    // Initializing different observers/decorators that will be used for the game
    GameStatisticsObserver* gameStatsObserver = new GameStatisticsObserver(map, players);
    TurnMarkerObserver turnMarkerObserver(turnMarker);
    PlayerHands playerHands(players);
    PlayerHandsObserver* playerHandsObserver = new PlayerHandsObserver(playerHands);
    
    gameStatsObserver = new GameStatisticsObserverDecorator(gameStatsObserver);
    playerHandsObserver = new PlayerHandsDecorator(playerHandsObserver);
    
    // Vector of booleans for different players in order to see if the player wants to keep the undecorated or decorated observers
    vector<bool> statsAndHandDecorator;
    vector<bool> victoryCoinsDecorator;
    
    for(int i=0;i<players.size();i++)
    {
        cout << "Player #" << players.at(i)->getPlayerNumber() << " is: "  << players.at(i)->getName() << endl;
        statsAndHandDecorator.push_back(false);
        victoryCoinsDecorator.push_back(false);
    }
    
    cout << "================================= Turn #" << turnMarker.getTurnTracker() << " =================================" << endl;
    
    // Game will loop here until we reach the last turn, where the last turn will be played
    while(turnMarker.getTurnTracker()<=turnMarker.getTotalTurns())
    {
        int playersTurn = 0;
        
        // Temp variable to choose which player does their move

        while(playersTurn<numberOfPlayers)
        {
            //======================= remove conquer and canConquer
            int combo, raceTokens;
            
            /*
             Initializing the Conquering object which assists with the player's conquer method.
             The GamePhase and PhaseObserver are the objects required in order to print out the correct state the player is in.
             */
            Conquering conquerHelper(map,*players.at(playersTurn));
            GamePhase gamePhase(*players.at(playersTurn));
            PhaseObserver phaseObserver(gamePhase);
            TroopRedeployment troopRedeployment(map,*players.at(playersTurn));
            
            /*
             In order to show the first 6 Races and Abilities, and their associated victory points (if any) and the amount of
             army tokens the user would get if they chose that combination.
             */
            cout << "//================ Available races and Special Abilities: ================//" << endl;
            for(int i=0;i<6;i++)
            {
                cout << "#" << i+1 << ": " <<specialPowers.at(i)->getName() << " " << races.at(i)->getName() << " " << comboCost.at(i) << " victory coins.";
                int temp = specialPowers.at(i)->getTokenAmount() + races.at(i)->getTokenAmount();
                cout << " Total army token value: " << temp << endl;
            }
            
            cout << "\n=============================== " << players.at(playersTurn)->getName() << "'s turn =============================== " << endl;
            
            // The following code asks the user if they would like the basic or the decorated observers
            if(statsAndHandDecorator.at(playersTurn)==false)
            {
                string temp;
                cout << "Would you like to use more detailed statistics?" << endl;
                cin >> temp;
                correctInput = false;
                
                // No input mismatch handling since only specific inputs must be provided
                while(correctInput==false)
                {
                    if(boost::iequals(temp, "no"))
                    {
                        gameStatsObserver->setDetailedDecorator(false);
                        correctInput = true;
                    }
                    
                    else if(boost::iequals(temp, "yes"))
                    {
                        gameStatsObserver->setDetailedDecorator(true);
                        correctInput = true;
                    }
                    else
                    {
                        cout << "Please choose between yes or no." << endl;
                        cin >> temp;
                    }
                }
                
                cout << "Would you like to use more detailed player hands?" << endl;
                cin >> temp;
                correctInput = false;
                
                // No input mismatch handling since only specific inputs must be provided
                while(correctInput==false)
                {
                    if(boost::iequals(temp, "no"))
                    {
                        playerHandsObserver->setDetailedDecorator(false);
                        correctInput = true;
                    }
                    
                    else if(boost::iequals(temp, "yes"))
                    {
                        playerHandsObserver->setDetailedDecorator(true);
                        correctInput = true;
                    }
                    else
                    {
                        cout << "Please choose between yes or no." << endl;
                        cin >> temp;
                    }
                }
                
                // This section asks if the user would like to make his choices temporary or permanent for the entire game
                cout << "Would you like to make these choices permanent?" << endl;
                cin >> temp;
                correctInput = false;
                
                while(correctInput==false)
                {
                    if(boost::iequals(temp, "yes"))
                    {
                        statsAndHandDecorator.at(playersTurn) = true;
                        correctInput = true;
                    }
                    else if(boost::iequals(temp, "no"))
                    {
                        correctInput = true;
                    }
                    else
                    {
                        cout << "Please choose between yes or no." << endl;
                        cin >> temp;
                    }
                }
            }
            
            /*
             The following is when it is the player's first turn (whether the first round or when they choose
             a new combination after a decline has occured
             */
            
            if(players.at(playersTurn)->isFirstTurn()==true)
            {
                done = false;
                isNumber = false;
                
                cout << "Please choose a special ability and race combo above: " << endl;
                while(done==false)
                {
                    try
                    {
                        cin >> combo;
                        if(cin.fail())
                            throw "Not a number";
                        while(combo<1 ||combo>6)
                        {
                            cout << "Please choose a value between 1 and 6" << endl;
                            cin >> combo;
                            if(cin.fail())
                                throw "Not a number";
                        }
                        isNumber=true;
                    }
                    catch(char const* s)
                    {
                        cout << s << endl;
                        cout << "Please input a number" << endl;
                        cin.clear(); //clear bad input flag
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
                    }
                    if(isNumber==true)
                        done=true;
                }
                players.at(playersTurn)->picks_race(races.at(combo-1));
                
                // Show the user picked a race
                gamePhase.setGamePhase("Picked a race");
                players.at(playersTurn)->setSpecialPower(specialPowers.at(combo-1));
                
                // adds victorycoins on the combo the user chose
                victoryCoins.removeFromVictoryCoins(comboCost.at(combo-1), players.at(playersTurn)->getVictoryCoins());
                
                // Adds up the amount of raceTokens the player will have
                raceTokens = players.at(playersTurn)->getActiveRace()->getTokenAmount() + players.at(playersTurn)->getSpecialPower()->getTokenAmount();
                players.at(playersTurn)->setAmountOfRaceTokens(players.at(playersTurn)->getActiveRace()->getTokenAmount() , players.at(playersTurn)->getSpecialPower()->getTokenAmount());
                players.at(playersTurn)->getActiveRace()->removeRaceTokens(raceTokens);
                races.erase(races.begin()+(combo-1));
                specialPowers.erase(specialPowers.begin()+(combo-1));
                
                // Reprints the new combinations once the player has chosen their combination
                cout << "New available combos: " << endl;
                cout << "//================ Available races and Special Abilities: ================//" << endl;
                for(int i=0;i<6;i++)
                {
                    if(i<(combo-1))
                    {
                        /*
                         Updates the amount of victory points on the current available banners as well as reducing the player's victory points
                         by the amount needed to obtain the chosen combo the user wishes to have
                         */
                        comboCost.at(i)+= 1;
                        victoryCoins.addToVictoryCoins(1, players.at(playersTurn)->getVictoryCoins());
                    }
                    cout << "#" << i+1 << ": " <<specialPowers.at(i)->getName() << " " << races.at(i)->getName() << " " << comboCost.at(i) << " victory coins" << endl;
                }
                cout << endl;
                
                // This method is the one that will notify the observer in order to print out both players's hands
                playerHands.showHands();
                correctInput = false;
                if(players.at(playersTurn)->getRegionsControlled().size()>0)
                {
                    int tempIndex;
                    cout << "Would you like to abandon any regions?" <<endl;
                    while(correctInput==false)
                    {
                        cin >> abandon;
                        if(boost::iequals(abandon, "yes"))
                        {
                            Abandoning abandoning(map, *players.at(playersTurn));
                            abandoning.assistAbandoning();
                            correctInput = true;
                            break;
                        }
                        else if(boost::iequals(abandon, "no"))
                        {
                            correctInput = true;
                        }
                        else
                        {
                            cout << "Please enter yes or no" << endl;
                        }
                    }
                }
                
                players.at(playersTurn)->printVictoryPoints();
                cout << "Your available regions that you can conquer are the following, please choose one: " << endl;
                
                // Section to abandon regions for when the user has a declined Race
                correctInput = false;
                
                // ConquerHelper uses its method in order to allow the player to conquer the region they choose (if condition are met)
                conquerHelper.assistConquer();
                gamePhase.setGamePhase("Conquered some Regions");
                troopRedeployment.assistTroopRedeployment();
                gamePhase.setGamePhase("Troops Redeployed");
                
                // Sets player's turn to not be first turn in order to move to "following turns" section of the game
                players.at(playersTurn)->setFirstTurn(false);
            }
            // Following turns section
            else
            {
                // Show players's hands at the beginning of each player's turn
                playerHands.showHands();
                string declineRace;
                
                // Before conquest, but after using abilities -> TODO: add code in order to allow abilities to be used before declining
                
                // Ask user if they would like to decline their race
                cout << "<=== Would you like to place your current race in decline? ===>" << endl;
                correctInput = false;
                while(correctInput==false)
                {
                    cin >> declineRace;
                    if(boost::iequals(declineRace, "yes"))
                    {
                        // Remove everything till they have one token on each region and set current race to declined race
                        gamePhase.setGamePhase("Declined their race");
                        EnterDecline enterDecline(map, *players.at(playersTurn));
                        enterDecline.assistDecline();
                        players.at(playersTurn)->setFirstTurn(true);
                        playerHands.showHands();
                        correctInput = true;
                    }
                    else if(boost::iequals(declineRace, "no"))
                    {
                        correctInput = true;
                    }
                    else
                    {
                        cout << "Please enter yes or no" << endl;
                    }
                }
                
                if(boost::iequals(declineRace, "no"))
                {
                    int amountOfRaceTokens = 0;
                    int tempAmountOfRaceTokens = 0;
                    for(int i=0;i<players.at(playersTurn)->getRegionsControlled().size();i++)
                    {
                        amountOfRaceTokens = 0;
                        tempAmountOfRaceTokens = 0;
                        tempAmountOfRaceTokens = map.getGraph()[players.at(playersTurn)->getRegionsControlled().at(i)].getAmountOfRaceTokens();
                        amountOfRaceTokens += tempAmountOfRaceTokens-1;
                        map.getGraph()[players.at(playersTurn)->getRegionsControlled().at(i)].setAmountOfRaceTokens(tempAmountOfRaceTokens-amountOfRaceTokens);
                        players.at(playersTurn)->addAmountOfRaceTokens(amountOfRaceTokens);
                    }
                    Conquering conquerHelper(map,*players.at(playersTurn));
                    TroopRedeployment troopRedeployment(map,*players.at(playersTurn));
                    // Section to abandon regions
                    correctInput = false;
                    
                    if(players.at(playersTurn)->getRegionsControlled().size()>0)
                    {
                        cout << "Would you like to abandon any regions?" <<endl;
                        while(correctInput==false)
                        {
                            cin >> abandon;
                            if(boost::iequals(abandon, "yes"))
                            {
                                Abandoning abandoning(map, *players.at(playersTurn));
                                abandoning.assistAbandoning();
                                correctInput = true;
                                break;
                            }
                            else if(boost::iequals(abandon, "no"))
                            {
                                correctInput = true;
                            }
                            else
                            {
                                cout << "Please enter yes or no" << endl;
                            }
                        }
                    }
                    conquerHelper.assistConquer();
                    gamePhase.setGamePhase("Conquered some Regions");
                    troopRedeployment.assistTroopRedeployment();
                    gamePhase.setGamePhase("Troops Redeployed");
                }
                cout << endl;
            }
            /*
             Instantiate the VictoryCoinAssist object which helps with calculating victory coins earned, as well
             as exchance in case the board runs out of certain denominations. There is also the VictoryCoinObserver Object which
             helps with printing out what the player earned and how many victory coins they currently hold.
             */
            VictoryCoinAssist victoryCoinAssist(*players.at(playersTurn), victoryCoins, players.at(playersTurn)->score());
            VictoryCoinObserver* victoryCoinObserver = new VictoryCoinObserver(victoryCoinAssist);
            victoryCoinObserver = new VictoryCoinObserverDecorator(victoryCoinObserver);
            
            // Second section of asking the user if they wish to have the basic or undecorated Observer
            if(victoryCoinsDecorator.at(playersTurn)==false)
            {
                string temp;
                cout << "Would you like to use more detailed victory coins scoring?" << endl;
                cin >> temp;
                while(correctInput==false)
                {
                    if(boost::iequals(temp, "yes"))
                    {
                        victoryCoinObserver->setDetailedDecorator(true);
                        correctInput = true;
                    }
                    else if(boost::iequals(temp, "no"))
                    {
                        victoryCoinObserver->setDetailedDecorator(false);
                        correctInput = true;
                    }
                    else
                    {
                        cout << "Please choose between yes or no." << endl;
                        cin >> temp;
                    }
                }
                
                // Ask user if they want to keep their current choices permanent
                cout << "Would you like to make this choice permanent?" << endl;
                cin >> temp;
                correctInput = false;
                
                while(correctInput==false)
                {
                    if(boost::iequals(temp, "yes"))
                    {
                        victoryCoinsDecorator.at(playersTurn) = true;
                        correctInput = true;
                    }
                    else if(boost::iequals(temp, "no"))
                    {
                        correctInput = true;
                    }
                    else
                    {
                        cout << "Please choose between yes or no." << endl;
                        cin >> temp;
                    }
                }
            }
            
            // Calculate victory coins earned by user for the current turn using the assistVictoryCoins method
            victoryCoinAssist.assistVictoryCoin();
            gamePhase.setGamePhase("Scored some Victory Points");
            
            // Delete every turn
            delete victoryCoinObserver;
            victoryCoinObserver = NULL;
            
            // Increment to start next player's turn
            playersTurn++;
        }
        // Make playersTurn 1 again in order to start again from the first player's turn
        playersTurn = 1;
        
        // Increment the turnMarker by 1
        turnMarker.updateTurnTracker();
    }
    
    int mostVictoryPoints = 0;
    
    // Final Score
    cout << "Final Score:" << endl;
    for(int i=0;i<numberOfPlayers;i++)
    {
        players.at(i)->printVictoryPoints();
    }
    
    // Pointer deletion
    for(int i=0; i<players.size();i++)
    {
        delete players.at(i);
        players.at(i) = NULL;
    }
    
    for(int i=0;i<races.size();i++)
    {
        delete races.at(i);
        races.at(i) = NULL;
    }
    
    for(int i=0;i<specialPowers.size();i++)
    {
        delete specialPowers.at(i);
        specialPowers.at(i) = NULL;
    }
    
    for(int i=0;i<tokens.size();i++)
    {
        delete tokens.at(i);
        tokens.at(i) = NULL;
    }
    
    for(int i=0; i<strategies.size(); i++)
    {
        delete strategies.at(i);
        strategies.at(i) = NULL;
    }
    
    for(int i=0; i<boost::num_vertices(map.getGraph()); i++)
    {
        delete map.getGraph()[i].getRegion();
        map.getGraph()[i].setRegion(NULL);
    }
    
    // Delete Observers
    delete gameStatsObserver;
    gameStatsObserver = NULL;
    delete playerHandsObserver;
    playerHandsObserver = NULL;
    return 0;
}
