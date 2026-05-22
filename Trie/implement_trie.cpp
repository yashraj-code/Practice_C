#include<bits/stdc++.h>
using namespace std;

struct Node
{
    // Each element of the array links is a pointer to a Node object. 
    // This means that each element can point to a distinct Node instance or it can be nullptr (if not initialized).
    Node *links[26];
    
    // this will tell if it is the last node
    // at last latter it will be true 
    bool flag =false;

    // this will tell if the character is already inside the array or not
    bool containsKey(char ch)
        {return (links[ch-'a']!=NULL);}
    
    // here we are assigning character a new node
    // "node" here will be the new node
    void put(char ch, Node* node)
        {links[ch-'a']=node;}

    // this will provide with new reference, where we need to move forward
    Node* get(char ch)
        {return links[ch-'a'];}
    
    //This will set the flag to True
    bool setEnd()
        {flag=true;}

};

class Trie
{
    private:
        Node* root;
    
    public:

        // Initialized the data structure here
        Trie()
            {root= new Node();}

        // inserts word into the trie
        void insert(string word)
        {
            Node* node = root;  //temp variable
            for(int i=0;i<word.length(); i++)
                {
                    // if it does contain this word then
                    // create a new node and link it

                    if(!node->containsKey(word[i]))
                        {node->put(word[i],new Node());}
                    
                    // now go to next node
                    node = node->get(word[i]);
                }
                // we will now be standing at last refernce track
                // set flag condition to true
                node->setEnd();
        }

        
        // Return if the word is in Trie
        bool search(string word)
        {
            Node* node=root;
            for(int i=0;i<word.length();i++)
            {
                if(!node->containsKey(word[i]))
                    {return false;}

                // move the next
                node=node->get(word[i]);
            }

            //now we need to determine if it is a word or not, or just some starting letters
            // use flag for that info
            return node->flag;
        
        }

        bool startsWith(string prefix)
        {
            Node* node = root;
            for(int i=0;i<prefix.length();i++)
            {
                if(!node->containsKey(prefix[i]))
                    {return false;}
                
                node=node->get(prefix[i]);
            }

            return true;
        }
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) 
    {
		if (type[i] == 1) 
            {trie.insert(value[i]);}
		else if (type[i] == 2) 
        {
			if (trie.search(value[i])) 
                {cout << "true" << "\n";}
			else 
                {cout << "false" << "\n";}
		}
		else 
        {
			if (trie.startsWith(value[i])) 
                {cout << "true" << "\n";}
			else 
                {cout << "false" << "\n";}
		}
	}
}