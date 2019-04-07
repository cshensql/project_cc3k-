CXX = g++-5
CXXFLAGS = -std=c++14 -MMD -Werror=vla
EXEC = cc3k+
OBJECTS := \
	main.o textDisplay.o floor.o chamber.o BasicCell.o ConcreteCell.o cell.o \
	character.o item.o hero.o enemy.o human.o elves.o dwarf.o orc.o \
	vampire.o phoenix.o merchant.o dragon.o werewolf.o goblin.o troll.o \
	treasure.o normal.o small.o merchanthoard.o dragonhoard.o compass.o barriersuit.o potion.o \
	helper.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

