class Node
{
public:
    int value;
    Node* next;
    Node* prev;
    Node(int val)
    {
        value = val;
        next = nullptr;
        prev = nullptr;
    }
};


class MyCircularDeque {
private:
    Node* Head;
    Node* Tail;
    int Length;
    int Capacity;
public:
    MyCircularDeque(int k) {
        Length = 0;
        Capacity = k;
        Head = nullptr;
        Tail = nullptr;
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;

        Node *node = new Node(value);
        if (isEmpty())
        {
            Head = node;
            Tail = node;
            Length++;
            return true;
        }
        node -> next = Head;
        Head -> prev = node;
        Head = node;
        Length++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        Node *node = new Node(value);
        if (isEmpty())
        {
            Head = node;
            Tail = node;
            Length++;
            return true;
        }
        Tail -> next = node;
        node -> prev = Tail;
        Tail = node;
        Length++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        Head = Head -> next;
        Length--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        Tail = Tail -> prev;
        Length--;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return -1;
        return Head -> value;
    }
    
    int getRear() {
        if (isEmpty())
            return -1;
        return Tail -> value;
    }
    
    bool isEmpty() {
        return Length == 0;
    }
    
    bool isFull() {
        return Capacity == Length;
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