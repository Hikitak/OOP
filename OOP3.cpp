#include<bits/stdc++.h>
#include "OPP3.h"
int main(){
    //STILL WORKING
    int n;
    ifstream infile; // Создаем потоковый объект infile ...
    // ... класса ifstream для чтения из файла
    infile.open("infile.txt"); // Открываем поток, связывая его с файлом
    infile>>n;
    employee *a= new employee[n];
    for(int i=0;i<n;i++)
        infile>>a[i].sname>>a[i].name>>a[i].patronymic>>a[i].date.day>>a[i].date.month
           >>a[i].date.year>>a[i].division>>a[i].position;
    infile.close();
    int w=-1;
    while(w!=0){
        cout<<"Enter task:\n1)Display names of employee of chosen division\n2)Display data of all employee beyond 50 years old\n0)Quit\n";
        cin>>w;
        switch(w){
            case 1:
                fun1(a,n);
                break;
            case 2:
                fun2(a,n);
                break;
            default:
                cout<<"Quited\n";
                break;
        }
    }
    delete[] a;
    return 0;
}


