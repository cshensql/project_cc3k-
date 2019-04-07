#include <iostream>
#include "floor.h"
#include "cell.h"
//#include "chamber.h"
#include "textDisplay.h"
#include "character.h"
#include "hero.h"
#include "human.h"
#include "dwarf.h"
#include "elves.h"
#include "orc.h"
#include "enemy.h"
//#include "dragon.h"
//#include "merchant.h"
//#include "vampire.h"
//#include "werewolf.h"
//#include "troll.h"
//#include "goblin.h"
//#include "phoenix.h"
#include "item.h"
//#include "treasure.h"
//#include "barriersuit.h"
#include "compass.h"
#include "potion.h"
//#include "ConcreteCell.h"
//#include "BasicCell.h"
#include "helper.h"

using namespace std;

int main() {
    bool playing = true; //will become false if the player wants to quit

    while (playing) {
        srand(time(NULL));

        cout << "Welcome to CC3K+! Please select your hero from the following: " << endl;
        cout << "Human: 140 HP, 20 Atk, 20 Def                                          enter 'h' to be a human" << endl;
        cout << "Dwarf: 100 HP, 20 Atk, 30 Def, gold is doubled in value                enter 'd' to be a dwarf" << endl;
        cout << "Elves: 140 HP, 30 Atk, 10 Def, negative potions have positive effect   enter 'e' to be an elf" << endl;
        cout << "Orc:   180 HP, 30 Atk, 25 Def, gold is worth half value                enter 'o' to be an orc" << endl;

        char race;
        Hero *hero;
        cin >> race;

        if(race == 'h') {
            hero = new Human();
        } else if(race == 'd') {
            hero = new Dwarf();
        } else if(race == 'e') {
            hero = new Elves();
        } else if(race == 'o') {
            hero = new Orc();
        } else {
            if(race == 'q') {
                cout << "You Quit The Game!" << endl;
                playing = false;
                break;
            }else {
                cout << "Invalid input! Please try again!" << endl;
                continue;
            }
        }

        Floor *f = new Floor(hero);
        hero->setFloor(f);
        f->init();
        TextDisplay *display = new TextDisplay();
        display->setFloor(f);
        display->updateHeroInfo(hero);
        display->updateAction("Player character has spawned.");
        display->render(); // print the initial state and floor
        bool RH_found = false, BA_found = false ,BD_found = false, PH_found = false, WA_found = false, WD_found = false;
        bool unknown_potion = false;

        string command;
        string dir;

        while(true) {
            if (hero->getHp() <= 0) {
                cout << "You die!" << endl;
                double score;
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
                if(command == "no") {
                    move_dir = "North";
                } else if(command == "so") {
                    move_dir = "South";
                } else if(command == "ea") {
                    move_dir = "East";
                } else if(command == "we") {
                    move_dir = "West";
                } else if(command == "ne") {
                    move_dir = "Northeast";
                } else if(command == "nw") {
                    move_dir = "Northwest";
                } else if(command == "se") {
                    move_dir = "Southeast";
                } else if(command == "sw") {
                    move_dir = "Southwest";
                }

                int newX = helper::findX(f->getHero()->getX(), command);
                int newY = helper::findY(f->getHero()->getY(), command);
                double goldnum = hero->getGold();
                if(f->getCell(newX, newY).canMove()) {
		        ConcreteCell *conc = f->getCell(newX, newY).GetConcreteCell();
                    if(conc != nullptr && ((conc->GetType() == 'G') || (conc->GetType() == 'B'))) {
                        Item *it = dynamic_cast<Item *> (conc);
                        if(it->isPickable()) {
                            hero->move(command);
                        } else {
                            display->updateAction("You must kill the Dragon in order to pick this item!");
                            f->nextTurn();
                            display->updateHeroInfo(hero);
                            display->render();
                            continue;
                        }
                    } else {
                        hero->move(command);
                    }
                } else {
                    display->updateAction("Invalid move direction!!!");
                    f->nextTurn();
                    display->updateHeroInfo(hero);
                    display->render();
                    continue;
                }

                if (hero->GetType() == '\\') {
                    f->updateCurFloor();
                    if (f->getCurrentFloor() == 6) {
                        cout << "Congradulations, you win the game!" << endl;
                        double score;
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
                    } else {
                        display->updateAction("Player moves to the next floor.");
                        f->init();
                        hero->setDefaultAtkDef();
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
                    if(ccell) {
                        if (ccell->GetType() == 'P') {
                            Potion *p = dynamic_cast<Potion *>(ccell);
                            if (p->getType() == "RH") {
                                if (RH_found) {
                                    neighbours.emplace_back(p->getType());
                                } else {
                                    unknown_potion = true;
                                }
                            } else if (p->getType() == "BA") {
                                if (BA_found) {
                                    neighbours.emplace_back(p->getType());
                                } else {
                                    unknown_potion = true;
                                }
                            } else if (p->getType() == "BD") {
                                if (BD_found) {
                                    neighbours.emplace_back(p->getType());
                                } else {
                                    unknown_potion = true;
                                }
                            } else if (p->getType() == "PH") {
                                if (PH_found) {
                                    neighbours.emplace_back(p->getType());
                                } else {
                                    unknown_potion = true;
                                }
                            } else if (p->getType() == "WA") {
                                if (WA_found) {
                                    neighbours.emplace_back(p->getType());
                                } else {
                                    unknown_potion = true;
                                }
                            } else if (p->getType() == "WD") {
                                if (WD_found) {
                                    neighbours.emplace_back(p->getType());
                                } else {
                                    unknown_potion = true;
                                }
                            }
                        }
                    }
                }
                string Potions = "";
                for (string s : neighbours) {
                    Potions += s + " ";
                }
                if((hero->getGold() - goldnum) > 0 && unknown_potion) {
                    display->updateAction("PC moves " + move_dir + " and picks "
                                          + to_string(hero->getGold() - goldnum) + " Gold(s) and sees an unknown potion.");
                }
                else if((hero->getGold() - goldnum) > 0) {
                    display->updateAction("PC moves " + move_dir + " and picks " + to_string(hero->getGold() - goldnum) + " Golds.");
                }
                else if (unknown_potion && Potions != "") {
                    display->updateAction("PC moves " + move_dir + " and sees " + Potions + "and unknown potions.");
                    unknown_potion = false;
                }
                else if (unknown_potion) {
                    display->updateAction("PC moves " + move_dir + " and sees an unknown potion.");
                    unknown_potion = false;
                }
                else if (Potions != "" && !unknown_potion) {
                    display->updateAction("PC moves " + move_dir + " and sees " + Potions + "potions.");
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
                    if(p != nullptr) {
                        if (!hero->isAlive()) {
                            cout << "You die!" << endl;
                            double score;
                            if (hero->getRace() == "Human") {
                                score = hero->getGold() * 1.5;
                            } else {
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
                            } else if (answer == "No") {
                                playing = false;
                                break;
                            }
                        }
                        string p_type = p->getType();
                        if (p && p->getIsUsed()) {
                            if (p_type == "RH") {
                                RH_found = true;
                            } else if (p_type == "BA") {
                                BA_found = true;
                            } else if (p_type == "BD") {
                                BD_found = true;
                            } else if (p_type == "PH") {
                                PH_found = true;
                            } else if (p_type == "WA") {
                                WA_found = true;
                            } else if (p_type == "WD") {
                                WD_found = true;
                            }
                        }
                        display->updateAction("PC uses " + p_type + ".");
                    }else{
                        display->updateAction("Incorrect input, there is no potion at your selected direction");
                    }
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
		    if (enemy == nullptr) continue; // no enemy at the specified dir
                    char EnemyName = enemy->getType();
                    int heroHp = hero->getHp();
                    int damage = hero->attack(enemy);
                    int enemyHp = enemy->getHp();
                    f->nextTurn();
                    int damageTaken = heroHp - hero->getHp();
                    display->updateAction("PC deals " + to_string(damage) + " damage to " + EnemyName + " ("
                        + to_string(enemyHp) + " HP). " + EnemyName + " deals " + to_string(damageTaken) + " to PC.");
                    display->updateHeroInfo(hero);
                    display->render();
                    continue;
                } else { //Invalid direction
                    cout << "Incorrect input, please enter one of 'no', 'so', 'ea', 'we', 'ne', 'nw', 'se', 'sw'!" << endl;
                }

            }

            //restart
            else if(command == "r") {
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
