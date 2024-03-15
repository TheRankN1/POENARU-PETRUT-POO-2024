#include "pch.h"
#include "iostream"

using namespace std;
using namespace System;

struct Book {
    unsigned vechime;
    unsigned an;
    char editura[20];
    char autor[20];
};

class Carte {
private:  unsigned vechime;
       unsigned an;
       char editura[20];
       char autor[20];

public:
    Carte(unsigned vechime1, unsigned an1, char* editura1, char* autor1) {
        vechime = vechime1;
        an = an1;
        strcpy_s(editura, 20, editura1);
        strcpy_s(autor, 20, autor1);
    }
    Carte() {}

    char* arata_autor() {
        return this->autor;
    }

    char* arata_editura() {
        return this->editura;
    }

    unsigned arata_an() {
        return this->an;
    }

    unsigned arata_vechime() {
        return this->vechime;
    }
    
};

int main()
{
    Console::WriteLine("Introduceti numarul de carti");
    int nr_carti;
    cin >> nr_carti;
    Book* carti = new Book[nr_carti];
    for (int i = 0; i < nr_carti; i++) {
        Console::WriteLine("Introduceti numele autorului {0}: ", i + 1);
        char autor[20];
        cin >> autor;
        strcpy_s(carti[i].autor, 20, autor);

        Console::WriteLine("Introduceti numele editurii {0}: ", i + 1);
        char editura[20];
        cin >> editura;
        strcpy_s(carti[i].editura, 20, editura);

        Console::WriteLine("Introduceti anul cartii {0}: ", i + 1);
        unsigned an;
        cin >> an;
        carti[i].an = an;

        Console::WriteLine("Introduceti vechimea cartii {0}: ", i + 1);
        unsigned vechime;
        cin >> vechime;
        carti[i].vechime = vechime;
    }
    Console::WriteLine("Afisam numele autorului editura , anul aparitiei si vechimea cartii aferente");
    for (int i = 0; i < nr_carti; i++) {
        cout << carti[i].autor << "\t" << carti[i].editura<< "\t" << carti[i].an << "\t"<< carti[i].vechime << endl;
    }

    Console::ReadKey();
}
