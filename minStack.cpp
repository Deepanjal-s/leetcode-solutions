#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    class Node{
    public:
        int  value;
        int minValue;
        Node* next;

        Node(int val, int minVal){
            value = val;
            minValue = minVal;
            next = nullptr;
        }
    };

    Node* head;

    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        int minMin = (head == nullptr) ? val : min(val,head->minValue);
        Node* newNode = new Node(val,minMin);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        Node* temp = head;
        head = head->next;
        delete temp;//error so replaced head with temp
    }
    
    int top() {
        return head->value;
    }
    
    int getMin() {
        return head->minValue;
    }

};

int main(){

// Usage
MinStack* obj = new MinStack();
obj->push(5);   // Node: value=5,  minValue=5
obj->push(3);   // Node: value=3,  minValue=3
obj->push(7);   // Node: value=7,  minValue=3  <-- min is still 3
obj->push(2);   // Node: value=2,  minValue=2

cout << obj->getMin();  // 2
obj->pop();
cout << obj->getMin();  // 3  <-- automatically restored!

}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->head();
 * int param_4 = obj->getMin();
 */