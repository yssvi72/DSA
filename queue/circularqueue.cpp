class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int num) {
        val = num;
        next = nullptr;
        prev = nullptr;
    }
};

class MyCircularDeque {
public:
    Node* head;
    Node* tail;
    int size;
    int max_len;

    MyCircularDeque(int k) {
        max_len = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = newNode;  
            newNode->prev = newNode;  
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }

        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = tail = newNode;
            newNode->next = newNode; 
            newNode->prev = newNode;  
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }

        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;

        if (size == 1) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            tail->next = head->next;
            head->next->prev = tail;
            head = head->next;
            delete temp;
        }

        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        if (size == 1) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            head->prev = tail->prev;
            tail->prev->next = head;
            tail = tail->prev;
            delete temp;
        }

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == max_len;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
