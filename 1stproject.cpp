#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
template<class t>
class Arr
{
private:
    t *arr;
    int size;
    int length;
public:
    Arr(int size)
    {
        this-> size=size;
        arr=new t [size];
        length=0;
    }
    bool isEmpty()
    {
        return (length==0);
    }
    bool isFull()
    {
        return (length==size);
    }
    void append(t value)
    {
         if (isFull())
        {
            cout<<"it's full"<<endl;
            return;
        }
        else
        arr [length++]=value;
    }
    void insert (int index,t value)
    {
        if (isFull())
        {
            cout<<"it's full"<<endl;
            return;
        }
        else if(index<0||index>=length)
        {
            cout<<"wrong index";
            return;
        }
        else
        {
            for (int i=length;i>index;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[index]=value;
        length++;
        }
    }
    void print()
    {
        if(isEmpty())
            return;
        for (int i=0;i<length;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    void printreverse()
    {
        if(isEmpty())
           {
              cout<<"it's empty"<<endl;
            return;
           }
        for (int i=length-1;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
    void reverse()
    {
        if(isEmpty())
            return;
        int start =0;
        int end=length-1;
        while(start<end)
        {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
    void reverse(int start,int end)
    {
        if(isEmpty())
            return;
        while(start<end)
        {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
    void rotatearray(int position,bool toleft=true)
    {
        if(isEmpty())
            return;
   else if(position<0||position>=length)
        {
            cout<<"wrong position";
            return;
        }
   else
    {   if(toleft)
       {
        reverse();
        reverse(0,length-position-1);
        reverse(length-position,length-1);
       }
       else
       {
        reverse();
        reverse(0,position-1);
        reverse(position,length-1);
       }
    }
    }
    void findduplicates()
    {
         if(isEmpty())
            return;
            sort (arr,arr+length);
         for(int i=1;i<length;i++)
         {
             if(arr[i]==arr[i-1])
                cout <<arr[i]<<endl;
         }
    }
    void mergearrays(const t *arr1 ,int size1,const t *arr2 ,int size2 ,t *mergearr )
    {
        int index=0;
        for (int i=0;i<size1;i++)
        {
            mergearr[index++]=arr1[i];
        }
          for (int i=0;i<size2;i++)
        {
            mergearr[index++]=arr2[i];
        }

    }
    void resizearr(int newsize)
    {   if(newsize<=0)
    { cout<<"wrong size"<<endl;
    return;
    }
        t *newarr= new t [newsize];
        int csize= min( newsize,length);
        for(int i=0;i<csize;i++)
        {
          newarr[i]=i+1;
        }
        delete[] arr;
        arr=newarr;
        size=newsize;
        length=csize;
    }
} ;
int main()
 {
    Arr <int> myArray(10);
    myArray.append(1);
    myArray.append(2);
    myArray.append(3);
    myArray.append(4);
    myArray.append(5);

    cout << "Array after append:" <<endl;
    myArray.print();
    myArray.insert(2, 99);
    cout << "Array contents after inserting 99 at index 2:" <<endl;
    myArray.print();
    cout << "Array contents in reverse:" <<endl;
    myArray.printreverse();
    myArray.reverse();
    std::cout << "Array contents after reverse:" <<endl;
    myArray.print();
    myArray.rotatearray(2, true);
    std::cout << "Array contents after rotating left by 2 positions:" << endl;
    myArray.print();
    Arr<int> myArrayWithDuplicates(10);
    myArrayWithDuplicates.append(1);
    myArrayWithDuplicates.append(2);
    myArrayWithDuplicates.append(2);
    myArrayWithDuplicates.append(3);
    myArrayWithDuplicates.append(3);
    myArrayWithDuplicates.append(3);

    cout << "Finding duplicates in array with duplicates:" <<endl;
    myArrayWithDuplicates.findduplicates();

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};
    int mergearr[6];
    myArray.mergearrays(arr1, 3, arr2, 3, mergearr);
    cout << "Merged array contents:" <<endl;
    for (int i = 0; i < 6; i++) {
        cout << mergearr[i] <<endl;
    }

    cout << "Array after resizing to 4:" << endl;
    myArray.resizearr(4);
    myArray.print();
    return 0;
}
