#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace  std;

struct student {
    int miejsce;
    string imie;
    string nazwisko;
    string plec;
    int nr_pesel;
    int nr_indeks;
};

struct BazaStudentow {
    student bazaW[100];
    int ile;
};

void menu(BazaStudentow& bazaZ);
void display_student(BazaStudentow& bazaZ, int gdzie);
void display_all_students(BazaStudentow& bazaZ);
void add_student(BazaStudentow& bazaZ);
void remove_student(BazaStudentow& bazaZ);
int find_students(BazaStudentow& bazaZ, int indeks);
void load_students(BazaStudentow& bazaZ);
void save_students(BazaStudentow& bazaZ);


int main() {
    BazaStudentow bazaZ{{},0};
    //przykladowe
    bazaZ.bazaW[0].miejsce=1;
    bazaZ.bazaW[0].imie="Jan";
    bazaZ.bazaW[0].nazwisko="Kowalski";
    bazaZ.bazaW[0].plec="M";
    bazaZ.bazaW[0].nr_pesel=2312444321241;
    bazaZ.bazaW[0].nr_indeks=214451234;
    bazaZ.bazaW[1].miejsce=2;
    bazaZ.bazaW[1].imie="Ola";
    bazaZ.bazaW[1].nazwisko="Tak";
    bazaZ.bazaW[1].plec="K";
    bazaZ.bazaW[1].nr_pesel=244213;
    bazaZ.bazaW[1].nr_indeks=54764563;
    bazaZ.ile=2;
    //
    menu(bazaZ);
    return 0;
}

void menu(BazaStudentow& bazaZ)
{
    int szukaj=0;
    int co=1;
    do{
        cout<<endl;
        cout<<"1-Wczytac liste studentow (Najpierw to!!!)"<<endl;
        cout<<"2-Pokaz wszystkich studentow"<<endl;
        cout<<"3-Pokaz konkretnego studenta"<<endl;
        cout<<"4-Dodaj studenta"<<endl;
        cout<<"5-Usun studenta"<<endl;
        cout<<"6-Znajdz studenta"<<endl;
        cout<<"7-Zapisz zmiany do pliku(Na Koncu!!!)"<<endl;
        cout<<"0-Koniec Programu"<<endl<<endl;
        cout << "Co zrobic?: ";
        cin >> co;
        switch (co)
        {
            case 1:{
                load_students(bazaZ);
                break;
            }
            case 2:{
                display_all_students(bazaZ);
                break;
            }
            case 3:{
                cout<<"Podaj miejsce: "<<endl;
                cin>>szukaj;
                display_student(bazaZ, szukaj);
                break;
            }
            case 4:{
                add_student(bazaZ);
                break;
            }
            case 5:{
                remove_student(bazaZ);
                break;
            }
            case 6:{
                cout<<"Podaj szukany indeks: "<<endl;
                cin>>szukaj;
                cout<<"Indeks znajduje sie na pozycji (-1 jesli brak): "<<find_students(bazaZ, szukaj)<<endl;
                break;
            }
            case 7:{
                save_students(bazaZ);
                break;
            }
            default:{
                co=0;
                break;
            }
        }
    }while(co!=0);
}

void display_student(BazaStudentow& bazaZ, int gdzie)
{
        cout << bazaZ.bazaW[gdzie-1].miejsce<<". " << endl;
        cout<<"Imie-"<<bazaZ.bazaW[gdzie-1].imie<<endl;
        cout<<"Nazwisko-"<<bazaZ.bazaW[gdzie-1].nazwisko<<endl;
        cout<<"Plec-"<<bazaZ.bazaW[gdzie-1].plec<<endl;
        cout<<"nr pesel-"<<bazaZ.bazaW[gdzie-1].nr_pesel<<endl;
        cout<<"nr indeksu-"<<bazaZ.bazaW[gdzie-1].nr_indeks<<endl;
}

void display_all_students(BazaStudentow& bazaZ)
{
    for(int i=0; i<bazaZ.ile; i++) {
        cout << bazaZ.bazaW[i].miejsce<<". " << endl;
        cout << "Imie-" << bazaZ.bazaW[i].imie << endl;
        cout << "Nazwisko-" << bazaZ.bazaW[i].nazwisko << endl;
        cout << "Plec-" << bazaZ.bazaW[i].plec << endl;
        cout << "nr pesel-" << bazaZ.bazaW[i].nr_pesel << endl;
        cout << "nr indeksu-" << bazaZ.bazaW[i].nr_indeks << endl;
        cout<<"---------------------------------"<<endl;
    }
    cout<<"Studentow: "<<bazaZ.ile<<endl;
    cout<<"---------------------------------"<<endl;
}

