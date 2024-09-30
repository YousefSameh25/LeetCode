class Node
{
public:
    int val;
    Node* next;
    Node(int x): val(x) {
        next = nullptr;
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

        int idx = Length - Len;
        Node *st = Head;
        while(idx--)
            st = st -> next;

        while(st != nullptr) {
            st -> val += val;
            st = st -> next;
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