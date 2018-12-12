#include <SFML/Graphics.hpp>
#include <Cell.h>
#include <time.h>

#define N 22
#define N_BOMBS 50


void setBombs();
void setNumbersOfBombs();

Cell field[N][N];
int main()
{


    sf::Text text;
    sf::Font font;

    srand((unsigned)time(NULL));

    setBombs();

    if (!font.loadFromFile("arial.ttf"))
    {

    }
    else{
        text.setFont(font);
        text.setString("Minesweeper - By Gallottino");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Blue);
        text.setStyle(sf::Text::Bold);
        text.move(sf::Vector2f(220,0));
    }


    sf::RenderWindow window(sf::VideoMode(850, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        for(int i=0; i<N;i++){
            for(int j=0; j<N;j++){
                field[i][j].draw(&window);
            }
        }
        field[0][0].draw(&window);
        window.draw(text);
        window.display();
    }

    return 0;
}

void setBombs()
{

    int pos_i;
    int pos_j;

    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            field[i][j].setX((i+2)*32);
            field[i][j].setY((j+2)*32);
        }
    }

    for(int i=0;i<N_BOMBS;i++){
        pos_i = rand()%N;
        pos_j = rand()%N;
        while(field[pos_i][pos_j].getValue() == 88){
            pos_i = rand()%N;
            pos_j = rand()%N;
        }
        field[pos_i][pos_j].setValue(88);
    }

    setNumbersOfBombs();
}

void setNumbersOfBombs()
{
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){

            for(int k=j-1;k<j+2 && k<N;k++){
                if(field[i-1][k].getValue() == 88 && i-1 > 0 && k > 0 && k<N){
                    if(field[i][j].getValue() != 88)
                        field[i][j].setValue(1);
                }
            }

            for(int k=j-1;k<j+2 && k<N;k++){
                if(field[i][k].getValue() == 88 && k > 0 && k<N){
                    if(field[i][j].getValue() != 88)
                        field[i][j].setValue(1);
                }
            }

            for(int k=j-1;k<j+2 && k<N;k++){
                if(field[i+1][k].getValue() == 88 && i+1<N && k > 0 && k<N){
                    if(field[i][j].getValue() != 88)
                        field[i][j].setValue(1);
                }
            }
          field[i][j].loadTexture();
        }
    }
}
