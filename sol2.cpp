using namespace std;
#include <bits/stdc++.h>
class MinHeap{
    private:
    int *array{};
    int capacity{1000};
    int size{0};
    int left(int node){
        int c=2*node+1;
        return c>=size? -1 : c;
    }
    int right(int node){
        int c=node*2+2;
        return c>=size? -1 : c;
    }
    int parent(int node){
        return node==0? -1 :(node-1)/2;
    }

    void heapify_up(int child_pos){
        int par_pos=parent(child_pos);
        if(par_pos==-1||array[par_pos]<=array[child_pos]) return;
        swap(array[par_pos],array[child_pos]);
        heapify_up(par_pos);
    }
    void heapify_down(int parent_pos){
        int child_pos=left(parent_pos);
        int right_child=right(parent_pos);
            if(child_pos==-1) return;
        if(right_child!=-1&&array[right_child]<array[child_pos]){
            child_pos=right_child;
        }
        if(array[parent_pos]>array[child_pos]){
             swap(array[parent_pos],array[child_pos]);
             heapify_down(child_pos);
        }
    }

    public:
    MinHeap(){
        array=new int[capacity]{};
    }
    ~MinHeap(){
        delete[] array;
        array=nullptr;
    }
    void push(int key){
        assert(size+1<=capacity);
        array[size]=key;
        heapify_up(size);
        size++;
    }
    bool isEmpty(){
        return size==0;
    }
    void pop(){
        assert(!isEmpty());
        array[0]=array[--size];
        heapify_down(0);
    }
    int getSize(){
        return size;
    }
    int top(){
        return array[0];
    }

};
class MedianFinder {
public:
    MinHeap minh;
    priority_queue<int> maxh;
    MedianFinder() {

        
    }
    
    void addNum(int num) {
        if (maxh.empty() || num <= maxh.top())
            maxh.push(num);
        else
            minh.push(num);
        if(maxh.size()>minh.getSize()+1){
            minh.push(maxh.top());
            maxh.pop();

          
        }
        if (minh.getSize() > maxh.size()) {
        maxh.push(minh.top());
        minh.pop();
        }
        
    }
    
    double findMedian() {
        if(maxh.size()==minh.getSize()){
            return (maxh.top()+minh.top())/2.0;
        }
        else{
            if(maxh.size()>minh.getSize()){
                return maxh.top();
            }
            else{
                return minh.top();
            }
            
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */