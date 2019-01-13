#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class siz;
//Class To enter the names of the players
class name{
    string first;
public:
    void get()
    {
        cin>>first;
    }
    friend void input(name,siz,name,name);
    friend void matrix(siz,name,int&,int&,int&);
    friend void checkresponse(name,siz);
};
class siz{
    int sizee;
public:
    void get()
    {
        cin>>sizee;
    }
    friend void matrix(siz,name,int&,int&,int&);
    friend void space(siz);
    friend void input(name,siz,name,name);
    friend void checksize(siz);
    friend void checkresponse(name,siz);
    friend int endgame(siz);
};
//Invalid move printer
void Invalid()
{
    cout<<"!!Invalid Entry!!";
    exit(0);
}
//TO check the size of the matrix is under range
void checksize(siz len)
{
    if(len.sizee<0 || len.sizee>9)
    {
      Invalid();
    }
}
void space(siz len)
{
    int i;
    for(i=0;i<len.sizee;i++)
    {
        if(i==0)
            cout<<"   ";
        cout<<char(i+49)<<"  ";
    }
    cout<<endl<<endl;
}
//Arrays to keep horizontal and vertical record
int arr[10][10],arr1[10][10];
//checking which player have scored
int arr2[10][10];
//checking the ressponse entered by player
void checkresponse(name three,siz len)
{
    if(three.first[0]=='q')
        exit(0);
    if(three.first[0]!=three.first[2])
    {
        if(three.first[1]!=three.first[3])
        {
            Invalid();
        }
    }
    else{
        if(three.first[1]==three.first[3])
        {
             Invalid();
        }
    }
    if(three.first[1]==three.first[3])
    {
        if(three.first[0]!=three.first[2]-1)
            Invalid();
    }
    else{
        if(three.first[1]!=three.first[3]-1)
            Invalid();
    }
    int x=three.first[0]-97,y=three.first[1]-49,z=three.first[2]-97,xy=three.first[3]-49;
    if(x<0||x>len.sizee-1)
    {
        Invalid();
    }
    if(z<0||z>len.sizee-1)
    {
        Invalid();
    }
    if(y<0||y>len.sizee-1)
    {
        Invalid();
    }
    if(xy<0||xy>len.sizee-1)
    {
        Invalid();
    }
}
//Print matrix on the screen
void matrix(siz len,name three,int &count,int &pone,int &ptwo)
{
    static int count1=0;
    int i,j;
    if(count1==0)
    {
    }
    else{
        if(three.first[0]==three.first[2])
        {
            int waste=0;
            arr[three.first[0]-97][three.first[1]-49]=1;
            if( arr1[three.first[0]-97][three.first[1]-49]==1 && arr1[three.first[0]-97][three.first[1]-48]==1&& arr[three.first[0]-96][three.first[1]-49]==1)
            {
                if(arr2[three.first[0]-97][three.first[1]-49]==0)
                {

                    if(count==1)
                    {
                        arr2[three.first[0]-97][three.first[1]-49]=1;
                        pone++;
                        waste=2;
                    }
                    else
                    {
                        arr2[three.first[0]-97][three.first[1]-49]=2;
                        ptwo++;
                        waste=1;
                    }
                }
            }
            if(arr1[three.first[0]-98][three.first[1]-49]==1 && arr1[three.first[0]-98][three.first[1]-48]==1&& arr[three.first[0]-98][three.first[1]-49]==1)
            {
                 if(arr2[three.first[0]-98][three.first[1]-49]==0)
                {
                    if(count==1)
                    {
                        arr2[three.first[0]-98][three.first[1]-49]=1;
                        pone++;
                        waste=2;
                    }
                    else
                    {
                        arr2[three.first[0]-98][three.first[1]-49]=2;
                        ptwo++;
                        waste=1;
                    }
                }
            }
            if(waste==1||waste==2)
                count=waste;
        }
        else
        {
            int waste=0;
            arr1[three.first[0]-97][three.first[1]-49]=1;
            if(arr1[three.first[0]-97][three.first[1]-48]==1&& arr[three.first[0]-97][three.first[1]-49]==1&& arr[three.first[0]-96][three.first[1]-49]==1)
            {
                if(arr2[three.first[0]-97][three.first[1]-49]==0)
                {

                    if(count==1)
                    {
                        arr2[three.first[0]-97][three.first[1]-49]=1;
                        pone++;
                        waste=2;
                    }
                    else
                    {
                        arr2[three.first[0]-97][three.first[1]-49]=2;
                        ptwo++;
                        waste=1;
                    }
                }
            }
            if(arr1[three.first[0]-97][three.first[1]-50]==1&& arr[three.first[0]-97][three.first[1]-50]==1&& arr[three.first[0]-96][three.first[1]-50]==1)
            {
                if(arr2[three.first[0]-97][three.first[1]-50]==0)
                {

                    if(count==1)
                    {
                        arr2[three.first[0]-97][three.first[1]-50]=1;
                        pone++;
                        waste=2;
                    }
                    else
                    {
                        arr2[three.first[0]-97][three.first[1]-50]=2;
                        ptwo++;
                        waste=1;
                    }
                }
            }
            if(waste==1||waste==2)
                count=waste;
        }
    }
    for(i=0;i<len.sizee;i++)
    {
        cout<<char(i+97)<<"  ";
        for(j=0;j<len.sizee;j++)
        {
            if(arr[i][j]==1)
                cout<<"+--";
            else
            cout<<"+  ";
        }
        cout<<endl;
        cout<<"   ";
        for(j=0;j<len.sizee;j++)
            {
                if(arr1[i][j]==1)
                {
                      if(arr2[i][j]==0)
                      cout<<"|  ";
                      else if(arr2[i][j]==1)
                        cout<<"|P1";
                      else
                        cout<<"|P2";
                }
                else
                    cout<<"   ";
            }
        cout<<endl;
    }
    count1++;
}
//Check the players turn
int turn(int &count)
{
    if(count==1)
    {
         count=2;
    }
    else
    {
        count=1;
    }
}
//Check if the game is completed or not
int endgame(siz len)
{
    int i,j,flag;
    for(i=0;i<len.sizee-1;i++)
    {
        for(j=0;j<len.sizee;j++)
        {
            if(arr1[i][j]!=1)
            {
                flag=0;
                break;
            }
            else
                flag=1;
        }
    }
    if(flag==1)
    {
        for(i=0;i<len.sizee;i++)
        {
            for(j=0;j<len.sizee-1;j++)
            {
                if(arr[i][j]!=1)
                {
                    flag=0;
                    break;
                }
                else
                    flag=1;
            }
        }
    }
    return flag;
}
void input(name three,siz len,name one,name two)
{
   int temp,flag;
   int pone=0,ptwo=0;
   three.first[0]='a';
   static int count=0;
   matrix(len,three,count,pone,ptwo);
   while(three.first[0]!='q')
   {
       turn(count);
       temp=count;
       if(count==1)
       cout<<"Player one turn: ";
       else
        cout<<"Player two turn: ";
       three.get();
       checkresponse(three,len);
       cout<<"\033[2J\033[1;H";
       space(len);
       matrix(len,three,count,pone,ptwo);
       flag=endgame(len);
       if(flag==1)
        break;
       if(temp!=count)
        cout<<"Player "<<temp<<" scored!"<<endl;
   }
    cout<<one.first<<" scored: "<<pone<<endl;
    cout<<two.first<<" scored: "<<ptwo;
}
int main()
{
    int i,j;
    cout<<"\033[2J\033[1;1H";
    cout<<"***************************************************************"<<endl<<endl;
    cout<<"*          Welcome to the game of plus and boxes              *"<<endl<<endl;
    cout<<"***************************************************************"<<endl;
    //Two objects to enter names of players
    name one,two;
    cout<<"Enter name of first player: ";
    one.get();
    cout<<"Enter name of second player: ";
    two.get();
    siz len;
    cout<<"Enter the size of matrix(<10): ";
    len.get();
    checksize(len);
    cout<<"\033[2J\033[1;1H";
    space(len);
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            arr[i][j]=0;
            arr1[i][j]=0;
            arr2[i][j]=0;
        }
    }
    name three;
    /*cout<<"Player one turn: ";
    three.get();
    checkresponse(three,len);
    system("cls");
    space(len);
    matrix(len,three);*/
    input(three,len,one,two);
}
