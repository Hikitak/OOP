#ifndef OOP_H
#define OOP_H


#include<iostream>
#include<string>
#include <ctime>
#include<fstream>
using std::string;
using std::ifstream;


struct bday{
    int day;
    int month;
    int year;
};
typedef struct bday bday;


class employee{
    private:
        string sname;
        string name;
        string patronymic;
        bday date;
        int division;
        string position;
    public:



};
#endif // OOP_H
