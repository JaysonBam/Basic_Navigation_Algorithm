#include <iostream>
using namespace std;

struct node {
    string nodeID;
    node* next;
};

struct edge {
    string startnodeID;
    string endnodeID;
    float weight;
    edge* next;
};

struct adjacencyNode {
    string nodeID;
    float weight;
    adjacencyNode* next;
};

void insertAN(adjacencyNode*& head, string nodeID, float weight) {
    adjacencyNode* temp = new adjacencyNode;
    temp->nodeID = nodeID;
    temp->weight = weight;
    temp->next = head;
    head = temp;
}

void insertNode(node*& head, string nodeID) {
    node* temp = new node;
    temp->nodeID = nodeID;
    temp->next = head;
    head = temp;
}

void insertEdge(edge*& head, string startnodeID, string endnodeID, float weight) {
    edge* temp = new edge;
    temp->startnodeID = startnodeID;
    temp->endnodeID = endnodeID;
    temp->weight = weight;
    temp->next = head;
    head = temp;
}

adjacencyNode* listOfAdjNodes(string startnodeID, edge* head, bool directed) {
    edge* cEdge = head;
    adjacencyNode* NewListHead = nullptr;
    while (cEdge) {
        if (cEdge->startnodeID == startnodeID)
            insertAN(NewListHead, cEdge->endnodeID, cEdge->weight);
        if (!directed && cEdge->endnodeID == startnodeID)
            insertAN(NewListHead, cEdge->startnodeID, cEdge->weight);
        cEdge = cEdge->next;
    }
    return NewListHead;
}

void PrintAD(adjacencyNode* head) {
    adjacencyNode* c = head;
    while (c) {
        cout << c->nodeID << "\t" << c->weight << endl;
        c = c->next;
    }
}

void deleteNodes(node* head) {
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteEdges(edge* head) {
    while (head) {
        edge* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteAdjNodes(adjacencyNode* head) {
    while (head) {
        adjacencyNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Mock graph
    node* NodeList = nullptr;
    insertNode(NodeList, "0");
    insertNode(NodeList, "1");
    insertNode(NodeList, "2");
    insertNode(NodeList, "3");
    insertNode(NodeList, "4");

    
    edge* EdgeList = nullptr;
    insertEdge(EdgeList, "1", "2", 1);
    insertEdge(EdgeList, "1", "3", 4);
    insertEdge(EdgeList, "1", "0", 3);
    insertEdge(EdgeList, "3", "4", 3);
    insertEdge(EdgeList, "3", "0", 7);
    insertEdge(EdgeList, "0", "4", 8);

    adjacencyNode* adjList = listOfAdjNodes("1", EdgeList, false);
    PrintAD(adjList);

    // Clean up dynamically allocated memory
    deleteNodes(NodeList);
    deleteEdges(EdgeList);
    deleteAdjNodes(adjList);

    return 0;
}
