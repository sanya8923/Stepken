#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "menuItems.h"
using namespace std;

class Screen
{
    MenuItems items;
    int menuPosition;
    string text;
    string enterPlaceholder;

    void writeText();
    int handleUserInput();
    int waitForEnter();

    public:
        Screen(vector<string> options, int menuPosition);

        void clearScreen();
        int drawMenu();
        void setText(string text);
        void setMenuItems(vector<string>);
        void addMenuItem(string item);
        void setMenuPointer(string pointer);
        void setEnterPlaceholder(string text);
};