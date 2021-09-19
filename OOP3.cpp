//#include "stdafx.h"
#include "OOP3.h"
#include<iostream>
void employee::display_all(){
            cout<<sname<<" "<<name<<" "
                <<patronymic<<" "<<date.day<<'.'<<(date.month <= 9 ? "0" : "" )
                <<date.month<<'.'<<date.year<<" "<<division<<" "
                <<position<<endl;
}
void employee::write_all(ofstream &FILE){
            FILE<<sname<<" "<<name<<" "
                <<patronymic<<" "<<date.day<<'.'<<(date.month <= 9 ? "0" : "" )
                <<date.month<<'.'<<date.year<<" "<<division<<" "
                <<position<<endl;
}
void employee::display_name_n_position_only(){
    cout<<sname<<" "<<name<<" "<<patronymic<<" "<<position<<endl;
}
void employee::write__name_n_position_only(ofstream &FILE){
    FILE<<sname<<" "<<name<<" "<<patronymic<<" "<<position<<endl;
}
void employee::read_from(ifstream &FILE){
    FILE>>sname>>name>>patronymic>>date.day>>date.month>>date.year>>division>>position;
}
int employee::get_division(){
        return division;
}
int employee::get_day(){
    return date.day;
}
int employee::get_month(){
    return date.month;
}
int employee::get_year(){
    return date.year;
}
void fun1(employee *a, int n, ofstream &FILE){
    int q;
    cout<<"Enter division you require for\n";
    cin>>q;
    //ofstream outfile;
    //outfile.open("outfile.txt", ios::app);
    for(int i=0;i<n;i++){
        if(a[i].get_division()==q){
            a[i].display_name_n_position_only();
            a[i].write__name_n_position_only(FILE);
        }
    }
    //outfile<<"\n\n";
    FILE.close();
}
void fun2(employee *a, int n, ofstream &FILE){
    //ofstream outfile;
    //outfile.open("outfile.txt", ios::app);
    time_t now = time(0);
    tm *ltm = localtime(&now);
    //cout<<ltm->tm_mday;
    for(int i=0;i<n;i++){
        if(a[i].get_year()<=1850+ ltm->tm_year && a[i].get_month()<=1 + ltm->tm_mon && a[i].get_day()<=ltm->tm_mday){
            a[i].display_all();
            a[i].write_all(FILE);
        }
    }
    //outfile<<"\n\n";
    FILE.close();
}
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


