#include "Abandoning.hpp"

Abandoning::Abandoning() {
    this->map = NULL;
    this->player = NULL;
}

Abandoning::Abandoning(Map &map, Player &player) {
    this->map = &map;
    this->player = &player;
}

Abandoning::~Abandoning() {
    
}

void Abandoning::assistAbandoning() {
    bool correctInput = false, continueAbandon = true, inFor = true, done = false, isNumber = false;
    int tempIndex = 0;
    string temp;
    
    while(continueAbandon == true)
    {
        correctInput = false;
        cout << "Please choose from the following regions: " << endl;
        for(int i=0; i<this->player->getRegionsControlled().size(); i++)
        {
            cout << "Region: " << this->player->getRegionsControlled().at(i) << ". ";
            cout << "Amount of tokens on region (already removed down to 1 for conquest): " << this->map->getGraph()[player->getRegionsControlled().at(i)].getAmountOfRaceTokens() << endl;
        }
        while(done==false)
        {
            try
            {
                cin >> tempIndex;
                if(cin.fail())
                    throw "Not a number";
                while(inFor==true)
                {
                    for(int i=0; i<this->player->getRegionsControlled().size(); i++)
                    {
                        if(tempIndex == this->player->getRegionsControlled().at(i))
                        {
                            cout << "Your previous amount of tokens: " << player->getAmountOfRaceTokens() << endl;
                            int tempTroops = this->map->getGraph()[tempIndex].getAmountOfRaceTokens();
                            this->map->getGraph()[tempIndex].setAmountOfRaceTokens(0);
                            this->player->addAmountOfRaceTokens(tempTroops);
                            this->player->getRegionsControlled().erase(this->player->getRegionsControlled().begin()+i);
                            cout << "Your new amount of tokens: " << player->getAmountOfRaceTokens() << endl;
                            this->map->getGraph()[tempIndex].setPlayer(NULL);
                            correctInput = true;
                            inFor = false;
                        }
                    }
                    if(correctInput == false)
                    {
                        cout << "Please enter a value from the regions provided" << endl;
                        cin >> tempIndex;
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
        
        correctInput = false;
        if(!this->player->getRegionsControlled().empty())
        {
            cout << "Would you like to abandon another region?" << endl;
            while(correctInput==false)
            {
                cin >> temp;
                
                if(boost::iequals(temp, "yes"))
                {
                    continueAbandon = true;
                    correctInput = true;
                    inFor = true;
                    done = false;
                    break;
                }
                else if(boost::iequals(temp, "no"))
                {
                    continueAbandon = false;
                    correctInput = true;
                    break;
                }
                else
                {
                    cout << "Please enter yes or no" << endl;
                }
            }
        }
        if(this->player->getRegionsControlled().empty())
            break;
    }
}
