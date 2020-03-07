#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<fstream>

using namespace std;

struct student {
    string imie;
    string nazwisko;
    string plec;
    long long pesel;
    int album;
};

struct bazaStudentow{
    vector<student> spis = vector<student>(100);
    int number = 100;
};


void load_student(student &bob)
{
    cout << "Podaj imie: " << endl;
    cin >> bob.imie;
    cout << "Podaj nazwisko: " << endl;
    cin >> bob.nazwisko;
    cout << "Podaj plec: " << endl;
    cin >> bob.plec;
    cout << "Podaj pesel: " << endl;
    cin >> bob.pesel;
    cout << "Podaj album: " << endl;
    cin >> bob.album;

}

void display_student(student &bob)
{
    cout << "Imie: " << bob.imie << endl
         << "Nazwisko: " << bob.nazwisko << endl
         << "Plec: "     << bob.plec << endl
         << "pesel: "    << bob.pesel << endl
         << "Album: "    << bob.album << endl;

}

void load_table(student tablica[], int how_big) {

    srand( time( NULL ) );


    for (int i=0; i < how_big; i++)
    {
        tablica[i].imie = "Szymon";
        tablica[i].nazwisko = "Sliwa";
        tablica[i].plec = "man";
        tablica[i].pesel =(rand() % 89999999999 ) + 10000000000;
        tablica[i].album = (rand() % 899999 ) + 100000;
    }

}

void display_all_students(student tablica[], int how_big)
{
    cout << endl << endl << endl;
    for (int i=0; i < how_big; i++)
    {
        cout << "Imie: " << tablica[i].imie << endl
             << "Nazwisko: " << tablica[i].nazwisko << endl
             << "Plec: "     << tablica[i].plec << endl
             << "pesel: "    << tablica[i].pesel << endl
             << "Album: "    << tablica[i].album << endl << endl << endl;
    }

}

int find_student(bazaStudentow first,int indeks)
{
    int f=0;

    for(int i=0; i<first.spis.size() ; i++)
    {f++;
        if(indeks == first.spis[i].album)
        {return f;}
    }
    return -1;
}

void load_vector(bazaStudentow &first) {


    srand(time(NULL));


    for (int i = 0; i < first.number; i++) {
        first.spis[i].imie = "Szymon";
        first.spis[i].nazwisko = "Sliwa";
        first.spis[i].plec = "man";
        first.spis[i].pesel = (rand() % 89999999999) + 10000000000;
        first.spis[i].album = (rand() % 899999) + 100000;
    }
    first.spis[22].album = 123456;
}

void add_student(bazaStudentow &first)
{
    student nowy;
    first.spis.push_back(nowy);
    int i = first.spis.size()-1;
    cout << "Podaj dane studenta ktorego chcesz wpisac: " << endl
         << "Imie: " << endl;
    cin >> first.spis[i].imie;
    cout << "Nazwisko: " << endl;
    cin >> first.spis[i].nazwisko;
    cout << "Plec: " << endl;
    cin >> first.spis[i].plec;
    cout << "Pesel: " << endl;
    cin >> first.spis[i].pesel;
    cout << "Numer albumu: " << endl;
    cin >> first.spis[i].album;
}


void remove_student(bazaStudentow &first)
{
    int i;
    cout << "Podaj numer studenta, ktorego chcesz usunac: " << endl;
    cin >> i;
    first.spis.erase (first.spis.begin()+i);
    //   myvector.erase (myvector.begin()+5);
}

void save_students(bazaStudentow &first)
{
    fstream lista;
    lista.open("lista.txt", ios::out);
    for(int i=0; i<first.spis.size(); i++)
    {
        lista << first.spis[i].imie << endl;
        lista << first.spis[i].nazwisko << endl;
        lista << first.spis[i].plec << endl;
        lista << first.spis[i].pesel << endl;
        lista << first.spis[i].album << endl;
    }

    lista.close();
}

void load_studentFile(bazaStudentow &first) {
    string linia;
    int line_number = 1;
    fstream lista;
    lista.open("lista.txt", ios::in);
    if (lista.good() == false)
        cout << "Nie ma pliku, uzyj najpierw funkcji save_student! " << endl;

    for (int i = 0; i < first.spis.size(); i++) {
        while (getline(lista, linia)) {
            switch (line_number) {
                case 1:
                    linia = first.spis[i].imie;
                    break;
                case 2:
                    linia = first.spis[i].nazwisko;
                    break;
                case 3:
                    linia = first.spis[i].plec;
                    break;
                case 4:
                    first.spis[i].pesel = atoi(linia.c_str()) ;
                    break;
                case 5:
                    first.spis[i].album = atoi(linia.c_str());
                    break;
            }
            line_number++;
        }

    }


    for(int i=0; i<first.spis.size(); i++)
    {
        cout << first.spis[i].imie << endl
             << first.spis[i].nazwisko << endl
             << first.spis[i].plec << endl
             << first.spis[i].pesel << endl
             << first.spis[i].album << endl;

    }

    lista.close();
}

int main()
{
    bazaStudentow first;

    int how_big, indeks, menu;
    cout << "Podaj wielkosc tablicy studentow Szymonow: " << endl;
    cin >> how_big;

    student tablica[how_big];
    student bob;

    load_student(bob);
    display_student(bob);
    load_table(tablica, how_big);
    display_all_students(tablica, how_big);
    load_vector(first);

    // cout << first.spis[55].imie << endl; sprawdzenie poprawnego zapelnienia wektorow

    cout << "Podaj szukany numer indeksu: " << endl;
    cin >> indeks;

    cout << "Numer indeksu znaleziony na pozycji: " <<  find_student(first,indeks) << endl; // zeby sprawdzic album numer 22 o numerach 123456

    cout<< endl << endl << "MENU" << endl << "----------"<< endl << "1.Dodaj studenta " << endl << "----------"<< endl << "2.Usun studenta "
        << endl << "----------"<< endl << "3.Zapisz studentow " << endl << "----------"<< endl << "4.Wczytaj studentow z pliku "<<
        endl << "----------"<< endl;



    while(menu>4 || menu<1) {
        cin >> menu;
        if (menu == 1)
            add_student(first);
        else if (menu == 2)
            remove_student(first);
        else if (menu == 3)
            save_students(first);
        else if (menu == 4)
            load_studentFile(first);
        else cout << "Nie ma takiej opcji!" << endl;
    }



    return 0;
}