#include <iostream>

using namespace std;

template<class T>
class node {
public:
    T data;
    node *next;

    explicit node(T x) {
        data = x;
        next = nullptr;
    }
};

template<class T>
class dNode {
public:
    T data;
    dNode *next;
    dNode *prev;

    explicit dNode(T x) {
        data = x;
        next = prev = nullptr;
    }
};

template<class T>
class linkedList {
private:
    node<T> *head;
    node<T> *tail;
    int size = 0;
public:
    linkedList() {
        head = tail = nullptr;
    }

    void insert(T x, int i) {
        auto *newNode = new node<T>(x);

        if (size == 0) {
            newNode->next = nullptr;
            tail = newNode;
            head = newNode;
        } else if (i == 0) {
            newNode->next = head;
            head = newNode;
        } else if (i == size) {
            tail->next = newNode;
            tail = newNode;
        } else {
            node<T> *current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void printList(int i) {
        node<T> *temp = head;
        int num = 0;
        while (num < i) {
            cout << temp->data << " ";
            temp = temp->next;
            num++;
        }
        cout << temp->data << endl;
    }
};

template<class T>
class linkInversion {
private:
    node<T> *head;
    node<T> *tail;
    node<T> *p;
    node<T> *q;
    int size = 0;
    int index;
public:
    linkInversion() {
        head = tail = p = q = nullptr;
        index = 0;
    }

    void insert(T x, int i) {
        auto *newNode = new node<T>(x);

        if (size == 0) {
            newNode->next = nullptr;
            tail = q = p = head = newNode;
        } else if (i == 0) {
            newNode->next = head;
            head = newNode;
        } else if (i == size) {
            tail->next = newNode;
            tail = newNode;
        } else {
            node<T> *current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void printList(int i) {
        node<T> *temp;
        cout << q->data << " ";

        while (index != i) {

            if (index < i) {
                temp = q;
                q = q->next;
                temp->next = p;
                p = temp;
                index++;
            } else {

                temp = p;
                p = p->next;
                temp->next = q;
                q = temp;
                index--;
            }
            cout << q->data << " ";
        }
        cout << endl;
    }
};

template<class T>
class doubleList {
private:
    dNode<T> *head;
    dNode<T> *tail;
    int size = 0;
public:
    doubleList() {
        head = tail = nullptr;
    }

    void insert(T x, int i) {
        auto *newNode = new dNode<T>(x);

        if (size == 0) {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            tail = newNode;
            head = newNode;
        } else if (i == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (i == size) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            dNode<T> *current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }

        size++;
    }

    void printList(int i) {
        if (i < size / 2) {
            dNode<T> *temp = head;
            int num = 0;
            while (num < i) {
                cout << temp->data << " ";
                temp = temp->next;
                num++;
            }
            cout << temp->data << endl;
        } else {
            dNode<T> *temp = tail;
            int num = size;
            while (num > i) {
                cout << temp->data << " ";
                temp = temp->prev;
                num--;
            }
            cout << endl;
        }
    }
};

template<class T>
class circularList {
private:
    node<T> *head;
    int size = 0;
public:
    circularList() {
        head = nullptr;
    }

    void insert(T x, int i) {
        auto *newNode = new node<T>(x);

        if (size == 0) {
            head = newNode;
            newNode->next = head;

        } else if (i == 0) {
            node<T> *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
        } else if (i == size) {
            node<T> *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        } else {
            node<T> *current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }

    void printList(int i) {
        node<T> *temp = head;
        int num = 0;
        while (num < i) {
            cout << temp->data << " ";
            temp = temp->next;
            num++;
        }
        cout << temp->data << endl;
    }
};

int main() {
    auto *singleList = new linkedList<int>();
    auto *invertedList = new linkInversion<int>();
    auto *dubList = new doubleList<int>();
    auto *circleList = new circularList<int>();
    int list[5] = {123, 234, 345, 456, 567};
    int order[5] = {4, 1, 0, 3, 2};

    for (int i = 0; i < 5; i++) {
        singleList->insert(list[i], i);
        invertedList->insert(list[i], i);
        dubList->insert(list[i], i);
        circleList->insert(list[i], i);
    }

    cout << "Singly linked list traversal" << endl << "List: ";
    for (int i: list) {
        cout << i << " ";
    }
    cout << endl << "Order: ";
    for (int i: order) {
        cout << i << " ";
    }
    cout << endl << "Output: " << endl;
    for (int i: order) {
        cout << "\t";
        singleList->printList(i);
    }

    cout << endl << "Link inversion list traversal" << endl << "List: ";
    for (int i: list) {
        cout << i << " ";
    }
    cout << endl << "Order: ";
    for (int i: order) {
        cout << i << " ";
    }
    cout << endl << "Output: " << endl;
    for (int i: order) {
        cout << "\t";
        invertedList->printList(i);
    }

    cout << endl << "Doubly linked list traversal" << endl << "List: ";
    for (int i: list) {
        cout << i << " ";
    }
    cout << endl << "Order: ";
    for (int i: order) {
        cout << i << " ";
    }
    cout << endl << "Output: " << endl;
    for (int i: order) {
        cout << "\t";
        dubList->printList(i);
    }

    cout << endl << "Circular linked list traversal" << endl << "List: ";
    for (int i: list) {
        cout << i << " ";
    }
    cout << endl << "Order: ";
    for (int i: order) {
        cout << i << " ";
    }
    cout << endl << "Output: " << endl;
    for (int i: order) {
        cout << "\t";
        circleList->printList(i);
    }

    return 0;
}
