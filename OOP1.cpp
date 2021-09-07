#include<iostream>
#include<string>
#include <ctime>
/*
Kadatsky Nikita Sergeevitch 1 7 2002 303 stajer
Svetlov Andrey Vladimirivich 3 8 1990 303 prepodavatel
Qwertiv Anton Antonovich 4 7 1971 203 president
Weriev Nikolay Stepanovich 4 8 1970 103 ohranik
Valentiniv Valentin Valentinovich 3 3 1950 203 nachalnik_otdela
Juj qwertyuiop Antonovskyy 4 5 1980 103 starshy_stajer
Vaslili Valili Valili 6 7 1970 203 artist
*/
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
void fun1(employee *a, int n){
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        if(a[i].division==q){
            cout<<a[i].sname<<" "<<a[i].name<<" "<<a[i].patronymic<<" "<<a[i].position<<endl;
        }
    }
}
void fun2(employee *a, int n){
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
int main(){

    int n;
    cin>>n;
    employee a[n];
    for(int i=0;i<n;i++)
        cin>>a[i].sname>>a[i].name>>a[i].patronymic>>a[i].date.day>>a[i].date.month
           >>a[i].date.year>>a[i].division>>a[i].position;
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
    return 0;
}
