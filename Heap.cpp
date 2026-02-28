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

    void heapify(){
        for(int i=size/2 -1;i>=0;i--){
            heapify_down(i);
        }
    }

    public:
    MinHeap(){
        array=new int[capacity]{};
    }

    MinHeap(const vector<int>&v){
        assert((int)v.size()<=capacity);
        array=new int[capacity]{};
        size=v.size();
        for(int i=0;i<(int)v.size();i++){
            array[i]=v[i];
        }
        heapify();
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
    int top(){
        assert(!isEmpty());
        return array[0];
    }
    bool isEmpty(){
        return size==0;
    }
    void pop(){
        assert(!isEmpty());
        array[0]=array[--size];
        heapify_down(0);
    }
    void heap_sort(int *p,int n){
        if(n<=1) return;
        int * old_arr=array;
        int old_size=size;
        size=n;
        array=p;
        heapify();
        while(size--){
            swap(array[0],array[size]);
            heapify_down(0);
        }
        for(int i=0;i<n/2;i++){
            swap(array[i],array[n-i-1]);
        }
        size=old_size;
        array=old_arr;
    }
    

};



void create_heap_nlogn(){
        MinHeap heap;
        vector<int> nums={5,3,8,4,1};
        for(int num:nums){
            heap.push(num);
        }
        while(!heap.isEmpty()){
            cout<<heap.top()<<" ";
            heap.pop();
        }
    }
void create_heap_n(){
        vector<int> nums={5,3,8,4,1};
        MinHeap heap(nums);
        while(!heap.isEmpty()){
            cout<<heap.top()<<" ";
            heap.pop();
        }
    }    
int main(){
    create_heap_nlogn();
    cout<<endl;
    create_heap_n();

}