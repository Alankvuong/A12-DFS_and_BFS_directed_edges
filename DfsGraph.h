#ifndef DFSGRAPH_H_
#define DFSGRAPH_H_

#include "main_header.h"
#include <vector>
#include <algorithm>

class DfsGraph
{
public:

    enum EDGETYPE {
      FORWARD,
      DISCOVERY,
      BACK,
      CROSS
    };

    struct Edge {
      int terminal;
      int weight;
      EDGETYPE type;
    };


    DfsGraph();

    ~DfsGraph();

    void addNode(string name);
    
    void addEdge(string initial, string terminal, int weight);

    int getIndex(string name);

    void Dfs(string initial);

    bool isStronglyConnected();

    void print();

private:
  void DfsHelper(int index);
  vector< vector<Edge> > adjList;
  vector<bool> visited;
  vector<string> names;
  int totalDistance;

  vector<int> startTimes;
  vector<int> finishTimes;
  int time;
};

// Constructor
DfsGraph::DfsGraph()
{

}

// Deconstructor
DfsGraph::~DfsGraph()
{

}

void DfsGraph::addNode(string name) {
  names.push_back(name);

  vector<Edge> tempVec;
  adjList.push_back(tempVec);
}

void DfsGraph::addEdge(string initial, string terminal, int weight) {
  int initalIndex = getIndex(initial);
  int terminalIndex = getIndex(terminal);

  vector<Edge> *initialVector = &adjList[initalIndex];

  initialVector -> push_back({terminalIndex, weight, DISCOVERY});

  sort(initialVector -> begin(), initialVector -> end(), 
  [] (const Edge& e1, const Edge& e2) { return e1.weight < e2.weight; });
}

int DfsGraph::getIndex(string name) {
  for (unsigned int i = 0; i < names.size(); i++) {
    if (name == names[i])
      return i;
  }

  return -1;
}

void DfsGraph::Dfs(string initial) 
{
  totalDistance = 0;
  int initialIndex = getIndex(initial);

  visited.resize(names.size());
  for (auto i = visited.begin(); i < visited.end(); i++) 
  {
    *i = false;
  }

  time = 0; 
  startTimes.resize(names.size());
  for (auto i = startTimes.begin(); i < startTimes.end(); i++) 
  {
    *i = 0;
  }

  finishTimes.resize(names.size());
  for (auto i = finishTimes.begin(); i < finishTimes.end(); i++) 
  {
    *i = 0;
  }

  DfsHelper(initialIndex);
}

void DfsGraph::DfsHelper(int index) 
{
  visited[index] = true;
  time++;
  startTimes[index] = time;

  cout << names[index] << endl;
  for (auto iter = adjList[index].begin(); iter < adjList[index].end(); iter++) 
  {
    if(visited[iter->terminal]){
      if (finishTimes[iter->terminal] == 0)
        iter->type = BACK;
      else if (startTimes[index] < startTimes[iter->terminal])
        iter->type = FORWARD;
      else
        iter->type = CROSS;
    }
    else 
    {
      totalDistance += iter -> weight;
      iter -> type = DISCOVERY;

      DfsHelper(iter -> terminal);
    }
  }
  time++;
  finishTimes[index] = time;

}

 bool DfsGraph::isStronglyConnected()
 {
   if (find(visited.begin(), visited.end(), false) != visited.end()) 
   {  
      return false;
   }
   else
   {
     return true;
   }
   


 }

void DfsGraph::print() 
{
  cout << "Total Distance: " << totalDistance << endl << endl;
  
  for (unsigned int i = 0; i < adjList.size(); i++) 
  {
    for (unsigned int j = 0; j < adjList[i].size(); j++) 
    {
      cout << "Initial Vertex: " << names[i] << endl;
      cout << "Terminal Vertex: " << names[adjList[i][j].terminal] << endl;
      cout << "Edge Type: ";

      if (adjList[i][j].type == FORWARD) 
      {
        cout << "Forward";
      } 
      else if (adjList[i][j].type == DISCOVERY) 
      {
        cout << "Discovery";
      } 
      else if (adjList[i][j].type == BACK) 
      {
        cout << "Back";
      } 
      else if (adjList[i][j].type == CROSS) 
      {
        cout << "Cross";
      } 
      else 
      {
        cout << "Error.";
      }
      
      cout  << endl << endl;
    }
  }
}

#endif