#include <iostream>
#include "floor.h"
#include "cell.h"
#include "chamber.h"
#include "textDisplay.h"
#include "character.h"
#include "hero.h"
#include "human.h"
#include "dwarf.h"
#include "elves.h"
#include "orc.h"
#include "enemy.h"
#include "dragon.h"
#include "merchant.h"
#include "vampire.h"
#include "werewolf.h"
#include "troll.h"
#include "goblin.h"
#include "phoenix.h"
#include "item.h"
#include "treasure.h"
#include "barriersuit.h"
#include "compass.h"
#include "potion.h"
#include "ConcreteCell.h"
#include "BasicCell.h"


using namespace std;

int main() {
    bool playing = true; //will become false if the player wants to quit

    while (playing) {
        cout << "Welcome to CC3K+! Please select your hero from the following: " << endl;
        cout << "Human: 140 HP, 20 Atk, 20 Def                                          enter 'h' to be a human" << endl;
        cout << "Dwarf: 100 HP, 20 Atk, 30 Def, gold is doubled in value                enter 'd' to be a dwarf" << endl;
        cout << "Elves: 140 HP, 30 Atk, 10 Def, negative potions have positive effect   enter 'e' to be an elf" << endl;
        cout << "Orc:   180 HP, 30 Atk, 25 Def, gold is worth half value                enter 'o' to be an orc" << endl;

        char race;
        Hero *hero;
        cin >> race;
        switch (race) {
            case 'h' : hero = new Human();
            case 'd' : hero = new Dwarf();
            case 'e' : hero = new Elves();
            case 'o' : hero = new Orc();
            default : cout << "Invalid input! Please try again!" << endl;
        }

        Floor *f = new Floor(hero);
        f->init();
        TextDisplay *display = new TextDisplay();
        display->setFloor(f);
        display->updateHeroInfo(hero);
        display->render();

        string command;
        string dir;

        while(true) {
            cin >> command;
            display->updateAction(command);
            //move direction
            if(command == "no" || command == "so" || command == "ea" || command == "we" ||
                    command == "ne" || command == "nw" || command == "se" || command == "sw") {

            }

            //use potion with direction dir
            else if(command == "u") {
                cin >> dir;
                if(dir == "no" || dir == "so" || dir == "ea" || dir == "we" ||
                     dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {

                } else { //Invalid direction

                }
            }

            //attack with direction dir
            else if(command == "a") {
                cin >> dir;
                if(dir == "no" || dir == "so" || dir == "ea" || dir == "we" ||
                   dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {

                } else { //Invalid direction

                }
            }

            //restart
            else if(command == "r") {

                break;
            }

            //quit
            else if(command == "q") {
                playing = false;
            }
        }
    }
}