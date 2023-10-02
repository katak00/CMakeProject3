#include <iostream>

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void push_back(int value) {
        if (head == nullptr) {
            head = new Node(value);
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
        ++size;
    }

    void insert(int position, int value) {
        if (position >= 0 && position <= size) {
            if (position == 0) {
                Node* temp = new Node(value);
                temp->next = head;
                head = temp;
            }
            else {
                Node* current = head;
                for (int i = 0; i < position - 1; ++i) {
                    current = current->next;
                }
                Node* temp = new Node(value);
                temp->next = current->next;
                current->next = temp;
            }
            ++size;
        }
    }

    void erase(int position) {
        if (position >= 0 && position < size) {
            if (position == 0) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            else {
                Node* current = head;
                for (int i = 0; i < position - 1; ++i) {
                    current = current->next;
                }
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            --size;
        }
    }

    int getSize() const {
        return size;
    }

    int operator[](int index) const {
        if (index >= 0 && index < size) {
            Node* current = head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->value;
        }
        return 0; // Индекс выходит за границы списка, возвращаем значение по умолчанию
    }
};

int main() {
    LinkedList myList;

    for (int i = 0; i < 10; ++i) {
        int value;
        std::cin >> value;
        myList.push_back(value);
    }

    for (int i = 0; i < myList.getSize(); ++i) {
        std::cout << " " << myList[i];
    }
    std::cout << std::endl;

    std::cout << "Size: " << myList.getSize() << std::endl;

    myList.erase(2);
    myList.erase(4);
    myList.erase(6);

    std::cout << "Erase: ";
    for (int i = 0; i < myList.getSize(); ++i) {
        std::cout << " " << myList[i];
    }
    std::cout << std::endl;

    myList.insert(0, 10);

    std::cout << "Push 10: ";
    for (int i = 0; i < myList.getSize(); ++i) {
        std::cout << " " << myList[i];
    }
    std::cout << std::endl;

    myList.insert(3, 20);

    std::cout << "Push 20: ";
    for (int i = 0; i < myList.getSize(); ++i) {
        std::cout << " " << myList[i];
    }
    std::cout << std::endl;

    myList.push_back(30);

    std::cout << "Push 30: ";
    for (int i = 0; i < myList.getSize(); ++i) {
        std::cout << " " << myList[i];
    }
    std::cout << std::endl;

    return 0;
}