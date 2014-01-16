#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
class Heap
{
public:
	Heap();
	~Heap();

	void insert(int element);
	int deletemin();
	void print();
	int size() {return heap.size();}  
private:
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void upheap(int index);
	void downheap(int index);
private:
	std::vector<int> heap;
};
Heap::Heap() {} 
Heap::~Heap() {}
void Heap::insert(int element){
	heap.push_back(element);
	upheap(heap.size()-1);
}
int Heap::deletemin(){
	int min = heap.front();
	heap[0]=heap.back();
	heap.pop_back();
	downheap(0);
	return min;
}
void Heap::print(){
	int i;
	cout<<"the heap prints out :\n";
	for(i=0;i<heap.size();i++) {
		cout<<heap[i]<<' ';
	}
	cout<<endl;
    
}
int Heap::left(int parent){
	int i = 2*parent + 1;
	return (i<heap.size()) ? i : -1;  
}
int Heap::right(int parent){
	int i = 2*parent +2;
	return (i<heap.size()) ? i : -1;  
	
}
int Heap::parent(int child){
	if(child != 0) {return ((child-1)/2);}
	else return -1;
}
void Heap::upheap(int index)
{
	while((index>0) && (parent(index)>=0) && (heap[parent(index)]>heap[index]))
	{
		int tmp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = tmp;
        index = parent(index); //update index 
	}
}
void Heap::downheap(int index) 
{
	int child = left(index);
	if ( ( child > 0 ) && ( right(index) > 0 ) &&
         ( heap[child] > heap[right(index)] ) )
    {
        child = right(index);
    }    //child becomes the minimum of the 2 children 
    //Iterative implementation
    // while((index<heap.size()) && (heap[index]>heap[child])) 
    // {
    // 	int t = heap[child];
    // 	heap[child] = heap[index];
    // 	heap[index]=t;
    // 	index=child;
    // }
    //end of iterative version 
     if ( child > 0 )
    {    //swap //
        int tmp = heap[index];
        heap[index] = heap[child];
        heap[child] = tmp;
        //end swap//
        downheap(child); //recurse
    }
}
int main(int argc, char **argv){
	Heap* myheap = new Heap();
	myheap->insert(700);
    myheap->print();
    myheap->insert(500);
    myheap->print();
    myheap->insert(100);
    myheap->print();
    myheap->insert(800);
    myheap->print();
    myheap->insert(200);
    myheap->print();
    myheap->insert(400);
    myheap->print();
    myheap->insert(900);
    myheap->print();
    myheap->insert(1000);
    myheap->print();
    myheap->insert(300);
    myheap->print();
    myheap->insert(600);
    myheap->print();

    // Get priority element from the heap
    int heapSize = myheap->size();
    for ( int i = 0; i < heapSize; i++ )
        cout << "Get min element = " << myheap->deletemin() << endl;

    // Cleanup
    delete myheap;
}