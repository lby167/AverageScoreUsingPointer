//Write a program that dynamically allocates an array large enough to hold a user-defined number of test scores. Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. Another function should be called that calculates the average score. The program should display the sorted list of scores and averages with appropriate headings. Use pointer notation rather than array notation whenever possible. Input Validation: Do not accept negative numbers for test score//
//Module 9 Programming//

#include<iostream>
#include<iomanip>
using namespace std;

//function prototypes
void bubbleSort(double[],int);
void swap(int &, int &);
void average(double [], int);


int main()
{
    double *scores=nullptr;//create a pointer can use to hold address of double
    
    int size;//array size integer for how many scores user input
    int count;
    //ask user to user defined array size
    cout<<"How many scores do you want to enter?: ";
    cin>>size;
    
    //dynamically allocate an array large enough to hold that many scores
    scores=new double[size];
    
    //get each score
    cout<<"Enter the scores : \n";
    for(count=0;count<size;count++)
    {
        cin>>*(scores+count);//user input of each iteration will be store in the pointer point to
        while(*(scores+count)<0){//while test the value which pointer point to is less than 0, warning user re-enter
            cout<<"Please enter non negative value for test score ";
            cin>>*(scores+count);
        }
    }
    
    
    //sort the array.
    bubbleSort(scores,size);
    
    //dispay the sorted array
    cout<<"The Sorted Scores : ";
    for(int i=0;i<size;i++)
        cout<<*(scores+i)<<" ";
    cout<<endl;
    
    //average the scores
    average(scores,size);
    
    
    //Free dynamically allocate memory
    delete [] scores;
    scores=nullptr; //make score a null pointer
    
    return 0;
    
    
}

//sort function
void bubbleSort(double scores[], int size)
{
    int maxElement;
    int index;
    
    for(maxElement = size-1; maxElement>0; maxElement--)
    {
        for(index=0;index<maxElement;index++)
        {
            if(*(scores+index)>*(scores+index+1))//if score[index]>score[index+1], then swap
            {
                swap(*(scores+index),*(scores+index+1));//call swap function
            }
        }
    }
}

//swap function for two values
void swap(double &a, double &b ) //swaps doubles a and b in memory
{
    int temp=a;
    a=b;
    b=temp;
}

//avergae function
void average(double scores[], int size)
{
    double average;//initial average as double
    double total=0;//initial total as double
    
    //use pointer instead of subscript of array to add each score from the array to total
    for(int i=0;i<size;i++)
    {
        total+=*(scores+i);

    }
    //calculate average score
    average=total/size;
    
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"The Average Score : "<<average<<endl;
}
