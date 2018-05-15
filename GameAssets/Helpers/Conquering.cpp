#include "Conquering.hpp"

Conquering::Conquering() {
    this->raceTokensOnNode = 0;
    this->playerCurrentRaceTokens = 0;
    this->regionToConquer = 0;
    this->raceTokensRequired = 0;
}

Conquering::Conquering(Map &map, Player &player) {
    this->raceTokensOnNode = 0;
    this->playerCurrentRaceTokens = 0;
    this->regionToConquer = 0;
    this->raceTokensRequired = 0;
    this->map = &map;
    this->player = &player;
}

Conquering::~Conquering() {
}

int Conquering::calculateAmountOfTokens() {
    return 0;
}

int Conquering::getAmountOfAvailableTokens() {
    return 0;
}

void Conquering::assistConquer() {
    bool canConquer = false, troopRedeployment = false, done = false, isNumber = false, isOutsideEdge = false, correctInput = false, isAdjacent = false;
    vector<int> temp = player->getRegionsControlled();
    int amountOfRaceTokens, diceValue = 0;
    string keepConquering;
    
    while(player->getAmountOfRaceTokens()>0)
    {
        // This is for first turn conquering where the user can only choose outside edges
        
        // TODO: condition to keep conquering, no need for exception handling (boost::iequals)
        
        cout << "Would you like to conquer/keep conquering any regions?" << endl;
        
        while(correctInput==false)
        {
            cin >> keepConquering;
            if(boost::iequals(keepConquering, "yes"))
            {
                correctInput = true;
            }
            else if(boost::iequals(keepConquering, "no"))
            {
                correctInput = true;
            }
            else
            {
                cout << "Please enter yes or no" << endl;
            }
        }
        if(keepConquering=="no")
        {
            break;
        }
        
        while((canConquer!=true && player->isFirstTurn()) || player->getRegionsControlled().size()==0)
        {
            amountOfRaceTokens = 0;
            this->playerCurrentRaceTokens = player->getAmountOfRaceTokens();
            
            if(playerCurrentRaceTokens<=1 && canConquer == false)
            {
                troopRedeployment = true;
                break;
            }
            
            cout << "You have " << this->playerCurrentRaceTokens << " race tokens." << endl;
            // Print outside edges that the user can conquer
            this->map->printOutsideEdges();
            // Value the user wants to conquer
            cout << "Please enter a region: " << endl;
            done=false;
            isOutsideEdge=false;
            isNumber=false;
            while(done==false)
            {
                try
                {
                    cin >> this->regionToConquer;
                    if(cin.fail())
                        throw "Not a number";
                    while(isOutsideEdge==false)
                    {
                        for(int i=0;i<map->getOutsideEdges().size();i++)
                        {
                            if(this->regionToConquer==map->getOutsideEdges().at(i))
                            {
                                isOutsideEdge=true;
                                break;
                            }
                        }
                        if(isOutsideEdge==false)
                        {
                            this->map->printOutsideEdges();
                            cout << "Please choose a value from the adjacent ones provided" << endl;
                            cin >> this->regionToConquer;
                            if(cin.fail())
                                throw "Not a number";
                        }
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
            
            this->raceTokensOnNode = map->getGraph()[regionToConquer].getAmountOfRaceTokens();
            this->raceTokensRequired = raceTokensOnNode + 2;
            
            /* Need to test and see if it matches with the edges that they can conquer */
            for(int i=0;i<map->getOutsideEdges().size();i++)
            {
                if(regionToConquer==map->getOutsideEdges().at(i) && playerCurrentRaceTokens>=raceTokensRequired)
                {
                    while(amountOfRaceTokens<raceTokensRequired || amountOfRaceTokens>playerCurrentRaceTokens)                //TODO: Need to account for different situations
                    {
                        cout << "You currently hold " << playerCurrentRaceTokens << " race tokens.";
                        cout << "The minimum amount that you need is: " << raceTokensRequired << endl;
                        
                        done = false;
                        isNumber=false;
                        while(done==false)
                        {
                            try
                            {
                                cin >> amountOfRaceTokens;
                                if(cin.fail())
                                    throw "Not a number";
                                while(amountOfRaceTokens<raceTokensRequired ||amountOfRaceTokens>playerCurrentRaceTokens)
                                {
                                    cout << "Please choose a value between " << raceTokensRequired << " and " << playerCurrentRaceTokens << endl;
                                    cin >> amountOfRaceTokens;
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
                    }
                    if(map->getGraph()[regionToConquer].getPlayer()!=NULL && player->getAmountOfRaceTokens()>1 && playerCurrentRaceTokens>=raceTokensRequired)
                    {
                        // If a Lost tribe token is on the region
                        if(map->getGraph()[regionToConquer].getPlayer()->getName() == "Lost Tribes")
                        {
                            map->getGraph()[regionToConquer].setPlayer(NULL);
                        }
                        // If a player is on the region
                        else
                        { // 
                            // In order to remove specific element inside a vector
                            int indexToRemove = this->map->getGraph()[regionToConquer].getPlayer()->getIndexOfRegionControlled(regionToConquer);
                            
                            this->map->getGraph()[regionToConquer].getPlayer()->getRegionsControlled().erase(this->map->getGraph()[regionToConquer].getPlayer()->getRegionsControlled().begin()+indexToRemove);
                            this->map->getGraph()[regionToConquer].getPlayer()->addAmountOfRaceTokens(raceTokensRequired-1);
                        }
                    }
                    this->map->getGraph()[regionToConquer].setAmountOfRaceTokens(amountOfRaceTokens);
                    this->player->conquers(regionToConquer, amountOfRaceTokens);
                    this->map->getGraph()[regionToConquer].setPlayer(player);
                    canConquer = true;
                    break;
                }
            }
            if(canConquer == false)
            {
                if(playerCurrentRaceTokens<raceTokensRequired)
                    cout << "You do not have enough tokens for this region " << endl;
                else
                {
                    cout << "Please enter a value from the adjacent ones provided: " << endl;
                }
                
            }
            
        }
        canConquer = false;
        bool useDice = false;
        bool lastConquest = false;
        string reinforcementDie;
        
        this->playerCurrentRaceTokens = player->getAmountOfRaceTokens();
        
        cout << "You now hold " << playerCurrentRaceTokens << " tokens." << endl;
        
        
        if(playerCurrentRaceTokens<1)
        {
            break;
        }
        else
        {
            cout << "Would you like to use your reinforcement die (this will make it your last conquest for this turn)?" << endl;
            correctInput = false;
            while(correctInput==false)
            {
                cin >> reinforcementDie;
                if(boost::iequals(reinforcementDie, "yes"))
                {
                    diceValue = player->getDice().rollDice();
                    useDice = true; // Add this to the conquest part in order to add to race token value
                    lastConquest = true;
                    correctInput = true;
                    break;
                }
                else if(boost::iequals(reinforcementDie, "no"))
                {
                    correctInput = true;
                }
                else
                {
                    cout << "Please enter yes or no" << endl;
                }
            }
        }
        
        while(canConquer!=true)
        {
            this->playerCurrentRaceTokens = player->getAmountOfRaceTokens();
            temp = this->player->getRegionsControlled();
            int tempIndex = 0;
            if((playerCurrentRaceTokens+diceValue)<2 && canConquer == false)
            {
                troopRedeployment = true;
                break;
            }
            
            for(int i=0;i<this->player->getRegionsControlled().size();i++)
            {
                cout << "You control region: " << this->player->getRegionsControlled().at(i) << endl;
            }
            map->printAdjacentRegions(temp, false);
            
            cout << "You can conquer any of the adjacent regions (except the ones you already control), please choose one: " << endl;
            amountOfRaceTokens = 0;
            
            done = false;
            isAdjacent = false;
            isNumber = false;
            while(done==false)
            {
                try
                {
                    cin >> this->regionToConquer;
                    if(cin.fail())
                        throw "Not a number";
                    while(isAdjacent==false)
                    {
                        for(int i=0;i<this->player->getRegionsControlled().size();i++)
                        {
                            for(int j=0; j<this->map->getGraph()[this->player->getRegionsControlled().at(i)].getAdjacentRegionsIndex().size(); j++)
                            {
                                // Test whether they are equal and ensure that it is not a sea
                                if(this->regionToConquer == this->map->getGraph()[this->player->getRegionsControlled().at(i)].getAdjacentRegionsIndex().at(j) && this->map->getGraph()[this->map->getGraph()[this->player->getRegionsControlled().at(i)].getAdjacentRegionsIndex().at(j)].getRegion()->getName()!="Sea")
                                {
                                    isAdjacent=true;
                                    break;
                                }
                            }
                        }
                        if(isAdjacent==false)
                        {
                            for(int i=0;i<this->player->getRegionsControlled().size();i++)
                            {
                                map->printAdjacentRegions(temp, false);
                            }
                            cout << "Please choose a value from the adjacent ones provided" << endl;
                            cin >> this->regionToConquer;
                            if(cin.fail())
                                throw "Not a number";
                        }
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
            
            this->raceTokensOnNode = map->getGraph()[regionToConquer].getAmountOfRaceTokens();
            this->raceTokensRequired = raceTokensOnNode + 2;
            
            for(int i=0;i<player->getRegionsControlled().size();i++)
            {
                int temp = player->getRegionsControlled().at(i);
                for(int j=0;j<map->getGraph()[temp].getAdjacentRegionsIndex().size();j++)
                {
                    /* Test if the conquering region is amongst the adjacent regions the player can conquer */
                    if(this->regionToConquer==map->getGraph()[temp].getAdjacentRegionsIndex().at(j)) // Need to test for sea
                    {
                        // If no player is on the region
                        if(map->getGraph()[regionToConquer].getPlayer()==NULL && player->getAmountOfRaceTokens()>1 && playerCurrentRaceTokens>=raceTokensRequired) // Region is empty
                        {
                            while(amountOfRaceTokens<raceTokensRequired || amountOfRaceTokens>playerCurrentRaceTokens)
                            {
                                if(useDice==true && diceValue>0)
                                {
                                    cout << "You have additional reinforcements of: " << diceValue << endl;
                                    raceTokensRequired -= diceValue;
                                    if(raceTokensRequired<1)
                                        raceTokensRequired = 1;
                                    cout << "You currently hold " << playerCurrentRaceTokens << " race tokens.";
                                    cout << "The minimum amount that you need is: " << raceTokensRequired << endl;
                                }
                                else
                                {
                                    cout << "You currently hold " << playerCurrentRaceTokens << " race tokens.";
                                    cout << "The minimum amount that you need is: " << raceTokensRequired << endl;
                                }
                                
                                /* Additional dice roll if it is used */
                                done = false;
                                isNumber=false;
                                
                                while(done==false)
                                {
                                    try
                                    {
                                        cin >> amountOfRaceTokens;
                                        if(cin.fail())
                                            throw "Not a number";
                                        while(amountOfRaceTokens<raceTokensRequired ||amountOfRaceTokens>playerCurrentRaceTokens)
                                        {
                                            cout << "Please choose a value between " << raceTokensRequired << " and " << playerCurrentRaceTokens << endl;
                                            cin >> amountOfRaceTokens;
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
                            }
                            this->map->getGraph()[regionToConquer].setAmountOfRaceTokens(amountOfRaceTokens);
                            this->player->conquers(regionToConquer, amountOfRaceTokens);
                            this->map->getGraph()[regionToConquer].setPlayer(player);
                            canConquer = true;
                            break;
                        }
                        
                        // If a player or lost tribe token is on the region
                        else if(map->getGraph()[regionToConquer].getPlayer()!=NULL && player->getAmountOfRaceTokens()>1 && playerCurrentRaceTokens>=raceTokensRequired)
                        {
                            while(amountOfRaceTokens<raceTokensRequired || amountOfRaceTokens>playerCurrentRaceTokens)
                            {
                                if(useDice==true && diceValue>0)
                                {
                                    cout << "You have additional reinforcements of: " << diceValue << endl;
                                    raceTokensRequired -= diceValue;
                                    if(raceTokensRequired<1)
                                        raceTokensRequired = 1;
                                    cout << "You currently hold " << playerCurrentRaceTokens << " race tokens.";
                                    cout << "The minimum amount that you need is: " << raceTokensRequired << endl;
                                }
                                else
                                {
                                    cout << "You currently hold " << playerCurrentRaceTokens << " race tokens.";
                                    cout << "The minimum amount that you need is: " << raceTokensRequired << endl;
                                }
                                /* Additional dice roll if it is used */
                                done = false;
                                isNumber=false;
                                while(done==false)
                                {
                                    try
                                    {
                                        cin >> amountOfRaceTokens;
                                        if(cin.fail())
                                            throw "Not a number";
                                        while(amountOfRaceTokens<raceTokensRequired ||amountOfRaceTokens>playerCurrentRaceTokens)
                                        {
                                            cout << "Please choose a value between " << raceTokensRequired << " and " << playerCurrentRaceTokens << endl;
                                            cin >> amountOfRaceTokens;
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
                            }
                            // If a Lost tribe token is on the region
                            if(map->getGraph()[regionToConquer].getPlayer()->getName() == "Lost Tribes")
                            {
                                map->getGraph()[regionToConquer].setPlayer(NULL);
                            }
                            // If a player is on the region
                            else
                            {
                                // In order to remove specific element inside a vector
                                int indexToRemove = this->map->getGraph()[regionToConquer].getPlayer()->getIndexOfRegionControlled(regionToConquer);
                                
                                this->map->getGraph()[regionToConquer].getPlayer()->getRegionsControlled().erase(this->map->getGraph()[regionToConquer].getPlayer()->getRegionsControlled().begin()+indexToRemove);
                                this->map->getGraph()[regionToConquer].getPlayer()->addAmountOfRaceTokens(raceTokensRequired-1);
                            }
                            this->map->getGraph()[regionToConquer].setAmountOfRaceTokens(amountOfRaceTokens);
                            this->player->conquers(regionToConquer, amountOfRaceTokens);
                            this->map->getGraph()[regionToConquer].setPlayer(player);
                            canConquer = true;
                            break;
                        }
                        else
                        {
                            cout << "=============== You do not have enough tokens to conquer this regions ===============" << endl;
                            cout << "You need " << raceTokensRequired << " and you have " << playerCurrentRaceTokens << " (with dice roll included if used)."<< endl;
                        }
                    }
                }
            }
            if(canConquer == false)
                cout << "Please enter a value from the adjacent ones provided: " << endl;
        }
        if(troopRedeployment==true || lastConquest==true)
            break;
        cout << endl;
    }
}
