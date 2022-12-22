#include <iostream>

using namespace std;

class Node {
    public:
    int key;
    int data;
    Node* next;
    
    // constructor
    Node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList {
    public:
    Node* head;
    
    // constructor
    SinglyLinkedList(Node* n) {
        head = n;
    }
    
    Node* nodeExists(int k) {
        Node* ptr = head;
        while(ptr!=NULL) {
            if(ptr->key == k) {
                break;
            }
            else {
                ptr = ptr->next;
            }
        }
        return ptr;
    }
    
    void appendNode(Node* n) {
        if(nodeExists(n->key)) {
            cout << "Node with key = " << n->key << " already exists.\n";
        }
        else {
            Node* ptr = head;
            while(ptr->next!=NULL) {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
    
    void deleteNode(int k) {
        if(!nodeExists(k)) {
            cout << "Node with key = " << k << " doesn't exists.\n";
        }
        else {
            Node* ptr = head;
            if(head->key == k) {
                head = head->next;
                ptr->next = NULL;
            }
            else {
                Node* currentNode = ptr->next;
                while(currentNode->key != k) {
                    currentNode = currentNode->next;
                    ptr = ptr->next;
                }
                ptr->next = currentNode->next;
                currentNode->next = NULL;
            }
        }
    }
    
    void insertNode(int k, Node* n) {
        if(nodeExists(n->key)) {
            cout << "Node with key = " << n->key << " doesn't exists.\n";
        }
        else {
            Node* ptr = head;
            while(ptr->key != k) {
                ptr = ptr->next;
            }
            n->next = ptr->next;
            ptr->next = n;
        }
    }
    
    void prependNode(Node* n) {
        if(nodeExists(n->key)) {
            cout << "Node with key = " << n->key << " doesn't exists.\n";
        }
        else {
            n->next = head;
            head = n;
        }
    }
    
    void printList() {
        Node* ptr = head;
        cout << "\n(key : value)\n";
        while(ptr!=NULL) {
            if(ptr->next != NULL) {
                cout << '(' << ptr->key << " : " << ptr->data << "), ";
            }
            else {
                cout << '(' << ptr->key << " : " << ptr->data << ")";
            }
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    Node n1(1,1);
    SinglyLinkedList s(&n1);
    int option;
    do {
        cout << "\nLinked list simulation\n";
        cout << "Enter 0 to exit.\n";
        cout << "Enter 1 to append a node.\n";
        cout << "Enter 2 to delete a node.\n";
        cout << "Enter 3 to insert a node.\n";
        cout << "Enter 4 to prepend a node.\n";
        cout << "Enter 5 to print the list.\n";
        cout << "Enter 6 to clear the screen.\n";
        cin >> option;
        switch(option) {
            case 1: {
                int k,d;
                cout << "Enter key of data to be entered : ";
                cin >> k;
                cout << "Enter data to be entered : ";
                cin >> d;
                Node* n = new Node(k,d);
                s.appendNode(n);
                cout << '\n';
                break;
            }
            case 2:{
                int k;
                cout << "Enter key of node to be deleted : ";
                cin >> k;
                s.deleteNode(k);
                break;
            }
            case 3:{
                int k,d,key_target;
                cout << "Enter key of node to be inserted : ";
                cin >> k;
                cout << "Enter data to be inserted : ";
                cin >> d;
                cout << "Enter key of node after which current data must be inserted : ";
                cin >> key_target;
                Node* n = new Node(k,d);
                s.insertNode(key_target,n);
                cout << '\n';
                break;
            }
            case 4:{
                int k,d;
                cout << "Enter key of data to be entered : ";
                cin >> k;
                cout << "Enter data to be entered : ";
                cin >> d;
                Node* n = new Node(k,d);
                s.prependNode(n);
                cout << '\n';
                break;
            }
            case 5:
            s.printList();
            break;
            case 6:
            system("clear");
            break;
        }
    }while(option != 0);
    return 0;
}
