#include <iostream>
#include<ctime>
#include<stdio.h>

using namespace std;
#define NMAX 100
template<typename T> class Queue {
    private:
        T queueArray[NMAX];
        int head, tail;
    public:
        void enqueue(T x) {
            if (tail >= NMAX) {
                fprintf(stderr, "Error 101 - The queue is full!\n");
                return;
            }
            queueArray[tail] = x;
            tail++;
        }

        T dequeue() {
            if (isEmpty()) {
                fprintf(stderr, "Error 102 - The queue is empty!\n");
                T x;
                return x;
            }
            T x = queueArray[head];
            head++;
            return x;
        }
                T peek() {
            if (isEmpty()) {
                fprintf(stderr, "Error 103 - The queue is empty!\n");
                T x;
                return x;
            }
            return queueArray[head];
        }

        int isEmpty() {
            return (head == tail);
        }


    Queue() {
        head = tail = 0; // the queue is empty in the beginning
    }
};


class Message{
private:
    tm date;
    char sender;
    char recipient;
    char content[256];
public:
    Message(char sender,char recipient,char content[256],tm date){
        this->sender=sender;
        this->recipient=recipient;
        content=new char[256];
        this->date=date;
    }
};

class MessageSender{
private:
    Message a;
    Queue<Message> messageSend;
public:
    MessageSender(){}
    void sendMessage(Message a){
        messageSend.enqueue(a);
    }
};

class MessageReciver{
private:
    MessageSender recive;
public:
    MessageReciver(){}
    void reciveMessage(){
        cout<<recive.messageSend.dequeue()<<endl;
    }
};


void displayDate(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   cout << "Time: "<< 1 + ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec << endl;
}
int main(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    tm date;
    Message a('a','b',"lunch?",date);
    MessageSender<Message>a;

}