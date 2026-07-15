//*******************************************************
// ==================== kutuphaneler ====================
//*******************************************************
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <fstream>
#include "Pet.h"



//***********************************************
// ==================== MAIN ====================
//***********************************************
int main() {
    srand(time(NULL));

    pet pet;

    char answer;
    char choice;
    bool gameover = false;
   

    

    do {
        clearing();
        gameover = false;
        blue();
        std::cout << "===================================\n";
        std::cout << std::setw(30) << std::right << "PIXEL PET : KONSOL DOSTUM" << '\n';
        std::cout << "===================================\n";
        reset();


      

        std::cout << "\nkayitli bir oyun var mi (e/h): ";
        std::cin >> answer;

        while (answer != 'e' && answer != 'E' && answer != 'h' && answer != 'H') {
            red();
            std::cout << "lutfen E/H veya e/h giriniz: ";
            reset();
            std::cin >> answer;
        }

        if (answer == 'E' || answer == 'e') {
            loadgame(pet);
            if (pet.name.empty()) {
                std::cout << "Dosya bulunamadi, yeni oyun baslatiliyor\n";
                pet.hunger = 100;
                pet.happines = 100;
                pet.energy = 100;
                pet.days = 0;
            }
        }
        else {
            std::cin.ignore();
            std::cout << "Evcil hayvaninza bir isim veriniz: ";
            getline(std::cin, pet.name);
           

        }
        


       do{

           clearing();
           bool validation = true; 
           blue();
            std::cout << std::setw(7) << std::right << "=== " << pet.name << " Dunyasi " << "(yas: " << pet.days << ") ===\n";
            std::cout << "--------------------------------\n";
            reset();
            showpet(pet);
            std::cout << '\n';
            menu();
            std::cin >> choice;

            switch (choice) {
             
            case '1':
                feeding(pet);
                animatedeating();
                break;
            case '2':
                playing(pet);
                animatedhappy();
                break;
            case '3':
                sleeping(pet);
                animatedsleep();
                break;
            case '4':
                savegame(pet);
                green();
                std::cout << " *** OYNUNUZ KAYDEDILDI ***" << std::endl;
                reset();
                break;

            case '5':
                red();
                std::cout << "*** CIKIS YAPILIYOR ***" << std::endl;
                reset();
                gameover = true;
                break;
             default:
                red();
                std::cout << "LUTFEN (1-5) ARASINDA SAYI GIRINIZ: ";
                reset();
                validation = false;
                delay(1200);
                break;
            }


            if (validation == true) {
                statupdate(pet);
            }


            if (pet.hunger <= 0 || pet.energy <= 0 || pet.happines <= 0) {
                animateddead();
                delay(1100);
                pink();
                std::cout << pet.name << " " << pet.days << " gun yasadi. " << '\n';
                reset();
                gameover = true;
            }
       } while (!gameover);
        
      
       do {
           std::cout << "Bir daha oynamak ister misiniz (e/h): ";
           std::cin >> answer;

           if (answer != 'e' && answer != 'E' && answer != 'h' && answer != 'H') {
               red();
               std::cout << "Lutfen E/e veya H/h giriniz!\n";
               reset();
               
           }

       } while (answer != 'e' && answer != 'E' &&
           answer != 'h' && answer != 'H');

       if (answer == 'h' || answer == 'H') {
           green();
           std::cout << "*** IYI GUNLER!!! *** ";
           reset();
       }


    } while (answer == 'E' || answer == 'e');
    return 0;
}
