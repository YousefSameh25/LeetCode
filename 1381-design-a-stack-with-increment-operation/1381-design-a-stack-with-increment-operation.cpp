class Node
{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int x): val(x) {
        next = nullptr;
        prev = nullptr;
    }
};
class CustomStack {
private:
    int Length, Capacity;
    Node *Head, *Tail; 
public:
    CustomStack(int maxSize) {
        Capacity = maxSize;
        Head = nullptr;
        Tail = nullptr;
        Length = 0;
    }
    
    void push(int x) {
        if (Length == Capacity)
            return;
        if (Length == 0)
        {
            Head = new Node(x);
            Tail = Head;
        }
        else
        {
            Node *node = new Node(x);
            node -> next = Head;
            Head -> prev = node;
            Head = node;
        }
        Length++;
    }
    
    int pop() {
        if (Length == 0)
            return -1;
        int top = Head -> val;
        Head = Head -> next;
        Length--;
        if (Length == 0)
            Tail = nullptr;
        return top;
    }
    
    void increment(int k, int val) {
        int Len = min(k, Length);
        Node* st = Tail;
        while(Len-- and st != nullptr) {
            st -> val += val;
            st = st -> prev;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */