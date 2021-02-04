#include <string>
#include <iostream>
struct Key
{
    std::string key;
    Key * next;
};

class KeyList
{
    public:
        bool push(std::string newKeyStr)
        {
            struct Key * newKey = (Key *)malloc(sizeof(Key));
            newKey->key = newKeyStr;
            newKey->next = NULL;
            if(!newKey){return 0; }//mem err

            if(head == NULL){head = newKey;return 1;}

            Key * finder = head;
            while(finder->next!=NULL)
            {
                finder = finder->next;
            }

            finder->next = newKey;
            return 1;
        };

        bool search(std::string searchKey)
        {
            Key * finder = head;
            while(finder)
            {
                if(finder->key == searchKey){return 1;}
                finder = finder->next;
            }
            return 0;
        };
        void print()
        {
            Key * skipper = head;
            while(skipper!=NULL)
            {
                std::cout << skipper->key << std::endl;
                skipper = skipper->next;
            }
        };
        bool del_key(std::string key);

        KeyList()
        {
            head = NULL;
        };

        ~KeyList()
        {
            int count = 0;
            keyAcc(head, &count);
        };
        void keyAcc(Key * head, int * count)
        {
            if(!head){return;}
            else {keyAcc(head->next, count);}
            free(head);
            *(count) = *(count)+1;
        }
    private:
        Key * head;
};