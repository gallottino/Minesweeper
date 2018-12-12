#include <SFML/Graphics.hpp>
#include <Cell.h>
#include <time.h>

#define N 22
#define N_BOMBS 50

void restart();
void setBombs();
void setNumbersOfBombs();
void deepSearch(int i, int j);

Cell field[N][N];
int main()
{


    sf::Text text;
    sf::Font font;

    srand((unsigned)time(NULL));

    setBombs();

    if (!font.loadFromFile("./fonts/arial.ttf"))
    {

    }
    else{
        text.setFont(font);
        text.setString("Minesweeper 88");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        text.move(310,0);
    }


    sf::RenderWindow window(sf::VideoMode(850, 800), "MineSweeper");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                int i = pos.x/32 - 2;
                int j = pos.y/32 - 2;
                printf("%d %d\n",i,j);
                if(i>=0 && i<N && j>=0 && j<N){
                    if(field[i][j].getValue() == 88){
                        restart();
                        setBombs();
                    }
                    else
                        deepSearch(i,j);
                }
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                int i = pos.x/32 - 2;
                int j = pos.y/32 - 2;
                printf("%d %d\n",i,j);
                if(i>=0 && i<N && j>=0 && j<N){
                    field[i][j].setFlag();
                }
            }
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

void restart()
{
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++){
            field[i][j].setCheck(false);
            field[i][j].setValue(0);
        }
    }
}

void deepSearch(int i, int j)
{
    if(!field[i][j].getCheck())
        field[i][j].setCheck(true);


    if(field[i][j].getValue() != 0){
        return;
    }

    for(int k=j-1;k<j+2 && k<N;k++){
        if(!field[i-1][k].getCheck() && i-1 >= 0 && k >= 0 && k<N ){
            deepSearch(i-1,k);
        }
    }

    for(int k=j-1;k<j+2 && k<N;k++){
        if(!field[i][k].getCheck() && k >= 0 && k<N && k!=j){
            deepSearch(i,k);
        }
    }

    for(int k=j-1;k<j+2 && k<N;k++){
        if(!field[i+1][k].getCheck() && i+1<N && k >=0 && k<N){
            deepSearch(i+1,k);
        }
    }

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
                if(field[i-1][k].getValue() == 88 && i-1 >= 0 && k >= 0 && k<N){
                    if(field[i][j].getValue() != 88)
                        field[i][j].setValue(1);
                }
            }

            for(int k=j-1;k<j+2 && k<N;k++){
                if(field[i][k].getValue() == 88 && k >= 0 && k<N && k!=j){
                    if(field[i][j].getValue() != 88)
                        field[i][j].setValue(1);
                }
            }

            for(int k=j-1;k<j+2 && k<N;k++){
                if(field[i+1][k].getValue() == 88 && i+1<N && k >=0 && k<N){
                    if(field[i][j].getValue() != 88)
                        field[i][j].setValue(1);
                }
            }
          field[i][j].loadTexture();
        }
    }
}
