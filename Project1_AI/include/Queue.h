#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstring>

using namespace std;

class Queue {
private:
    int front, rear, numItems;
    string arr[31];
public:

    Queue()
    {front = numItems = 0; rear = -1;
      for(int i=0;i<31;i++)
        arr[i]="";
     }
    void enqueue(string);
    string dequeue();
    string get_front();
    string get_rear();
    bool isEmpty() {if(numItems==0) return true;
                     else return false;}
    bool isFull()  {if(numItems==31) return true;
                     else return false;}

};

void Queue::enqueue(string val) {

    if(!isFull())
    {rear = (rear+1) % 10;
     arr[rear] = val;
     numItems++;
    }
}

string Queue::dequeue() {

    if(!isEmpty())
    { string v = arr[front];
    front = (front+1) % 10; //wrap the index around
    numItems--;
    return v;
    }
}

string Queue::get_front()
{
    return arr[front];
}
string Queue::get_rear()
{
    return arr[rear];
}

#endif // QUEUE_H
