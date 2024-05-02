#include <iostream>
#include <conio.h>
#include <fstream> 
#include<bits/stdc++.h> 
using namespace std;
int main()
{   string search;
    string arr[50];
    int arr1[50];
    int length = sizeof(arr)/sizeof(arr[0]);
    struct contact 
          {
            string name;
            int no;
          };
          contact con;
    back: //to repeat the process using goto at line 42
      ofstream ob;
      ifstream ob1;
      ob.open("contacts.txt",ios::app); //app - append mode
      ob1.open("contacts.txt",ios::in);
    char name[20];
    int number;
 cout<<" -----Contact management -----\n";
   cout<<"1. Enter a contact\n 2. Show all contacts \n 3. Edit a contact \n 4. Exit\n";
    int choice;
    cin>>choice;
         switch(choice)
    {
        case 1 :
          cout<<"\n Enter name of the contact: ";
          cin>>name;
          cout<<"\n Enter contact number: ";
          cin>>number;
          con.name = name;
          con.no = number;
          ob<<con.name<<endl<<con.no<<endl;
          break;
        case 2 :
          while(!ob1.eof())
          {
            char ch;
            ob1.get(ch);
            cout<<ch;
          }
          break;
        case 3:
        int x,y;
        x = 0;
        y=0;
          for (int i = 0; !ob1.eof(); i ++)
          {
            string line;
            getline(ob1,line);
            if (i%2==0)
            {
              arr[x] = line;
              cout<<arr[i]<<endl;
              x+=1;
            }
            else 
            {
              arr1[y] = stoi(line);
              y+=1;
            }
          }
          cout<<"Enter the name of the contact to edit: ";
          cin>>search;
          int match;
          for (int i = 0 ; i<=(length-1); i++)
          {
            if (arr[i]==search)
            {
              match = i;
              cout << match;
          
            }
            else 
            {
              continue;
            }
          }
          break;
        case 4:
          return 0;
        default:
          cout<<"exiting\n";
          return 0;
    }
    cout<<arr[0]<<arr[1]<<arr1[0]<<arr1[1];
    goto back;
   }
