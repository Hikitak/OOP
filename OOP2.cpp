#include<iostream>
#include<string>
#include <ctime>
#include<fstream>
using namespace std;
struct bday{
    int day;
    int month;
    int year;
};
typedef struct bday bday;
struct employee{
    string sname;
    string name;
    string patronymic;
    bday date;
    int division;
    string position;
};
typedef struct employee employee;
void enter_struct(employee *a, int n, ifstream & FILE ){
    for(int i=0;i<n;i++)
        FILE>>a[i].sname>>a[i].name>>a[i].patronymic>>a[i].date.day>>a[i].date.month
           >>a[i].date.year>>a[i].division>>a[i].position;

}

void fun1(employee *a, int n, ofstream &FILE){
    int q;
    cout<<"Enter division you require for\n";
    cin>>q;
    //ofstream outfile;
    //outfile.open("outfile.txt", ios::app);
    for(int i=0;i<n;i++){
        if(a[i].division==q){
            cout<<a[i].sname<<" "<<a[i].name<<" "<<a[i].patronymic<<" "<<a[i].position<<endl;
            //outfile<<a[i].sname<<" "<<a[i].name<<" "<<a[i].patronymic<<" "<<a[i].position<<endl;
            FILE<<a[i].sname<<" "<<a[i].name<<" "<<a[i].patronymic<<" "<<a[i].position<<endl;
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
        if(a[i].date.year<=1850+ ltm->tm_year && a[i].date.month<=1 + ltm->tm_mon && a[i].date.day<=ltm->tm_mday){
            cout<<a[i].sname<<" "<<a[i].name<<" "
                <<a[i].patronymic<<" "<<a[i].date.day<<'.'<<(a[i].date.month <= 9 ? "0" : "" )
                <<a[i].date.month<<'.'<<a[i].date.year<<" "<<a[i].division<<" "
                <<a[i].position<<endl;
            FILE<<a[i].sname<<" "<<a[i].name<<" "
                <<a[i].patronymic<<" "<<a[i].date.day<<'.'<<(a[i].date.month <= 9 ? "0" : "" )
                <<a[i].date.month<<'.'<<a[i].date.year<<" "<<a[i].division<<" "
                <<a[i].position<<endl;
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
    enter_struct(a,n,infile);
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

