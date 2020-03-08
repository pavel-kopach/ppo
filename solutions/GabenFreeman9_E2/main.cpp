#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace  std;

struct BazaStudentow {
    int nr_indeks[100];
    int ile;
};


void load_students(BazaStudentow& students); //pyk
void save_students(BazaStudentow& students); //pyk
void add_students(BazaStudentow& students); //pyk
void remove_students(BazaStudentow& students);
void find_students(BazaStudentow& students, int indeks); //pyk
void show_students(BazaStudentow& students); //pyk
void menu(BazaStudentow& students);


int main() {
    BazaStudentow students;
    menu(students);

    return 0;
}

void menu(BazaStudentow& students)
{
    int szukaj;
    int co=1;
    do{
        cout<<endl;
        cout<<"1-Wczytac liste studentow (Najpierw to!!!)"<<endl;
        cout<<"2-Pokaz liste"<<endl;
        cout<<"3-Dodaj studenta"<<endl;
        cout<<"4-Usun studenta"<<endl;
        cout<<"5-Znajdz studenta"<<endl;
        cout<<"6-Zapisz zmiany do pliku(Na Koncu!!!)"<<endl;
        cout<<"0-Koniec Programu"<<endl<<endl;
        cout << "Co zrobic?: ";
        cin >> co;
        switch (co)
        {
            case 1:{
                load_students(students);
                break;
            }
            case 2:{
                show_students(students);
                break;
            }
            case 3:{
                add_students(students);
                break;
            }
            case 4:{
                remove_students(students);
                break;
            }
            case 5:{
                cout<<"Podaj szukany indeks: "<<endl;
                cin>>szukaj;
                find_students(students, szukaj);
                break;
            }
            case 6:{
                save_students(students);
                break;
            }
            default:{
                co=0;
                break;
            }
        }
    }while(co!=0);
}

void load_students(BazaStudentow& students)
{
    fstream plik;
    string nr_idneks, linia;
    int j=0;
    plik.open("D:\\Gaben\\C++\\Studia\\solutions\\GabenFreeman9_E2\\studenci.txt", ios::in);
    if(!plik.good())
    {
        cout<<"Plik nie istnieje"<<endl;
        exit(0);
    }
    while(getline(plik,linia))
    {
        students.nr_indeks[j]=atoi(linia.c_str());
        j++;
    }
    students.ile=j;
    plik.close();
    cout<<"Pomyslnie zaladowano plik"<<endl;
}

void show_students(BazaStudentow& students)
{
    cout<<"Lista "<<students.ile<<". studentow:"<<endl;
    for(int i=0; i<students.ile; i++)
    {
        cout<<i+1<<". "<<students.nr_indeks[i]<<endl;
    }
    cout<<"ile: "<<students.ile<<endl;
}

void find_students(BazaStudentow& students, int indeks)
{
    bool czy_znalazl=0;
    int pozycja=1;
    for(int i=0; i<students.ile; i++)
    {
        if(students.nr_indeks[i]==indeks)
        {
            czy_znalazl=1;
            break;
        }
        pozycja++;
    }
    if(czy_znalazl==0)
        cout<<"-1"<<endl;
    else
        cout<<pozycja<<endl;
}

void add_students(BazaStudentow& students)
{
    int indeks;
    if(students.ile==100) {
        cout << "Lista pelna" << endl;
    }
    else {
        cout << "Podaj indeks: " << endl;
        cin>>indeks;
        students.nr_indeks[students.ile]=indeks;
        students.ile+=1;
        cout<<"Dodano studenta o indeksie: "<<indeks<<endl;
    }
}

void save_students(BazaStudentow& students)
{
    fstream plik;
    int j=0;
    plik.open("D:\\Gaben\\C++\\Studia\\solutions\\GabenFreeman9_E2\\studenci.txt",ios::out);
    if(!plik.good())
    {
        cout<<"Plik nie istnieje"<<endl;
        exit(0);
    }
    for(int i=0; i<students.ile; i++)
    {
        plik<<students.nr_indeks[i]<<endl;
    }
    plik.close();
}

void remove_students(BazaStudentow& students)
    {
        int pozycja;
        cout<<"Podaj pozycje do usuniecia: "<<endl;
        cin>>pozycja;
        if(pozycja>students.ile)
        {
            cout<<"Ta pozycja jest juz pusta"<<endl;
        }
        else
        {
            for(int i=pozycja-1; i<students.ile-1; i++)
            {
                students.nr_indeks[i]=students.nr_indeks[i+1];
            }
            students.ile=students.ile-1;
        }
    }