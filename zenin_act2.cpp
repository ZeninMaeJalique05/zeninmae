#include <iostream>


using namespace std;


// Part 1: Creating Structure (Node)

struct Node {

    string songName;

    Node* link;

};


// Part 2: Creating Node

Node* createNode(string data) {

    Node* newNode = new Node();

    newNode->songName = data;

    newNode->link = nullptr;

    return newNode;

}


// Part 3: Traverse Operations

void traverse(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {

        cout << temp->songName << endl;

        temp = temp->link;

    }

    cout << endl;

}


// Display only OPM songs

void displayOPMSongs(Node* head) {

    cout << "OPM Songs in Playlist:\n";

    Node* temp = head;

    while (temp != nullptr) {

        if (temp->songName == "Sila - SUD" ||

            temp->songName == "Gayuma - Abra" ||

            temp->songName == "Karera - BINI") {

            cout << temp->songName << endl;

        }

        temp = temp->link;

    }

    cout << endl;

}


// Part 4: Insert Operations

void insertAtEnd(Node*& head, string songName) {

    Node* newNode = createNode(songName);

    if (head == nullptr) {

        head = newNode;

        return;

    }

    Node* temp = head;

    while (temp->link != nullptr) {

        temp = temp->link;

    }

    temp->link = newNode;

}


void insertAtBeginning(Node*& head, string songName) {

    Node* newNode = createNode(songName);

    newNode->link = head;

    head = newNode;

}


void insertAfter(Node* prevNode, string songName) {

    if (prevNode == nullptr) {

        cout << "Previous node cannot be null." << endl;

        return;

    }

    Node* newNode = createNode(songName);

    newNode->link = prevNode->link;

    prevNode->link = newNode;

}


void insertUnique(Node*& head, string songName) {

    Node* temp = head;

    while (temp != nullptr) {

        if (temp->songName == songName) {

            return; 

        }

        temp = temp->link;

    }

    insertAtEnd(head, songName);

}



// Part 5: Delete Operations


// Delete from the end

void deleteFromEnd(Node*& head) {

    if (head == nullptr) return;

    if (head->link == nullptr) {

        delete head;

        head = nullptr;

        return;

    }

    Node* temp = head;

    while (temp->link->link != nullptr) {

        temp = temp->link;

    }

    delete temp->link;

    temp->link = nullptr;

}


// Delete from the beginning

void deleteFromBeginning(Node*& head) {

    if (head == nullptr) return;

    Node* temp = head;

    head = head->link;

    delete temp;

}


// Delete a specific node

void deleteFromGivenNode(Node*& head, string givenNode) {

    if (head == nullptr) {

        cout << "The linked list is empty.\n";

        return;

    }


    if (head->songName == givenNode) {

        deleteFromBeginning(head);

        cout << "The node \"" << givenNode << "\" has been deleted.\n";

        return;

    }


    Node* temp = head;

    Node* prev = nullptr;


    while (temp != nullptr && temp->songName != givenNode) {

        prev = temp;

        temp = temp->link;

    }


    if (temp == nullptr) {

        cout << "No such node exists.\n";

        return;

    }


    prev->link = temp->link;

    delete temp;

    cout << "The node \"" << givenNode << "\" has been deleted.\n";

}



int main() {

    Node* head = nullptr;


    // Insert most played songs (No duplicates)

    insertUnique(head, "Gusto Ko Nang Bumitaw - Morissette");

    insertUnique(head, "Karera - BINI");

    insertUnique(head, "Glue Song - beabadoobee");


    // Insert favorite songs

    insertUnique(head, "Sila - SUD");

    insertUnique(head, "Gayuma - Abra");


    // Insert 3 OPM songs if they aren't already added

    insertUnique(head, "Sila - SUD"); // OPM

    insertUnique(head, "Gayuma - Abra"); // OPM

    insertUnique(head, "Karera - BINI"); // OPM


    // Display the full playlist

    cout << "Full Playlist:\n";

    traverse(head);


    // Display only OPM songs

    displayOPMSongs(head);


    // Delete operations

    deleteFromEnd(head);

    deleteFromBeginning(head);

    deleteFromGivenNode(head, "Karera - BINI");


    // Display updated playlist

    cout << "Updated Playlist:\n";

    traverse(head);


    return 0;

}