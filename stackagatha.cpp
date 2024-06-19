#include <iostream>
#include <string>
using namespace std;

// Array-based stack
int maksimalArray = 6;
string arrayKtk[6];
int arrayNMR[6];
string arrayEmail[6];
int top = 0;

bool apakahPenuh() {
    return top == maksimalArray;
}

bool apakahKosong() {
    return top == 0;
}

void tambahkanKtk(string data, int nomor, string email) {
    if (apakahPenuh()) {
        cout << "Data penuh" << endl;
    } else {
        arrayKtk[top] = data;
        arrayNMR[top] = nomor;
        arrayEmail[top] = email;
        top++;
    }
}

void hapusKtk() {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        top--;
        arrayKtk[top] = "";
        arrayNMR[top] = 0;
        arrayEmail[top] = "";
    }
}

void tampilkanDataKtk() {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else {
        cout << "Data stack array: " << endl;
        for (int i = top - 1; i >= 0; i--) {
            if (arrayKtk[i] != "") {
                cout << "Nama Kontak: " << arrayKtk[i] << endl;
                cout << "Nomor: " << arrayNMR[i] << endl;
                cout << "Email: " << arrayEmail[i] << endl;
                cout << endl;
            }
        }
        cout << "\n" << endl;
    }
}

void intipDataKtk(int posisi) {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
    } else {
        int index = top - posisi;
        cout << "Nama Kontak: " << arrayKtk[index] << endl;
        cout << "Nomor: " << arrayNMR[index] << endl;
        cout << "Email: " << arrayEmail[index] << endl;
    }
}

void gantiKtk(string data, int nomor, string email, int posisi) {
    if (apakahKosong()) {
        cout << "Data kosong!!" << endl;
    } else if (posisi > top || posisi <= 0) {
        cout << "Posisi tidak valid!" << endl;
    } else {
        int index = top - posisi;
        arrayKtk[index] = data;
        arrayNMR[index] = nomor;
        arrayEmail[index] = email;
    }
}

int countArray() {
    return top;
}

void hapusDataKtk() {
    for (int i = 0; i < top; i++) {
        arrayKtk[i] = "";
        arrayNMR[i] = 0;
        arrayEmail[i] = "";
    }
    top = 0;
}

// Linked List-based stack
struct DataKontak {
    string namaKontak;
    int kontak;
    string email;

    DataKontak* prev;
    DataKontak* next;
};

DataKontak* head = NULL;
DataKontak* tail = NULL;
DataKontak* cur;
DataKontak* newNode;
DataKontak* del;
int maksimalLinkedList = 5;

bool isFullKontak() {
    int count = 0;
    cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count == maksimalLinkedList;
}

bool isEmptyKontak() {
    return head == NULL;
}

void createKontak(string namaKontak, int kontak, string email) {
    head = new DataKontak();
    head->namaKontak = namaKontak;
    head->kontak = kontak;
    head->email = email;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

void pushKontak(string namaKontak, int kontak, string email) {
    if (isFullKontak()) {
        cout << "Data penuh" << endl;
    } else {
        if (isEmptyKontak()) {
            createKontak(namaKontak, kontak, email);
        } else {
            newNode = new DataKontak();
            newNode->namaKontak = namaKontak;
            newNode->kontak = kontak;
            newNode->email = email;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }
}

void popKontak() {
    if (isEmptyKontak()) {
        cout << "Data kosong!!" << endl;
    } else {
        del = tail;
        if (tail->prev != NULL) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete del;
    }
}

void displayKontak() {
    if (isEmptyKontak()) {
        cout << "Data Kontak kosong" << endl;
    } else {
        cout << "\n\nData Kontak : " << endl;
        cur = tail;
        while (cur != NULL) {
            cout << "Nama Kontak: " << cur->namaKontak << endl;
            cout << "Nomor: " << cur->kontak << endl;
            cout << "Email: " << cur->email << endl;
            cout << endl;
            cur = cur->prev;
        }
    }
}

void peekKontak(int posisi) {
    if (isEmptyKontak()) {
        cout << "Data Kontak kosong" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cout << "Data Kontak Posisi ke-" << posisi << " : " << cur->namaKontak << " - Nomor: " << cur->kontak << " - Email: " << cur->email << endl;
    }
}

void changeKontak(string namaKontak, int kontak, string email, int posisi) {
    if (isEmptyKontak()) {
        cout << "Data Kontak kosong" << endl;
    } else {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi) {
            cur = cur->prev;
            nomor++;
        }
        cur->namaKontak = namaKontak;
        cur->kontak = kontak;
        cur->email = email;
    }
}

void destroyKontak() {
    cur = head;
    while (cur != NULL) {
        del = cur;
        head = head->next;
        delete del;
        cur = cur->next;
    }
    head = tail = NULL;
}

int countKontak() {
    int count = 0;
    cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

int main() {
    // Testing array-based stack
    tambahkanKtk("Alice Smith", 12345, "alice@gmail.com");
    tambahkanKtk("Bob Johnson", 67890, "bob@gmail.com");
    tambahkanKtk("Carol White", 23456, "carol@gmail.com");
    tambahkanKtk("David Brown", 34567, "david@gmail.com");
    tambahkanKtk("Eve Black", 45678, "eve@gmail.com");
    tampilkanDataKtk();

    tambahkanKtk("Frank Green", 56789, "frank@gmail.com");
    tampilkanDataKtk();

    hapusKtk();
    tampilkanDataKtk();

    cout << "Apakah data penuh? : " << (apakahPenuh() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (apakahKosong() ? "Ya" : "Tidak") << endl;

    intipDataKtk(2);

    cout << "Banyak data: " << countArray() << endl;

    gantiKtk("Grace Blue", 89012, "grace@gmail.com", 3);
    tampilkanDataKtk();

    hapusDataKtk();

    cout << "Apakah data penuh? : " << (apakahPenuh() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (apakahKosong() ? "Ya" : "Tidak") << endl;

    // Testing linked list-based stack
    pushKontak("Alice Smith", 12345, "alice@gmail.com");
    pushKontak("Bob Johnson", 67890, "bob@gmail.com");
    pushKontak("Carol White", 23456, "carol@gmail.com");
    pushKontak("David Brown", 34567, "david@gmail.com");
    pushKontak("Eve Black", 45678, "eve@gmail.com");
    displayKontak();

    pushKontak("Frank Green", 56789, "frank@gmail.com");
    displayKontak();

    popKontak();
    displayKontak();

    cout << "Apakah data penuh? : " << (isFullKontak() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (isEmptyKontak() ? "Ya" : "Tidak") << endl;

    peekKontak(2);

    cout << "Banyak data: " << countKontak() << endl;

    changeKontak("Grace Blue", 89012, "grace@gmail.com", 3);
    displayKontak();

    destroyKontak();

    cout << "Apakah data penuh? : " << (isFullKontak() ? "Ya" : "Tidak") << endl;
    cout << "Apakah data kosong? : " << (isEmptyKontak() ? "Ya" : "Tidak") << endl;

    return 0;
}
