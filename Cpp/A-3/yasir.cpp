
#include<bits/stdc++.h>
using namespace std;
#define SIZE 10
class Complex
{
public:
  int real;
  int img;
  Complex()
  {
    real = img = 0;

  }
  Complex(int r, int i)
  {
    real = r;
    img = i;
  }
  Complex(const Complex &c)
  {
    real = c.real;
    img = c.img;
  }
  ~Complex()
  {

  }
  friend istream& operator>> (istream &cin, Complex &c);
  friend ostream& operator<<(ostream& cout, Complex c);
};

istream& operator>> (istream &cin, Complex &c)
{
  std::cout << "enter the real part of the complex number" << endl;
  cin >> c.real;
  std::cout << "enter the imaginary part of the complex number" << endl;
  cin >> c.img;
  return cin;
}
ostream& operator<<(ostream& cout, Complex c)
{
  cout << c.real << "+  " << c.img << "i";
  return cout;
}

//*************************************************************************************************

template<class T>// template declaration
class Stack// stack class
{
  //private section
  int top;
  int size;
  T *arr;
  public:// public section
    Stack()//default constructor
    {
      top=-1;
      size=0;
      arr=NULL;
    }
    Stack(int n){
      top=-1;
      size=n;
      arr=new T[n];
    }
    ~Stack()//destructor
    {
      
      cout<<"asdasda";
      if(arr!=NULL)
        delete(arr);
      cout<<"aaaa";
    }
    void push (T x)//pushing onto stack using try block
    {
      try
      {
        cout<<"size "<<size<<endl;
        cout<<"Top "<<top<<endl;
        if(top==size-1)
        {
          cout<<"stack is full\n";
          throw "can't push into the stack";
        }
        arr[++top]=x;
      }
      catch(const char *s)
      {
        cout<<s<<endl;
      }
    }
    void printStack()
    {
      int nTemp=top+1;
      cout<<"the stack elements are [from top to bottom]\n";
      while(nTemp--)
      {
        cout<<arr[nTemp]<<" ";
      }

    }
    T pop()// popping element using try catch block
    {
      try
      {
        if(top==-1)
        {
          cout<<"stack is empty\n";
          throw "can't pop from the stack";
        }
        return arr[top--];
      }
      catch(const char *s)
      {
        cout<<s<<endl;
      }
    }
    bool isEmpty()
    {
      return (top==-1);
    }
    bool isFull()
    {
      return (top==size);
    }
    T peek()
    {
      try
      {
        if(top==-1)
        {
          cout<<"stack is empty\n";
          throw "can't pop from the stack";
        }
        return arr[top];
      }
      catch(const char *s)
      {
        cout<<s<<endl;
      }
    }
    //int size()///returning size of stack
    //{
  //    return top+1;
  //  }
};
template<class T>
void tempStack()    //template function which can be invoked by any data type
{
  cout<<"Enter the size of stack : ";
  int sizeOfStack;
  cin>>sizeOfStack;
  Stack<T> stackObject(sizeOfStack);
  int choice;
  T input;
  while(1)
  {
    cout << "choose the options from below" << endl;
    cout << "1.push the element" << endl;
    cout << "2.pop the element" << endl;
    cout << "3.know the top element" << endl;
    cout << "4.know whether stack is full" << endl;
    cout << "5.know whether stack is empty" << endl;
    cout << "6.display the elemnets of the stack" << endl;
    cout << "7.exit";
    cout << endl;
    cout << "ENTER YOUR CHOICE";
    cin >> choice;
    switch(choice)
    {
      case 1: cout<<"enter the element you want to push\n";
          cin>>input;
          stackObject.push(input);
          break;
      case 2: cout<<"the top element popped from the stack is \n";
          cout<<stackObject.pop();
          cout<<endl;
          break;
      case 3: cout<<"the top of the stack is \n";
          cout<<stackObject.peek();
          cout<<endl;
          break;
      case 4: if(stackObject.isFull())
            cout<<"stack is full\n";
          else
            cout<<"stack is not full\n";
          break;
      case 5: if(stackObject.isEmpty())
            cout<<"stack is empty\n";
          else
            cout<<"stack is not empty\n";
          break;
      case 6: stackObject.printStack();
          cout<<endl;
          break;
      case 7: return ;
    }
  }
  return ;
}


//**********************************************************************************************************

int main()
{
  
  while(1)
  {
    cout<<"enter the data type of the stack\n";
    cout<<"1. int\n2.float\n3.character\n4.string\n5.complex\n6.exit\n\n";
    int Choice;
    cin>>Choice;
    switch(Choice)
    {
      case 1: tempStack<int>();
          break;
      case 2: tempStack<float>();
          break;
      case 3: tempStack<char>();
          break;
      case 4: tempStack<string>();
          break;
      case 5: tempStack<Complex>();
          break;
      case 6: exit(0);
          break;
      default:
          cout<<"Please enter correct option\n";
          break;
    }
  }

  return 0;
}