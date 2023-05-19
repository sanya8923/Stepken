#include <fstream>
#include "screen.h"
#include <string>
#include <iostream>
#include <ncurses.h>
using namespace std;

//Private methods
void Screen::writeText() {
    mvprintw(0, 0, "%s", text.c_str());
}

int Screen::handleUserInput() {
    while (true) {
        int firstCh = getch();
        switch(firstCh) {
            case '\033':
                {
                    getch();
                    int selectedIndex = items.getSelected();
                    int lastIndex = items.getLastIndex();
                    switch(getch()) {
                        case 65:
                            items.setSelected(selectedIndex == 0 ? lastIndex : selectedIndex - 1);
                            items.draw(menuPosition);
                            break;
                        //Arrow down
                        case 66:
                            items.setSelected(selectedIndex == lastIndex ? 0 : selectedIndex + 1);
                            items.draw(menuPosition);
                            break;
                        default:
                            break;
                    }
                    break;
                }
            case 10:
                return items.getSelected();
        }
    }
}

int Screen::waitForEnter() {
    mvprintw(menuPosition, 0, "%s", enterPlaceholder.c_str());

    while (getch() != 10) continue;

    return -1;
}

//Public methods
Screen::Screen(vector<string> items, int menuPosition) : items(items) {
    this->menuPosition = menuPosition;
}

void Screen::clearScreen() {
    system("clear");
    clear();
}

int Screen::drawMenu() {
    initscr();
    noecho();
    cbreak();
    clearScreen();
    writeText();
    items.draw(menuPosition);

    return items.getLastIndex() != -1 ? handleUserInput() : waitForEnter();
}

void Screen::setText(string text) {
    this->text = text;
}

void Screen::setMenuItems(vector<string> items) {
    this->items = items;
}

void Screen::addMenuItem(string item) {
    items.addItem(item);
}

void Screen::setMenuPointer(string pointer) {
    items.setPointer(pointer);
}

void Screen::setEnterPlaceholder(string text) {
    this->enterPlaceholder = text;
}