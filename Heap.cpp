#include<iostream>
#include<vector>
using namespace std;
class heap{
    vector<int> v;
    bool minHeap;
    void heapify(int i)
    {
        int left=2*i;
        int right=2*i+1;
        int minIndex=i;
        if(left<v.size() && v[left]<v[i])
        {
            minIndex=left;
        }
        if(right<v.size() && v[right]<v[minIndex])
        {
            minIndex=right;
        }
        if(minIndex!=i)
        {
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }
    }
public:
    heap(bool type=true)
    {
        minHeap=true;
        v.push_back(-1);
    }
    void push(int data)
    {
        v.push_back(data);
        int index=v.size()-1;
        int parent=index/2;
        while(index>1 && v[index]<v[parent])
        {
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
    int top()
    {
        return v[1];
    }
    bool empty()
    {
        return v.size()==1;
    }
    void pop()                                  // POPS TOPMOST ELEMENT - ROOT
    {                                           //1. Bring last node to first and first to last
        int last=v.size()-1;                    //2. Remove last node
        swap(v[1],v[last]);                     //3. Call Heapify(index) function
        v.pop_back();
        heapify(1);
    }
};
int main()
{
    heap h;
    h.push(5);
    h.push(10);
    h.push(2);
    h.push(3);
    cout<<h.top()<<endl;
    h.pop();
    cout<<h.top()<<endl;
}
