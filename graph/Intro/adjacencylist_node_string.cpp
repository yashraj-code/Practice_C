/*
Another way of creating Graph Data Structure
Here each node is not an integer andd represents a city name 
here the node will be a name and directional also
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<list>
using namespace std;

class Node
{
public:
    string name;    // name of the city
    list<string> neigh;

    /*
    we are creating a list inside our node object and  will contain its neighbours
    */

   Node(string name)
        {this->name=name;}
};


class Graph
{
    // All Nodes
    // Hashmap (string,Node*)
    // This hashmap wwill store the relationship btw the keys that are the city names to the node objects

    unordered_map<string,Node*> m;

    public:
        Graph(vector<string> cities)
        {
            // create all the node objects off cities 
            // now we need to add eddges/ connection
            for(auto city:cities)
                {m[city] = new Node(city);}
        }
    
    void addEdge(string x, string y, bool undir=false)
    {
        m[x]->neigh.push_back(y);
        if(undir)
            {m[y]->neigh.push_back(x);}
    }

    void printAdjList()
    {
		for(auto cityPair : m)
        {
			auto city = cityPair.first;
			cout<<city<<"-->";

            // iterate on neightbours
			Node *node = cityPair.second;
			for(auto nbr : node->neigh)
                {cout<<nbr<<",";}
                
			cout<<endl;
		}
	}
};

int main()
{
	vector<string> cities = {"Delhi","London","Paris","New York"};
	Graph g(cities);
	g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New York");

	g.printAdjList();
	

	return 0;
}