#include <vector>
class Heap
{
public:
	Heap();
	~Heap();

	void insert(int element);
	int deletemin();
	void print();
	int size();
private:
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void upheap(int index);
	void downheap(int index);
private:
	std::vector<int> heap;
};