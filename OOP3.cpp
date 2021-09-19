//#include "stdafx.h"
#include "FUN_3.h"
int main(){
    int n;
    ifstream infile; // Создаем потоковый объект infile ...
    // ... класса ifstream для чтения из файла
    infile.open("infile.txt"); // Открываем поток, связывая его с файлом
    infile>>n;
    employee *a= new employee[n];
    for (int i = 0; i < n; i++)
        a[i].read_from(infile);
    infile.close();
    int w=-1;
    while(w!=0){
        cout<<"Enter task:\n1)Display names of employee of chosen division\n2)Display data of all employee beyond 50 years old\n0-or any other)Quit\n";
        cin>>w;
        switch(w){
            case 1:{
                ofstream outfile;
                outfile.open("outfile.txt");
                fun1(a,n,outfile);
                break;}
            case 2:{
                ofstream outfile;
                outfile.open("outfile.txt");
                fun2(a,n,outfile);
                break;}
            default:
                cout<<"Quited\n";
                break;
        }
    }
    delete[] a;
    return 0;
}


