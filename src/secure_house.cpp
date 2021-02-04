#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "house.hpp"

using namespace std;


std::string owner_name;
string input = "";

struct userkey 
{
    string username;
    string key;
};

//for the house
vector <string> inside; //list of everybody inside
vector <string> allowed;
vector <userkey> inlock; //keys in the lock
vector <string> validKeys;




//vector<string> 
int main(int argc, char * argv[])
{
    owner_name = (std::string)argv[1];
    //std::cout << "Valid keys: " << std::endl;
    for(int i = 2; i < argc; i++)
    {
        validKeys.push_back((std::string)argv[i]);
    }
    while(getline(cin, input))
    {
        cin.clear();
        
        //tokenize input
        vector <std::string> toks; 
        stringstream check1(input); 
        string intermediate; 
        while(getline(check1, intermediate, ' ')) 
        { 
            toks.push_back(intermediate); 
        } 

        //interpereting input
        if(toks[0] == "INSERT") 
        { 
            struct userkey temp = {toks[2],toks[3]};
            cout << "KEY " << temp.key << " INSERTED BY " << temp.username << endl;
            inlock.push_back(temp);
        }
        if(toks[0] == "TURN")
        {
            string turner = toks[2];
            bool keyFound = 0;
            //find turners key in the lock
            string turnersKey;
            for(int i = 0;i<inlock.size(); i++)
            {
                if( inlock[i].username == turner)//if found
                {
                    turnersKey = inlock[i].key;
                    bool validKey = 0;
                    for(int i = 0;i<validKeys.size();i++)
                    {
                        if(validKeys[i] == turnersKey)
                        {
                            validKey = 1;
                        }
                    }
                    if(validKey)
                    {
                        allowed.push_back(turner);
                        cout << "SUCCESS " << turner << " TURNS KEY " << turnersKey << endl;
                        keyFound = 1;
                    }
                }
            }
            if(!keyFound){cout << "FAILURE " << turner << " UNABLE TO TURN KEY " << turnersKey << endl;}
        }
        if(toks[0] == "ENTER")
        {
            string enterer = toks[2];
            bool permission = 0;
            for(int i = 0;i<allowed.size();i++)
            {
                if(allowed[i] == enterer)
                {
                   inside.push_back(enterer);
                   cout << "ACCESS ALLOWED" << endl; 
                   permission = 1;
                }
            }
            if(!permission)
            {
                cout << "ACCESS DENIED" << endl;
            }
        }
        if(toks[0] == "WHO'S?")
        {
            for(int i = 0; i < inside.size(); i++)
            {
                cout << inside[i] << endl;
            }
        }
    }
}