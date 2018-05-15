#include "TroopRedeployment.hpp"

TroopRedeployment::TroopRedeployment() {
    this->player = NULL;
    this->map = NULL;
}

TroopRedeployment::TroopRedeployment(Map &map, Player &player) {
    this->player = &player;
    this->map = &map;
}

TroopRedeployment::~TroopRedeployment() {
    
}

void TroopRedeployment::assistTroopRedeployment() {
    int tempRegion = 0, tempTroops = 0, amountOfRaceTokens = 0;
    bool done = false, isNumber = false, isRegion = false;
    
    if(this->player->getRegionsControlled().size()==0)
    {
        cout << "You control no regions. We cannot redeploy." << endl;
    }
    else if(this->player->getRegionsControlled().size()==1)
    {
        cout << "No need to redeploy, you only control one region." << endl;
    }
    else
    {
        for(int i=0;i<this->player->getRegionsControlled().size();i++)
        {
            amountOfRaceTokens = this->map->getGraph()[this->player->getRegionsControlled().at(i)].getAmountOfRaceTokens();
            this->map->getGraph()[this->player->getRegionsControlled().at(i)].setAmountOfRaceTokens(amountOfRaceTokens-(amountOfRaceTokens-1));
            this->player->addAmountOfRaceTokens(amountOfRaceTokens-1);
        }
        while(this->player->getAmountOfRaceTokens()!=0)
        {
            cout << "You control the following regions: " << endl;
            
            for(int i=0;i<this->player->getRegionsControlled().size();i++)
            {
                cout << "Region: " << this->player->getRegionsControlled().at(i) << endl;
            }
            cout << "You have " << this->player->getAmountOfRaceTokens() << " troops to redeploy (all your regions were dropped down to 1)." << endl;
            cout << "Please choose one of the regions provided to redeploy your troops (until you have none left)." << endl;
            done = false;
            isRegion = false;
            
            while(done==false)
            {
                try
                {
                    cin >> tempRegion;
                    if(cin.fail())
                        throw "Not a number";
                    while(isRegion==false)
                    {
                        for(int i=0;i<this->player->getRegionsControlled().size();i++)
                        {
                            if(tempRegion==this->player->getRegionsControlled().at(i))
                            {
                                isRegion=true;
                                break;
                            }
                        }
                        if(isRegion==false)
                        {
                            cout << "Please choose a value from the regions provided" << endl;
                            cin >> tempRegion;
                            if(cin.fail())
                                throw "Not a number";
                        }
                    }
                    isNumber=true;
                    if(isNumber==true)
                    {
                        done=false;
                        isNumber = false;
                        cout << "How many troops would you like to place on this region?" << endl;
                        while(done==false)
                        {
                            try
                            {
                                cin >> tempTroops;
                                if(cin.fail())
                                    throw "Not a number";
                                while(tempTroops<0||tempTroops>this->player->getAmountOfRaceTokens())
                                {
                                    cout << "Please provide a value between 0 and " << this->player->getAmountOfRaceTokens() << endl;
                                    cin >> tempTroops;
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
            this->player->removeAmountOfRaceTokens(tempTroops);
            amountOfRaceTokens = this->map->getGraph()[tempRegion].getAmountOfRaceTokens();
            cout << "Previous amount of race tokens on region: " << this->map->getGraph()[tempRegion].getAmountOfRaceTokens() << endl;
            this->map->getGraph()[tempRegion].setAmountOfRaceTokens(amountOfRaceTokens+tempTroops);
            cout << "Current amount of race tokens on region: " << this->map->getGraph()[tempRegion].getAmountOfRaceTokens() << endl;
        }
    }
}
