#include <iostream>
using namespace std;

class Node {
public:
    char id;
    Node* next;
    
    Node() {
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    
    LinkedList() {
        head = tail = NULL;
    }
    
    void insertToHead(char data) {
        Node* node = new Node();
        node->id = data;
        
        Node* tmp = head;
        head = node;
        node->next = tmp;
    }
    
    void insertToTail(char data) {
        Node* node = new Node();
        node->id = data;
        
        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    
    void insertNodeAfter(char data, char after) {
        if (tail->id == data) {
            insertToTail(data);
        } else if (head->id == data) {
            insertToHead(data);
        } else {
            Node* node = new Node();
            node->id = data;
            
            Node* tmp = head;
            while (tmp != NULL && tmp->id != after) {
                tmp = tmp->next;
            }
            
            if (tmp == NULL) {
                cout << "After node is not found";
            } else {
                node->next = tmp->next;
                tmp->next = node;
            }
        }
    }
    
    void printALL() {
        if (head != NULL) {
            Node* tmp = head;
            do {
                cout << tmp->id << "->";
                tmp = tmp->next;
            } while (tmp != NULL);
            cout << "NULL" << endl;
        }
    }
    
    void deleteNode(char data) {
        if (head == NULL) {
            return;
        }
        
        if (head->id == data) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            if (head == NULL) {
                tail = NULL;
            }
            return;
        }
        
        Node* tmp = head;
        while (tmp->next != NULL && tmp->next->id != data) {
            tmp = tmp->next;
        }
        
        if (tmp->next == NULL) {
            cout << "Node with given data not found." << endl;
            return;
        }
        
        Node* nodeToDelete = tmp->next;
        tmp->next = nodeToDelete->next;
        if (tmp->next == NULL) {
            tail = tmp;
        }
        delete nodeToDelete;
    }
};

int main(int argc, char** argv) {
    LinkedList* link1 = new LinkedList();
    
    Node* node1 = new Node();
    node1->id = 'A';
    
    link1->head = node1;
    link1->tail = node1;
    
    Node* nodeX = new Node();
    nodeX->id = 'X';
    
    Node* tmp = link1->head;
    link1->head = nodeX;
    nodeX->next = tmp;
    
    link1->insertToHead('Y');
    link1->insertNodeAfter('Z', 'X');
    
    
	cout << link1->head->id << endl;
	cout << link1->tail->id << endl;

    link1->printALL();
    
    link1->deleteNode('Y');
    link1->printALL();
    
    return 0;
}
