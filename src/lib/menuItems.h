#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class MenuItems
{
    vector<string> items;
    int maxItemIndex;
    int selected;
    string pointer = "> ";

    public:
        MenuItems(vector<string> items);
        void addItem(string text);
        void setSelected(int index);
        void setPointer(string pointer);
        int getSelected();
        int getLastIndex();
        void draw(int start);
};