#include <SFML/Graphics.hpp>
#include <iostream>

int windowWidth = 200;
int windowHeight = 400;

using namespace sf;
using namespace std;

class playerClass{
    public:
        playerClass(){
            cout << "Hello World" << endl;
        }
};

int main()
{
    RenderWindow window(VideoMode(windowWidth, windowHeight), "SFML works!");
    
    bool playerUp = false, playerDown = false, playerLeft = false, playerRight = false;


    playerClass playeObject;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Right))  playerRight = true; 
        if (Keyboard::isKeyPressed(Keyboard::Left)) playerLeft = true;
        if (Keyboard::isKeyPressed(Keyboard::Up)) playerUp = true; 
        if (Keyboard::isKeyPressed(Keyboard::Down)) playerDown = true; 

        if (!(Keyboard::isKeyPressed(Keyboard::Right)))  playerRight = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Left))) playerLeft = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Up))) playerUp = false;
        if (!(Keyboard::isKeyPressed(Keyboard::Down))) playerDown = false;

        cout << playerDown << endl;
        cout << playerUp << endl;
        cout << playerLeft << endl;
        cout << playerRight << endl;

        window.clear();
        
        window.display();
        
    }

    return 0;
}