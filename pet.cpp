#include "Pet.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>


//******************************************************
// ==================== TEMEL ==========================
//******************************************************


void clearing() {
    system("cls");
}

void delay(int number) {
    Sleep(number);
}

void printart(std::string art) {
    std::cout << art << std::endl;
}

//******************************************************
// ==================== MENU ===========================
//******************************************************

void menu() {
    std::cout << '\n';
    purple();
    std::cout << "**** MENU ****" << std::endl;
    std::cout << "---------------\n";
    std::cout << "1.BESLE: " << std::endl;
    std::cout << "2.OYNA: " << std::endl;
    std::cout << "3.UYUT: " << std::endl;
    std::cout << "4.KAYDET: " << std::endl;
    std::cout << "5.CIKIS: " << std::endl;
    std::cout << "Seciminizi yapin (1-5): ";
    reset();
}

//*****************************************************
// ==================== KAYDETMEK ====================
//*****************************************************


void savegame(pet p) {
    std::ofstream f("pet.dat");
    f << p.name << std::endl
        << p.hunger << std::endl
        << p.happines << std::endl
        << p.energy << std::endl
        << p.days << std::endl;
    f.close();
}

//*****************************************************
// ==================== YUKLEMEK ======================
//*****************************************************

void loadgame(pet& p) {
    std::ifstream f("pet.dat");
    if (!f) {
        p.name.clear();
        return;
    }
    std::getline(f, p.name);
    f >> p.hunger >> p.happines >> p.energy >> p.days;
    f.close();
}


//*****************************************************
// ==================== BAR CIZMEK ====================
//*****************************************************

void draw_bar(const std::string& label, int value) {
    std::cout << label;
    if (value >= 70) {
        green();
    }
    else if (value >= 50) {
        yellow();
    }
    else {
        red();
    }

    int bar = value / 10;
    std::cout << "[";

    for (int i = 0; i < bar; i++) {
        std::cout << "#";
    }

    for (int i = bar; i < 10; i++) {
        std::cout << " ";
    }
    std::cout << "]";
    reset();
    std::cout << " " << std::setw(3) << value << "/100";
}
//******************************************************
// ==================== DURUMLAR =======================
//******************************************************

void showpet(const pet& p) {
    const char* lines[7];

    bool dead = (p.hunger <= 0 || p.happines <= 0 || p.energy <= 0);
    bool sad = (p.hunger < 60 || p.happines < 60 || p.energy < 60);

    if (dead) {
        lines[0] = "  /\\ ___ /\\";
        lines[1] = " (  x   x  )";
        lines[2] = "  \\  >#<  /";
        lines[3] = "  /       \\";
        lines[4] = " /         \\";
        lines[5] = "|           |";
        lines[6] = "  ///  ///   ";
    }
    else if (sad) {
        lines[0] = "  /\\ ___ /\\";
        lines[1] = " (  T   T  )";
        lines[2] = "  \\  >#<  /";
        lines[3] = "  /       \\";
        lines[4] = " /         \\";
        lines[5] = "|           |";
        lines[6] = "  ///  ///   ";
    }
    else {
        lines[0] = "  /\\ ___ /\\";
        lines[1] = " (  o   o  )";
        lines[2] = "  \\  >Y<  /";
        lines[3] = "  /       \\";
        lines[4] = " /         \\";
        lines[5] = "|           |";
        lines[6] = "  ///  ///   ";
    }

    draw_bar("ACLIK:     ", p.hunger);
    std::cout << '\n';
    draw_bar("MUTLULUK:  ", p.happines);
    std::cout << '\n';
    draw_bar("ENERJI:    ", p.energy);
    std::cout << '\n';
    std::cout << '\n';


    for (int i = 0; i < 7; i++) {
        std::cout << lines[i] << '\n';
    }
}


//*******************************************************************
// ==================== DEGERLERIN ASMAMASI iCIN ====================
//*******************************************************************
void limit(int& v) {
    if (v > 100) {
        v = 100;
    }
    if (v < 0) {
        v = 0;
    }
}
//*********************************************************************
// ==================== DOYUR UYUT VS FONKSIYONLAR ====================
//*********************************************************************

