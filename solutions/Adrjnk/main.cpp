#include <iostream>
#include <string>
#include<ctime>
#include<vector>
#include <fstream>

struct student
{
    std::string imie;
    std::string nazwisko;
    std::string plec;
    long long pesel;
    long long numer_albumu;
};
struct base_students
{
    int liczba_studentow=100;
    std::vector<student>students=std::vector<student>(100);
};
void loading_student(student &x)
{
    std::cout<<"Podaj imie: "<<"\n";
    std::cin>>x.imie;
    std::cout<<"Podaj nazwisko: "<<"\n";
    std::cin>>x.nazwisko;
    std::cout<<"Podaj plec: "<<"\n";
    std::cin>>x.plec;
    std::cout<<"Podaj pesel: "<<"\n";
    std::cin>>x.pesel;
    std::cout<<"Podaj numer albumu: "<<"\n";
    std::cin>>x.numer_albumu;
}
void display_student(student &x)
{
    std::cout<<x.imie<<"\n";
    std::cout<<x.nazwisko<<"\n";
    std::cout<<x.plec<<"\n";
    std::cout<<x.pesel<<"\n";
    std::cout<<x.numer_albumu<<"\n";
    std::cout<<std::endl;
}
void loading_all_students(student *students,int n)
{
    int p;
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        p = rand()%2;
        if (p == 1)
        {
            students[i].plec = "M";
            students[i].imie = "Jan";
            students[i].nazwisko = "Kowalski";
        }
        else
        {
            students[i].plec = "K";
            students[i].imie = "Milena";
            students[i].nazwisko = "Kowalska";
        }
        students[i].pesel = rand() % 99999999999 + 10000000000;
        students[i].numer_albumu = rand() % 999999 + 100000;
    }

}
void display_all_students(student *students, int n)
{

    for(int i=0; i<n; i++)
    {
        display_student(students[i]);
    }
}
void uzupelnienie(base_students &group)
{
    int p;
    srand(time(NULL));

    for (int i = 0; i < group.students.size(); i++) {
        p = rand() % 2;
        if (p == 1) {
            group.students[i].plec = "M";
            group.students[i].imie = "Jan";
            group.students[i].nazwisko = "Kowalski";
        } else {
            group.students[i].plec = "K";
            group.students[i].imie = "Milena";
            group.students[i].nazwisko = "Kowalska";
        }
        group.students[i].pesel = rand() % 89999999999 + 10000000000;
        group.students[i].numer_albumu = rand() % 899999 + 100000;
    }
}
int find_student(const base_students &group, int nr)
{
    for(int i=0; i<group.students.size(); i++)
    {
        if(group.students[i].numer_albumu==nr)
            return i;
    }
    return -1;
}
student add_students(base_students &group)
{
    student y;
    std::cout<<"Podaj imie: "<<"\n";
    std::cin>>y.imie;
    std::cout<<"Podaj nazwisko: "<<"\n";
    std::cin>>y.nazwisko;
    std::cout<<"Podaj plec: "<<"\n";
    std::cin>>y.plec;
    std::cout<<"Podaj pesel: "<<"\n";
    std::cin>>y.pesel;
    std::cout<<"Podaj numer albumu: "<<"\n";
    std::cin>>y.numer_albumu;
    return y;
}
void remove_students(base_students &group)
{
    int z;
    std::cout<<"wpisz nr indeksu studenta ktorego chcesz usunac: ";
    std::cin>>z;
    for(int i=0; i<group.students.size();i++)
    {
        if(group.students[i].numer_albumu==z)
        {
            group.students.erase(group.students.begin() + i);
        }
    }
}
void save_student(base_students &group)
{
    std::fstream list;
    list.open("lista.txt" , std::ios::out);
    for(int i=0; i<group.students.size(); i++)
    {
        list<<group.students[i].imie<<std::endl;
        list<<group.students[i].nazwisko<<std::endl;
        list<<group.students[i].plec<<std::endl;
        list<<group.students[i].pesel<<std::endl;
        list<<group.students[i].numer_albumu<<std::endl;
    }
    list.close();
}
void wyswietlanie(base_students &group)
{
    std::string line;
    int line_number=1;
    std::fstream list;
    list.open("lista.txt", std::ios::in);
    if(list.good() == false)
        std::cout<<"Brak pliku"<<std::endl;
    else
        for(int i=0; i<group.students.size(); i++)
        {
            while(std::getline(list, line))
            {
             switch (line_number)
             {
                 case 1:
                     line = group.students[i].imie;
                 case 2:
                     line = group.students[i].nazwisko;
                 case 3:
                     line = group.students[i].plec;
                 case 4:
                     line = group.students[i].pesel;
                 case 5:
                     line = group.students[i].numer_albumu;
                     break;
             }
             line_number++;
            }
        }
}
int main()
{
    int n,nr_indeksu;
    base_students group;
    std::cout<<"Liczba studentow: "<<"\n";
    std::cin>>n;
    student x;
    student students[n];
    loading_student(x);
    display_student(x);
    loading_all_students(students,n);
    display_all_students(students,n);
    uzupelnienie(group);
    std::cout<<"Wpisz nr indeksu ktorego poszukujesz:";
    std::cin>>nr_indeksu;
    std::cout<<"oto nr studenta ktorego poszukujesz:";
    std::cout<<find_student(group,nr_indeksu);
    group.students.push_back(add_students(group));
    remove_students(group);
    save_student(group);
    wyswietlanie(group);
    return 0;
}
