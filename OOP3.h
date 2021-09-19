#ifndef OOP_H

    #define OOP_H
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


    class employee{
        private:
            string sname;
            string name;
            string patronymic;
            bday date;
            int division;
            string position;
        public:
            //void enter_struct(employee *a, int n, ifstream & FILE );
            int get_division();
            void display_all();
            void write_all(ofstream &FILE);
            void read_from(ifstream &FILE);
            void display_name_n_position_only();
            void write__name_n_position_only(ofstream &FILE);
            int get_day();
            int get_month();
            int get_year();

    };
#endif // OOP_H
