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
    if(value != 0)
        this->value += value;
    else
        this->value = value;

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
    if (!covered.loadFromFile("./images/cell.png",sf::IntRect(0, 0, 32, 32))){
        // error...
        std::cout << "Error!" << std::endl;
        //printf("%s %s %d\n",name_texture,value_s,this->value);
    }
    if (!flaged.loadFromFile("./images/flag.png",sf::IntRect(0, 0, 32, 32))){
        // error...
        std::cout << "Error!" << std::endl;
        //printf("%s %s %d\n",name_texture,value_s,this->value);
    }
    else{
        if(checked)
            sprite.setTexture(texture);
        else
            sprite.setTexture(covered);
    }
}

void Cell::draw(sf::RenderWindow *window)
{

    window->draw(sprite);
}

void Cell::setCheck(bool value)
{
    this->checked = value;
    if(value)
        sprite.setTexture(texture);
    else
        sprite.setTexture(covered);
}

bool Cell::getCheck(){return this->checked;}

void Cell::setFlag()
{
    if(!checked){
        if(flag){
                flag = false;
                sprite.setTexture(covered);
        }
        else{
            flag = true;
            sprite.setTexture(flaged);
        }
    }
}
