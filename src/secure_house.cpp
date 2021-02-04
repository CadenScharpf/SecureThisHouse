#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "house.hpp"

using namespace std;

struct KeyInLock
{
    string username;
    string key;
};

vector<string> authorized_keys;
vector<string> authorized_users;
vector<KeyInLock> inserted_keys;
vector<string> inside_users;

string findUsersKeyInLock(string user)
{
    string key = NULL;
    for(int i = 0; i < inserted_keys.size(); i++)
    {
        if(inserted_keys[i].username == user)
        {
            return inserted_keys[i].key;
        }
    }
    return key;
}

bool checkKey(string key)
{
    for(int i = 0; i < authorized_keys.size(); i++)
    {
        if(authorized_keys[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
bool isAuthorized(string user)
{
    for(int i = 0; i < authorized_users.size(); i++)
    {
        if(authorized_users[i] == user)
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char * argv[])
{
    //initialization
    string owner_name = (std::string)argv[1];
    authorized_keys.push_back("FIREFIGHTER_SECRET_KEY");
    for(int i = 2; i < argc; i++)
    {
        authorized_keys.push_back((std::string)argv[i]);
    }

    //Main loop
    string input;
    while(getline(cin, input))
    {
        //tokenize line
        string buff;
        stringstream ss(input);
        vector<string> tokens;
        while(getline(ss,buff,' ')){ tokens.push_back(buff);};

        //determine which command
        string command = tokens[0];
        

        if(command == "INSERT")
        {
            struct KeyInLock keyToInsert={tokens[2],tokens[3]};
            inserted_keys.push_back(keyToInsert);
            cout << "KEY " << keyToInsert.key << " INSERTED BY " << keyToInsert.username << endl;
        }
        else if(command == "TURN")
        {
            string username = tokens[2];
            string usersKey = findUsersKeyInLock(username);
            if(checkKey(usersKey))
            {
                authorized_users.push_back(username);
                cout << "SUCCESS " << username << " TURNS KEY " << usersKey << endl;
            }
            else
            {
                cout << "FAILURE " << username << " UNABLE TO TURN KEY " << usersKey << endl;
            }
        }
        else if(command == "ENTER")
        {
            string username = tokens[2];
            if(isAuthorized(username))
            {
                inside_users.push_back(username);
                cout << "ACCESS ALLOWED" << endl;
            } else {cout << "ACCESS DENIED";}
        }
        else if(command == "WHO'S")
        {

            if(inside_users.size() == 0) { cout << "NOBODY HOME" << endl;}
            else
            {
                for(int i = 0; i < inside_users.size(); i++)
                {
                    cout << inside_users[i] << ", ";
                }
            }
            std::cout << endl;
        }
        else if(command == "CHANGE")
        {
            owner_name = tokens[2];
            authorized_keys.clear();
            for(int i = 3; i < tokens.size(); i++)
            {
                authorized_keys.push_back(tokens[i]);
            }
        }
        else if(command == "LEAVE")
        {
            
        }

        cin.clear();
    }
}