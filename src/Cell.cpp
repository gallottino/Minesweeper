#include "Cell.h"
#include <string.h>

Cell::Cell()
{
    this->value = 0;
    this ->checked = false;
}

Cell::Cell(int x,int y)
{
    this->x = x;
    this->y = y;
}

Cell::~Cell()
{
    //dtor
}

void Cell::setX(int x)
{
    this->x = x;
}

int Cell::getX(){ return x; }

void Cell::setY(int y)
{
    this->y = y;
    sprite.setPosition(sf::Vector2f(x,y));

}
int Cell::getY(){ return y; }

void Cell::setValue(int value)
{
    int before = this->value;
    this->value += value;
    if(this->value == 176){
        printf("%d    ERROREEEEEEEE\n ",before);
    }
}

int Cell::getValue(){ return value; }

void Cell::loadTexture()
{
    char name_texture[20] = "./images/cell_";
    char value_s[3];
    //printf("STRING: %s,VALORE: %d\n",name_texture,this->value);
    itoa(this->value,value_s,10);
    strcat(name_texture,value_s);
    strcat(name_texture,".png");

    if (!texture.loadFromFile(name_texture,sf::IntRect(0, 0, 32, 32))){
        // error...
        std::cout << "Error!" << std::endl;
        //printf("%s %s %d\n",name_texture,value_s,this->value);
    }
    else{
        sprite.setTexture(texture);
    }
}

void Cell::draw(sf::RenderWindow *window)
{

    window->draw(sprite);
}
