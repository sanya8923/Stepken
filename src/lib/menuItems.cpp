#include <fstream>
#include "menuItems.h"
#include <string>
#include <iostream>
#include <ncurses.h>
using namespace std;

//Private methods

//Public methods
MenuItems::MenuItems(vector<string> items) {
    this->items = items;
    maxItemIndex = items.size();
    selected = 0;
}

void MenuItems::addItem(string text) {
    items.push_back(text);
    maxItemIndex++;
}

void MenuItems::setSelected(int index) {
    if (index <= maxItemIndex) {
        selected = index;
    } else {
        throw invalid_argument("Wrong menu items index passed!");
    }
}

void MenuItems::setPointer(string pointer) {
    this->pointer = pointer;
}

int MenuItems::getSelected() {
    return selected;
}

int MenuItems::getLastIndex() {
    return maxItemIndex - 1;
}

void MenuItems::draw(int start) {
    string placeholder = "";
    for (int i = 0; i < pointer.length(); i++) {
        placeholder += " ";
    }

    for (int i = 0; i < items.size(); i++) {
        string item = i == selected ? pointer + items[i] : placeholder + items[i];
        mvprintw(start + i, 0, "%s", item.c_str());
    }
}