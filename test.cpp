#include <iostream>
#include <conio.h>
#include <fstream>
#include <bits/stdc++.h>
struct contact
{
    int number;
    std::string name;
};
int main()
{
    contact con;
    std::string names[100]; // array to store names
    int numbers[100];       // array to store numbers
    int x = 0;
    int y = 0;
    std::string c_name;
    int c_number;
    std::ifstream infile;
    std::ofstream outfile;
    infile.open("contacts.txt", std::ios::in);
    outfile.open("contacts.txt", std::ios::app);
 back:   for (int i = 0; !infile.eof(); i++)
    {
        std::string line;
        getline(infile, line);
        if (i % 2 == 0)
        {
            names[x] = line;
            x += 1;
        }
        else
        {
            numbers[y] = stoi(line);
            y += 1;
        }
    }
    infile.close();
    std::cout << " -----Contact management -----\n";
    std::cout << "1. Enter a contact\n 2. Show all contacts \n 3. Edit a contact \n 4. Exit\n";
    int choice;
    std::cin >> choice;
    infile.open("contacts.txt", std::ios::in);
    switch (choice)
    {
    case 1:
        std::cout << "\n Enter name of the contact: ";
        std::cin >> c_name;
        std::cout << "\n Enter contact number: ";
        std::cin >> c_number;
        con.name = c_name;
        con.number = c_number;
        outfile << con.name << std::endl<< con.number << std::endl;
        break;
    case 2: 
       while(!infile.eof())
        {
            char ch;
            infile.get(ch);
            std::cout<<ch;
        }
    }
  
}