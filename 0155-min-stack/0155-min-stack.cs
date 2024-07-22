public class MinStack 
{
    Stack < int > Values, minimums;

    public MinStack() {
        Values = new Stack < int >();
        minimums = new Stack < int >();
    }
    
    public void Push(int val) {
        Values.Push(val);

        if (minimums.Count() != 0)
            minimums.Push(Math.Min(minimums.Peek(), val));
        else
            minimums.Push(val);
    }
    
    public void Pop() {
         Values.Pop();
         minimums.Pop();
    }
    
    public int Top() {
        return Values.Peek();
    }
    
    public int GetMin() {
        return minimums.Peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(val);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */