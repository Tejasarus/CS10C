#include "Heap.h"

Heap::Heap() {
    numItems = 0;
}

void Heap::enqueue(PrintJob* job) {
    //Insert PrintJob pointer at the next available position.
    if(numItems < MAX_HEAP_SIZE) {
        
        //Insert pointer in the case where the array is empty.
        if(numItems == 0) {
            arr[numItems] = job;
        }
        else {
            int x = numItems;
            
            //Consider the case where the new PrintJob could violate the heap property. Percolate the new pointer up.
            while(x > 0 && arr[(x-1)/2]->getPriority() < job->getPriority()) {
                arr[x] = arr[(x-1)/2];
                
                x = (x-1)/2;
            }
            
            arr[x] = job;
        }
        
        ++numItems;
    }
}

void Heap::dequeue() 
{
    /*Removes the node with highest priority from the heap.
  Follow the algorithm on priority-queue slides. */

//first we find the node with the highest priority
int h_priority_index = -1;
int max = -999;
for(int i = 0; i < MAX_HEAP_SIZE; ++i)
{
    if(arr[i]->getPriority() > max)
    {
        max = arr[i]->getPriority();
        h_priority_index = i;
    }
}
   
}

PrintJob* Heap::highest()
{
    return arr[0];
}

void Heap::print() {
    cout << "Priority: " << arr[0]->getPriority()
         << "Job Number: " << arr[0]->getJobNumber()
         << "Number of Pages: " << arr[0]->getPages() << endl;
}

void Heap::trickleDown(int num)
{
    
}
