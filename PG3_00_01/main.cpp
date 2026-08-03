#include <stdio.h>
#include <string.h>
#include <list>
#include <iostream>

using namespace std;

int main(void) {

    list<const char*> eki_list{
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
        "Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro",
        "Takadanobaba", "Sin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya",
        "Ebisu", "Meguro", "Gotanda", "Osaki", "Sinagawa", "Tamachi", "Hamamatsucho",
        "Shimbashi", "Yurakucho"
    };

    printf("1970年\n");
    for (list<const char*>::iterator it_f = eki_list.begin(); it_f != eki_list.end(); ++it_f) {
        std::cout << *it_f << endl;
    }

    printf("\n2019年\n");
    for (list<const char*>::iterator it_f = eki_list.begin(); it_f != eki_list.end(); ++it_f) {
        if (strcmp(*it_f, "Tabata") == 0) {
            eki_list.insert(it_f, "Nishi-Nippori");
            std::cout << "Nishi-Nippori" << endl;
        }
        std::cout << *it_f << endl;
    }

    printf("\n2022年\n");
    for (list<const char*>::iterator it_f = eki_list.begin(); it_f != eki_list.end(); ++it_f) {
        if (strcmp(*it_f, "Tamachi") == 0) {
            eki_list.insert(it_f, "Takanawa Gateway");
            std::cout << "Takanawa Gateway" << endl;
        }
        std::cout << *it_f << endl;
    }

    return 0;
}