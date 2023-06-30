#include <iostream>
#include <string>
using namespace std;

struct AdjacencyNode {
    string nodeID;
    float weight;
    AdjacencyNode* next;
};

void insertAN(AdjacencyNode*& head, const string& nodeID, float weight) {
    AdjacencyNode* temp = new AdjacencyNode;
    temp->nodeID = nodeID;
    temp->weight = weight;
    temp->next = head;
    head = temp;
}

void insertNode(string* list, const string& nodeID) {
    int c = 0;
    while (!list[c].empty())
        c++;
    list[c] = nodeID;
}

int findIndex(const string* list, const string& nodeID, int size) {
    int i = 0;
    bool found = false;
    while (i < size && !found) {
        if (list[i] == nodeID) {
            found = true;
            return i;
        }
        i++;
    }
    if (!found) {
        cout << "Node does not exist";
        exit(1);
    }
    return i;
}

void insertEdge(string* list, float** matrix, const string& startNodeID, const string& endNodeID, float weight, bool directed) {
    int i = findIndex(list, startNodeID, 5);
    int k = findIndex(list, endNodeID, 5);
    matrix[i][k] = weight;
    if (!directed)
        matrix[k][i] = weight;
}

AdjacencyNode* listOfAdjNodes(const string& nodeID, const string* nodeList, float** matrix, int size) {
    AdjacencyNode* newListHead = nullptr;
    int k = findIndex(nodeList, nodeID, size);
    for (int i = 0; i < size; i++) {
        if (matrix[k][i] != -1)
            insertAN(newListHead, nodeList[i], matrix[k][i]);
    }
    return newListHead;
}

void printAD(const AdjacencyNode* head) {
    const AdjacencyNode* current = head;
    while (current) {
        cout << current->nodeID << "\t" << current->weight << endl;
        current = current->next;
    }
}

void deleteAdjNodes(AdjacencyNode* head) {
    while (head) {
        AdjacencyNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    const int TotalNodes = 5;
    string* nodeList = new string[TotalNodes];
    for (int i = 0; i < TotalNodes; i++)
        nodeList[i] = "";

    insertNode(nodeList, "0");
    insertNode(nodeList, "1");
    insertNode(nodeList, "2");
    insertNode(nodeList, "3");
    insertNode(nodeList, "4");

    float** edgeMatrix = new float* [TotalNodes];
    for (int i = 0; i < TotalNodes; i++)
        edgeMatrix[i] = new float[TotalNodes];

    for (int i = 0; i < TotalNodes; i++) {
        for (int k = 0; k < TotalNodes; k++) {
            edgeMatrix[i][k] = -1;
        }
    }

    insertEdge(nodeList, edgeMatrix, "1", "2", 1, false);
    insertEdge(nodeList, edgeMatrix, "1", "3", 4, false);
    insertEdge(nodeList, edgeMatrix, "1", "0", 3, false);
    insertEdge(nodeList, edgeMatrix, "3", "4", 3, false);
    insertEdge(nodeList, edgeMatrix, "3", "0", 7, false);
    insertEdge(nodeList, edgeMatrix, "0", "4", 8, false);

    AdjacencyNode* adjList = listOfAdjNodes("4", nodeList, edgeMatrix, TotalNodes);
    printAD(adjList);

    // Clean up dynamically allocated memory
    deleteAdjNodes(adjList);

    for (int i = 0; i < TotalNodes; i++)
        delete[] edgeMatrix[i];
    delete[] edgeMatrix;

    delete[] nodeList;

    return 0;
}