// DURUMU GOSTEREN FONK
void statupdate(pet& p) {
    p.hunger -= rand() % 8 + 4;
    p.happines -= rand() % 7 + 3;
    p.energy -= rand() % 8 + 4;
    p.days++;

    limit(p.hunger);
    limit(p.happines);
    limit(p.energy);
}
// YEDIRMEK
void feeding(pet& p) {
    p.hunger += rand() % 20 + 10;

    limit(p.hunger);
}
// OYNAMAK
void playing(pet& p) {
    p.hunger -= rand() % 10 + 3;
    p.energy -= rand() % 15 + 5;
    p.happines += rand() % 20 + 5;
    limit(p.hunger);
    limit(p.energy);
    limit(p.happines);

}
// UYUTMAK
void sleeping(pet& p) {
    p.hunger -= rand() % 10 + 3;
    p.happines -= rand() % 9 + 1;
    p.energy += rand() % 30 + 15;

    limit(p.hunger);
    limit(p.happines);
    limit(p.energy);
}
//******************************************************
// ==================== ASCII FRAMELER =================
//******************************************************
void happy_frame1() {
    printart(R"(

 /\     /\
{  `---'  }
{  O   O  }
~~>  "    <~~
 \   /\  /
  `-----'____
  /     \    \_
 {       }\  )_\_   _
 |  \_/  |/ /  \_\_/ )
  \__/  /(_/     \__/
    (__

)");
}

void happy_frame2() {
    printart(R"(

     /\     /\
    {  `---'  }
    {  O   O  }
    ~~>  "    <~~
     \  \__/ /
      `-----'____
      /     \    \_
     {       }\  )_\_   _
     |  \_/  |/ /  \_\_/ )
      \__/  /(_/     \__/
  O     (__

)");
}

void sleep_frame1() {
    printart(R"(
         ,-""""""-.
     /\j__/\  (  \`--.
     \`@_@'/  _)  >--.`.
    _{.:Y:_}_{{_,'    ) )
   {_}`-^{_} ```     (_/

)");
}

void sleep_frame2() {
    printart(R"(
         ,-""""""-.
     /\j__/\  (  \`--.
 zzz \`=_='/  _)  >--.`.
    _{.:Y:_}_{{_,'    ) )
   {_}`-^{_} ```     (_/
)");
}

void dead_frame1() {
    printart(R"(
          
   ____
 _\___ \  |\_/|
\     \ \/ @,@ \
 \__   \ \ >"< //
  |===  \/____)_)
  \______|    |
      _/_|  | |
     (_/  \_)_)

)");

}

void dead_frame2() {
    printart(R"(
           ___
          (___)
   ____
 _\___ \  |\_/|
\     \ \/ = = \
 \__   \ \> " <//
  |===  \/____)_)
  \______|    |
      _/_|  | |
     (_/  \_)_) RIP


)");

}

void eating_frame1() {
    printart(R"(

           _..---...,""-._  /}/)
     .''        ,      ``..'(/-<
    /   _      {      )         \
   ;   _ `.     `.   <         a(
 ,'   ( \  )      `.  \ __.._ .: y
(  <\_-) )'-.____...\  `._   //-'
 `. `-' /-._)))      `-._)))
   `...'


)");
}

void eating_frame2() {
    printart(R"(

           _..---...,""-._  /}/)
     .''        ,      ``..'(/-<
    /   _      {      )         \   NAMM NAMM 
   ;   _ `.     `.   <         a(
 ,'   ( \  )      `.  \ __.._ .: y
(  <\_-) )'-.____...\  `._   //-'
 `. `-' /-._)))      `-._)))       >==P>
   `...'


)");
}


//******************************************************
// ==================== ANIMASYONLAR ===================
//******************************************************

// MUTLU
void animatedhappy() {
    for (int i = 0; i < 3; i++) {
        clearing();
        happy_frame1();
        delay(400);
        clearing();
        happy_frame2();
        delay(400);
    }
}

//UYUMAK
void animatedsleep() {
    for (int i = 0; i < 3; i++) {
        clearing();
        sleep_frame1();
        delay(400);
        clearing();
        sleep_frame2();
        delay(400);
    }
}

// OLMEK
void animateddead() {
    for (int i = 0; i < 3; i++) {
        clearing();
        dead_frame1();
        delay(400);
        clearing();
        dead_frame2();
        delay(400);
    }
}

// YEMEK
void animatedeating() {
    for (int i = 0; i < 3; i++) {
        clearing();
        eating_frame1();
        delay(400);
        clearing();
        eating_frame2();
        delay(400);
    }
}



//**************************************************
// ==================== RENKLER ====================
//**************************************************
void green() {
    std::cout << "\033[32m";
}
void yellow() {
    std::cout << "\033[33m";
}
void red() {
    std::cout << "\033[31m";
}
void blue() {
    std::cout << "\033[94m";
}
void purple() {
    std::cout << "\033[95m";
}
void pink() {
    std::cout << "\033[38;5;213m";

}
void reset() {
    std::cout << "\033[0m";
}
