#include <iostream>
using namespace std;

const int maksimalAntrianArray = 5;
int front = 0, back = 0, count = 0;

struct Kontak {
    string nama, email;
    int nomor;
};

Kontak antrianKontak[maksimalAntrianArray];

bool isFullArray() {
    return count == maksimalAntrianArray;
}

bool isEmptyArray() {
    return count == 0;
}

void enqueueArray(string nama, int nomor, string email) {
    if (isFullArray()) {
        cout << "Antrian penuh!!" << endl;
    } else {
        antrianKontak[back].nama = nama;
        antrianKontak[back].nomor = nomor;
        antrianKontak[back].email = email;
        back = (back + 1) % maksimalAntrianArray;
        count++;
    }
}

void dequeueArray() {
    if (isEmptyArray()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        front = (front + 1) % maksimalAntrianArray;
        count--;
    }
}

int countArray() {
    return count;
}

void destroyArray() {
    front = back = count = 0;
}

void viewArray() {
    cout << "Jumlah data antrian: " << countArray() << " data." << endl;
    cout << "Data Antrian Kontak: " << endl;
    if (isEmptyArray()) {
        cout << "Antrian kosong!!" << endl;
    } else {
        int j = front;
        for (int i = 0; i < count; i++) {
            cout << (i + 1) << ". Nama: " << antrianKontak[j].nama 
                 << ", Nomor: " << antrianKontak[j].nomor 
                 << ", Email: " << antrianKontak[j].email << endl;
            j = (j + 1) % maksimalAntrianArray;
        }
    }
    cout << "\n" << endl;
}

struct Node {
    string nama;
    int nomor;
    string email;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void enqueueLinkedList(string nama, int nomor, string email) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nomor = nomor;
    newNode->email = email;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void dequeueLinkedList() {
    if (head == NULL) {
        cout << "Antrian kosong!!" << endl;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) {
            tail = NULL;
        }
    }
}

int countLinkedList() {
    int count = 0;
    Node* cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void clearLinkedList() {
    Node* cur = head;
    while (cur != NULL) {
        Node* del = cur;
        cur = cur->next;
        delete del;
    }
    head = tail = NULL;
}

void displayLinkedList() {
    cout << "Data Antrian Kontak: " << endl;
    if (head == NULL) {
        cout << "Antrian kosong!!" << endl;
    } else {
        Node* cur = head;
        int pos = 1;
        while (cur != NULL) {
            cout << pos << ". Nama: " << cur->nama 
                 << ", Nomor: " << cur->nomor 
                 << ", Email: " << cur->email << endl;
            cur = cur->next;
            pos++;
        }
    }
    cout << "\n" << endl;
}

int main() {
    
    cout << "Array-Based Queue Test:" << endl;
    enqueueArray("Alice Smith", 12345, "alice@gmail.com");
    enqueueArray("Bob Johnson", 67890, "bob@gmail.com");
    enqueueArray("Carol White", 23456, "carol@gmail.com");
    enqueueArray("David Brown", 34567, "david@gmail.com");
    enqueueArray("Eve Black", 45678, "eve@gmail.com");
    viewArray();

    enqueueArray("Frank Green", 56789, "frank@gmail.com");
    viewArray();

    dequeueArray();
    viewArray();

    destroyArray();
    viewArray();

    cout << "Banyak data (Array): " << countArray() << endl;

    cout << "Linked List-Based Queue Test:" << endl;
    enqueueLinkedList("Alice Smith", 12345, "alice@gmail.com");
    enqueueLinkedList("Bob Johnson", 67890, "bob@gmail.com");
    enqueueLinkedList("Carol White", 23456, "carol@gmail.com");
    enqueueLinkedList("David Brown", 34567, "david@gmail.com");
    enqueueLinkedList("Eve Black", 45678, "eve@gmail.com");
    displayLinkedList();

    enqueueLinkedList("Frank Green", 56789, "frank@gmail.com");
    displayLinkedList();

    dequeueLinkedList();
    displayLinkedList();

    clearLinkedList();
    displayLinkedList();

    cout << "Banyak data (Linked List): " << countLinkedList() << endl;

    return 0;
}