void add_student(BazaStudentow& bazaZ)
{
    long double x;
    //string y;
    if(bazaZ.ile>=100) {
        cout << "Lista pelna!" << endl;
    }
    else {
        bazaZ.bazaW[bazaZ.ile].miejsce=bazaZ.ile+1;
        cout << "Podaj imie: " << endl;
        cin>>bazaZ.bazaW[bazaZ.ile].imie;
        cout << "Podaj nazwisko: " << endl;
        cin>>bazaZ.bazaW[bazaZ.ile].nazwisko;
        cout << "Podaj plec[k/m]: " << endl;
        cin>>bazaZ.bazaW[bazaZ.ile].plec;
        cout << "Podaj pesel: " << endl;
        cin>>x;
        bazaZ.bazaW[bazaZ.ile].nr_pesel=x;
        cout << "Podaj indeks: " << endl;
        cin>>x;
        bazaZ.bazaW[bazaZ.ile].nr_indeks=x;
        bazaZ.ile++;
    }
}

void load_students(BazaStudentow& bazaZ)
{
    fstream plik;
    string nr_idneks, linia, sciezka;
    int j=0, miejsce=1;
    bool czy;
    cout<<"Wczytac domyslny plik?[0/1]: "<<endl;
    cin>>czy;
    if(czy==1) {
        plik.open("D:\\Gaben\\C++\\Studia\\solutions\\GabenFreeman9_Poprawka\\studenci.txt", ios::in);
    } else{
        cout<<"Podaj sciezke: "<<endl;
        cin>>sciezka;
        plik.open(sciezka, ios::in);
    }
    if(!plik.good())
    {
        cout<<"Plik nie istnieje"<<endl;
        exit(0);
    }
    while(getline(plik,linia))
    {
        bazaZ.bazaW[j].imie=linia;
        getline(plik,linia);
        bazaZ.bazaW[j].nazwisko=linia;
        getline(plik,linia);
        bazaZ.bazaW[j].plec=linia;
        getline(plik,linia);
        bazaZ.bazaW[j].nr_pesel=atoi(linia.c_str());
        getline(plik,linia);
        bazaZ.bazaW[j].nr_indeks=atoi(linia.c_str());
        bazaZ.bazaW[j].miejsce=miejsce;
        j++;
        miejsce++;
    }
    bazaZ.ile=j;
    plik.close();
    cout<<"Pomyslnie zaladowano plik"<<endl;
}

void save_students(BazaStudentow& bazaZ)
{
    fstream plik;
    bool czy;
    string sciezka;
    cout<<"Zapisac do domyslnego pliku?[0/1]: "<<endl;
    cin>>czy;
    if(czy==1) {
        plik.open("D:\\Gaben\\C++\\Studia\\solutions\\GabenFreeman9_Poprawka\\studenci.txt", ios::out);
    } else{
        cout<<"Podaj sciezke: "<<endl;
        cin>>sciezka;
        plik.open(sciezka, ios::out);
    }
    for(int i=0; i<bazaZ.ile; i++)
    {
        plik<<bazaZ.bazaW[i].imie<<endl;
        plik<<bazaZ.bazaW[i].nazwisko<<endl;
        plik<<bazaZ.bazaW[i].plec<<endl;
        plik<<bazaZ.bazaW[i].nr_pesel<<endl;
        plik<<bazaZ.bazaW[i].nr_indeks<<endl;
    }
    plik.close();
}

void remove_student(BazaStudentow& bazaZ)
{
    int pozycja;
    cout<<"Podaj pozycje do usuniecia: "<<endl;
    cin>>pozycja;
    if(pozycja>bazaZ.ile)
    {
        cout<<"Ta pozycja jest juz pusta"<<endl;
    }
    else
    {
        for(int i=pozycja-1; i<bazaZ.ile-1; i++)
        {
            bazaZ.bazaW[i].miejsce=i+1;
            bazaZ.bazaW[i].imie=bazaZ.bazaW[i+1].imie;
            bazaZ.bazaW[i].nazwisko=bazaZ.bazaW[i+1].nazwisko;
            bazaZ.bazaW[i].plec=bazaZ.bazaW[i+1].plec;
            bazaZ.bazaW[i].nr_pesel=bazaZ.bazaW[i+1].nr_pesel;
            bazaZ.bazaW[i].nr_indeks=bazaZ.bazaW[i+1].nr_indeks;

        }
        bazaZ.ile--;
    }
}

int find_students(BazaStudentow& bazaZ, int indeks)
{
    int pozycja=1;
    for(int i=0; i<bazaZ.ile; i++)
    {
        if(bazaZ.bazaW[i].nr_indeks==indeks)
        {
            return pozycja;
        }
        pozycja++;
    }
    return -1;
}
