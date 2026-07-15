#ifndef PET_H
#define PET_H

#include <string>
//******************************************************
// ==================== VERI YAPISI ====================
//******************************************************
struct pet {
    std::string name{};
    int happines = 100;
    int hunger = 100;
    int energy = 100;
    int days = 0;
};
//******************************************************
// ==================== PROTOTIPLER ====================
//******************************************************
void clearing();
void printart(std::string);
void delay(int number = 500);
void menu();
void savegame(pet);
void loadgame(pet&);
void draw_bar(const std::string&, int);
void showpet(const pet&);
void statupdate(pet&);
void limit(int&);
void feeding(pet&);
void playing(pet&);
void sleeping(pet&);

// ==================== ANIMASYONLAR ====================
void animatedhappy();
void animatedsleep();
void animateddead();
void animatedeating();




// ==================== RENKLER ====================
void green();
void yellow();
void red();
void blue();
void purple();
void pink();
void reset();

#endif
