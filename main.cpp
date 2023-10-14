#include "my_lib.h";

int main() {

    srand(static_cast<unsigned>(time(0)));
    vector<studentas> grupe1000, grupe10000, grupe100000, grupe1000000, grupe10000000;
    vector<studentas> moksliukai;
    vector<studentas> varksiukai;

    matuotiLaika("studentai.txt",grupe1000,1000,moksliukai,varksiukai);
    matuotiLaika("studentai.txt",grupe10000,10000,moksliukai, varksiukai);
    matuotiLaika("studentai.txt",grupe100000,100000,moksliukai,varksiukai);
    matuotiLaika("studentai.txt",grupe1000000,1000000,moksliukai,varksiukai);
    matuotiLaika("studentai.txt",grupe10000000,10000000,moksliukai,varksiukai);

    return 0;
}

