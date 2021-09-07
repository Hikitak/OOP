#include"OOP3.h"
#include<iostream>

using namespace std;

void employee::fun1(employee *a, int n){
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        if(a[i].division==q){
            cout<<a[i].sname<<" "<<a[i].name<<" "<<a[i].patronymic<<" "<<a[i].position<<endl;
        }
    }
}
void employee::fun2(employee *a, int n){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    //cout<<ltm->tm_mday;
    for(int i=0;i<n;i++){
        if(a[i].date.year<=1850+ ltm->tm_year && a[i].date.month<=1 + ltm->tm_mon && a[i].date.day<=ltm->tm_mday){
            cout<<a[i].sname<<" "<<a[i].name<<" "
                <<a[i].patronymic<<" "<<a[i].date.day<<'.'<<(a[i].date.month <= 9 ? "0" : "" )
                <<a[i].date.month<<'.'<<a[i].date.year<<" "<<a[i].division<<" "
                <<a[i].position<<endl;
        }
    }
}
int employee::get_division()
{
    return division;
}
void employee::read_from(ifstream &file)
{
    file>>n;
    employee *a= new employee[n];
    for(int i=0;i<n;i++)
        file>>a[i].sname>>a[i].name>>a[i].patronymic>>a[i].date.day>>a[i].date.month
           >>a[i].date.year>>a[i].division>>a[i].position;
}
void employee::display(){
    for(int i=0;i<n;i++){
            cout<<a[i].sname<<" "<<a[i].name<<" "
                <<a[i].patronymic<<" "<<a[i].date.day<<'.'<<(a[i].date.month <= 9 ? "0" : "" )
                <<a[i].date.month<<'.'<<a[i].date.year<<" "<<a[i].division<<" "
                <<a[i].position<<endl;
            /*outfile<<a[i].sname<<" "<<a[i].name<<" "
                <<a[i].patronymic<<" "<<a[i].date.day<<'.'<<(a[i].date.month <= 9 ? "0" : "" )
                <<a[i].date.month<<'.'<<a[i].date.year<<" "<<a[i].division<<" "
                <<a[i].position<<endl;*/
    }

}
