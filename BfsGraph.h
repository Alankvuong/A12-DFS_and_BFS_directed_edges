#ifndef BFSGRAPH_H_
#define BFSGRAPH_H_

#include "main_header.h"
#include <vector>
#include <algorithm>
#include <queue>

class BfsGraph {
public:
  enum EDGETYPE {
    DISCOVERY,
    BACK,
    CROSS
  };

  struct Edge {
    int weight = 0;
    EDGETYPE type;
  };

  BfsGraph();
  void addNode(string name);
  void addEdge(string start,string end, int distance);
  int getIndex(string name);
  void insertionSort(vector<int> &vec, int currNode);
  void Bfs(string name);
  void print();
private:
  vector<string> names;
  vector< vector<Edge> > adjMatrix;
  int totalDistance;
};

BfsGraph::BfsGraph() 
{
  totalDistance = 0;
}

void BfsGraph::addNode(string name) 
{
  names.push_back(name);

  adjMatrix.resize(names.size());
  for (unsigned int index = 0; index < adjMatrix.size(); index++) {
    adjMatrix[index].resize(names.size());
  }
}

int BfsGraph::getIndex(string name)
{
  auto it = find(names.begin(), names.end(), name);

    if(it != names.end()) 
    {
        int index = it - names.begin();
        return index;
    }
    else 
    {
        return -1;
    }
} 

void BfsGraph::insertionSort(vector<int> &vec, int currNode) 
{
    int key, j;
    for (unsigned int index = 1; index < vec.size(); index++) 
    {
        key = vec[index];
        j = index - 1;
        while (j >= 0 && adjMatrix[currNode][vec[j]].weight > adjMatrix[currNode][key].weight) 
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void BfsGraph::addEdge(string start,string end,int distance)
{
  int startI = getIndex(start);
  int endI = getIndex(end);
  Edge newEdge;
  newEdge.weight = distance;
  adjMatrix[startI][endI] = newEdge;
}

void BfsGraph::Bfs(string name) 
{
  vector<bool> visited(names.size(), false);
  queue<int> queue;
  vector<bool> level(names.size(),0);

  int currNode = getIndex(name);
  queue.push(currNode);
  visited[currNode] = true;

  while (!queue.empty()) 
  {
    int node = queue.front();
    queue.pop();

    cout << names[node] << endl;

    vector<int> adjList;
    for (unsigned int index = 0; index < adjMatrix[node].size(); index++) 
    {
      if (adjMatrix[node][index].weight > 0)
      {
        adjList.push_back(index);
      }
        
    }

    insertionSort(adjList, node);

    int nextNode;
    for (unsigned int index = 0; index < adjList.size(); index++) 
    {
      nextNode = adjList[index];
    
    if(!visited[nextNode]) 
    {
      adjMatrix[node][nextNode].type = DISCOVERY;
      visited[nextNode] = true;
      totalDistance += adjMatrix[node][nextNode].weight;
      queue.push(nextNode);
      level[nextNode] = level[node] + 1;
      
    } 
    else if (level[node] > level[nextNode]) 
    {
      adjMatrix[node][nextNode].type = BACK;
    } 
    else 
    {
      adjMatrix[node][nextNode].type = CROSS;
    }
  }
  }
  
}

void BfsGraph::print() {
   cout << "\nTotal Distance: " << totalDistance << endl << endl;
  
  for (unsigned int i = 0; i < adjMatrix.size(); i++) {
    for (unsigned int j = 0; j < adjMatrix[i].size(); j++) {
      if (adjMatrix[i][j].weight > 0) {
        cout << "Initial Vertex: " << names[i] << endl;
        cout << "Terminal Vertex: " << names[j] << endl;
        cout << "Edge Type: ";

        if (adjMatrix[i][j].type == DISCOVERY) {
          cout << "Discovery";
        } else if (adjMatrix[i][j].type == BACK) {
          cout << "Back";
        } else if (adjMatrix[i][j].type == CROSS) {
          cout << "Cross";
        } else {
          cout << "Error.";
        }
        
        cout  << endl << endl;
      }
    }
  }
}
#endif