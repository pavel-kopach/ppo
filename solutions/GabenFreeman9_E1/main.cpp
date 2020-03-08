#include <iostream>

using namespace  std;

struct student {
    string imie;
    string nazwisko;
    string plec;
    int nr_pesel;
    int nr_indeks;
};

void display_student(student osoba)
{
        cout << osoba.imie<<endl;
        cout << osoba.nazwisko<<endl;
        cout << osoba.plec<<endl;
        cout << osoba.nr_pesel<<endl;
        cout << osoba.nr_indeks<<endl<<endl;
}

void display_all_students(student* osoba, int ile)
{
    for(int i=0; i<ile; i++)
    {
        display_student(osoba[i]);
    }
}

int main()
{
    student osoba[2];
    osoba[0].imie="Jan";
    osoba[0].nazwisko="Kowalski";
    osoba[0].plec="M";
    osoba[0].nr_pesel=2312444321241;
    osoba[0].nr_indeks=214451234;
    osoba[1].imie="Ola";
    osoba[1].nazwisko="Tak";
    osoba[1].plec="K";
    osoba[1].nr_pesel=244213;
    osoba[1].nr_indeks=54764563;
    display_all_students(osoba, 2);
    return 0;
}
