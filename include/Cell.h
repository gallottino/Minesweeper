#ifndef CELL_H
#define CELL_H

#include<iostream>
#include <SFML/Graphics.hpp>

class Cell
{
    public:
        Cell();
        Cell(int x,int y);
        virtual ~Cell();
        void setX(int x);
        int getX();
        void setY(int y);
        int getY();
        void setValue(int value);
        int getValue();
        void setCheck();
        void draw(sf::RenderWindow *window);
        void loadTexture();

    protected:

    private:
        int x,y,value;
        bool checked;
        sf::Texture texture;
        sf::Texture covered;
        sf::Sprite sprite;

};

#endif // CELL_H
