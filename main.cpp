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
#include "helper.h"

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
        display->updateAction("Player character has spawned.");
        display->render(); // print the initial state and floor
        bool RH_found, BA_found, BD_found, PH_found, WA_found, WD_found = false;
        bool unknown_potion = false;

        string command;
        string dir;

        while(true) {
            if (hero->getHp() <= 0) {
                cout << "You die!" << endl;
                int score;
                if (hero->getRace() == "Human") {
                    score = hero->getGold() * 1.5;
                }
                else {
                    score = hero->getGold();
                }
                cout << "Your final score is " + to_string(score) + "!" << endl;
                cout << "Do you want to play again?" << endl;
                string answer;
                cout << "Yes or No" << endl;
                cin >> answer;
                if (answer == "Yes") {
                    f->clear();
                    break;
                }
                else if (answer == "No") {
                    playing = false;
                    break;
                }
            }
            cin >> command;
            display->updateAction(command);
            //move direction
            if(command == "no" || command == "so" || command == "ea" || command == "we" ||
                    command == "ne" || command == "nw" || command == "se" || command == "sw") {
                string move_dir;
                switch (dir) {
                case "no": move_dir = "North";
                case "so": move_dir = "South";
                case "ea": move_dir = "East";
                case "we": move_dir = "West";
                case "ne": move_dir = "Northeast";
                case "nw": move_dir = "Northwest";
                case "se": move_dir = "Southeast";
                case "sw": move_dir = "Southwest";
                }
                hero->move(command);
                if (hero->GetType() == '\\') {
                    f->updateCurFloor();
                    if (f->getCurrentFloor() == 6) {
                        cout << "Congradulations, you win the game!" << endl;
                        int score;
                        if (hero->getRace() == "Human") {
                            score = hero->getGold() * 1.5;
                        }
                        else {
                            score = hero->getGold();
                        }
                        cout << "Your final score is " + to_string(score) + "!" << endl;
                        cout << "Do you want to play again?" << endl;
                        string answer;
                        cout << "Yes or No" << endl;
                        cin >> answer;
                        if (answer == "Yes") {
                            f->clear();
                            break;
                        }
                        else if (answer == "No") {
                            playing = false;
                            break;
                        }
                    }
                    else {
                        display->updateAction("Player moves to the next floor.");
                        f->nextTurn();
                        display->updateHeroInfo(hero);
                        display->render();
                        continue;
                    }
                }
                vector<string> neighbours;
                vector<string> directions;
                directions.emplace_back("no");
                directions.emplace_back("so");
                directions.emplace_back("ea");
                directions.emplace_back("we");
                directions.emplace_back("ne");
                directions.emplace_back("nw");
                directions.emplace_back("se");
                directions.emplace_back("sw");
                for (string s : directions) {
                    Cell c = f->getCell(helper::findX(hero->getX(), s), helper::findY(hero->getY(), s));
                    ConcreteCell *ccell = c.GetConcreteCell();
                    if (ccell->GetType() == 'P') {
                        Potion *p = dynamic_cast<Potion *>(ccell);
                        if (p->getType() == "RH") {
                            if (RH_found) {
                                neighbours.emplace_back(p->getType);
                            }
                            else {
                                unknown_potion = true;
                            }
                        } else if (p->getType() == "BA") {
                            if (BA_found) {
                                neighbours.emplace_back(p->getType);
                            }
                            else {
                                unknown_potion = true;
                            }
                        } else if (p->getType() == "BD") {
                            if (BD_found) {
                                neighbours.emplace_back(p->getType);
                            }
                            else {
                                unknown_potion = true;
                            }
                        } else if (p->getType() == "PH") {
                            if (PH_found) {
                                neighbours.emplace_back(p->getType);
                            }
                            else {
                                unknown_potion = true;
                            }
                        } else if (p->getType() == "WA") {
                            if (WA_found) {
                                neighbours.emplace_back(p->getType);
                            }
                            else {
                                unknown_potion = true;
                            }
                        } else if (p->getType() == "WD") {
                            if (WD_found) {
                                neighbours.emplace_back(p->getType);
                            }
                            else {
                                unknown_potion = true;
                            }
                        }
                    }
                }
                string Potions = "";
                for (string s : neighbours) {
                    Potions += s + "";
                }
                if (unknown_potion && Potions != "") {
                    display->updateAction("PC moves " + move_dir + "and sees " + Potions + "and unknown potions.");
                }
                else if (unknown_potion) {
                    display->updateAction("PC moves " + move_dir + "and sees " +  "an unknown potion.");
                }
                else if (Potions != "" && !unknown_potion) {
                    display->updateAction("PC moves " + move_dir + "and sees " + Potions + "potions.");
                }
                else {
                    display->updateAction("PC moves " + move_dir + ".");
                }
            }

            //use potion with direction dir
            else if(command == "u") {
                cin >> dir;
                if(dir == "no" || dir == "so" || dir == "ea" || dir == "we" ||
                     dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {
                    Potion *p = hero->pickPotion(dir);
                    if (!hero->isAlive()) {
                        cout << "You die!" << endl;
                        int score;
                        if (hero->getRace() == "Human") {
                            score = hero->getGold() * 1.5;
                        }
                        else {
                            score = hero->getGold();
                        }
                        cout << "Your final score is " + to_string(score) + "!" << endl;
                        cout << "Do you want to play again?" << endl;
                        string answer;
                        cout << "Yes or No" << endl;
                        cin >> answer;
                        if (answer == "Yes") {
                            f->clear();
                            break;
                        }
                        else if (answer == "No") {
                            playing = false;
                            break;
                        }
                    }
                    string p_type = p->getType();
                    if (p && p->getIsUsed()) {
                        switch (p_type) {
                            case "RH": RH_found = true;
                            case "BA": BA_found = true;
                            case "BD": BD_found = true;
                            case "PH": PH_found = true;
                            case "WA": WA_found = true;
                            case "WD": WD_found = true;
                        }
                    }
                    display->updateAction("PC uses " + p_type + ".");
                } else { //Invalid direction
                    cout << "Incorrect input, please enter one of 'no', 'so', 'ea', 'we', 'ne', 'nw', 'se', 'sw'!" << endl;
                }
            }

            //attack with direction dir
            else if(command == "a") {
                cin >> dir;
                if(dir == "no" || dir == "so" || dir == "ea" || dir == "we" ||
                   dir == "ne" || dir == "nw" || dir == "se" || dir == "sw") {
                    Enemy *enemy = hero->attackDir(dir);
                    int heroHp = hero->getHp();
                    int damage = hero->attack(enemy);
                    int enemyHp = enemy->getHp();
                    f->nextTurn();
                    int damageTaken = heroHp - hero->getHp();
                    display->updateAction("PC deals " + to_string(damage) + " damage to " + enemy->getType() + " ("
                        + to_string(enemyHp) + " HP). " + enemy->getType() + " deals " + to_string(damageTaken) + " to PC.");
                    display->updateHeroInfo(hero);
                    display->render();
                    continue;
                } else { //Invalid direction
                    cout << "Incorrect input, please enter one of 'no', 'so', 'ea', 'we', 'ne', 'nw', 'se', 'sw'!" << endl;
                }

            }

            //restart
            else if(command == "r") {
                f->clear();
                break;
            }

            //quit
            else if(command == "q") {
                playing = false;
                break;
            }

            else {
                cout << "Invalid command, please enter again." << endl;
            }
            f->nextTurn();
            display->updateHeroInfo(hero);
            display->render();
        }
    }
}