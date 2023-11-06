#include <SFML/Graphics.hpp>
#include <iostream>

int windowWidth = 900;
int windowHeight = 900;
int halgwWinHeight = windowHeight / 2;
int halgwWinWidth = windowWidth / 2;

using namespace sf;
using namespace std;

class platformClass {
    public:
        float xvel;
        float yvel;
        float xpos;
        float ypos;
        platformClass(float xpos, float ypos) {
            xpos = xpos;
            ypos = ypos;
        }

};
class playerClass{
    
    public:
        float xvel;
        float yvel;
        float xpos;
        float ypos;
        bool playerFaceright;
        bool onGround;
        playerClass(){
            playerFaceright = true;
            onGround = false;
            xvel = 0;
            yvel = 0;
            xpos = 0;
            ypos = 0;
            
        }
        void update(bool playerUp,bool playerDown,bool playerLeft,bool playerRight) {
            if (playerRight) {
                playerFaceright = true;
                xvel = 1;
            }
            else if (playerLeft) {
                playerFaceright = false;
                xvel = -1;
            }
            if (playerUp) {
                yvel = -1;
            }
            else if (playerDown) {
                yvel = 1;
            }
            if (!(playerRight || playerLeft)) {
                
                xvel = 0;
            }
            if (!(playerUp || playerDown)) {

                yvel = 0;
            }
            if (onGround) {
                yvel = 0;
            }
            xpos += xvel;
            ypos += yvel;
            collide();

            cout << xpos << endl;
            cout << ypos << endl;
        }
        void collide() {
            if (ypos > 100) {
                yvel = 0;
                onGround = true;
            }
            else {
                onGround = false;
            }
        }
};

int main()
{
    RenderWindow window(VideoMode(windowWidth, windowHeight), "SFML works!");
    
    bool playerUp = false, playerDown = false, playerLeft = false, playerRight = false;


    playerClass playerObject ;

    Texture alienTexture;
    alienTexture.loadFromFile("C:\\Users\\gueri\\OneDrive\\Programming\\SideScroller-Game\\Data\\Images\\Alien.png");
    Sprite alienSprite(alienTexture);

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

        playerObject.update(playerUp, playerDown, playerLeft, playerRight);

        

        window.clear();

        window.draw(alienSprite);
        alienSprite.move(Vector2f(playerObject.xvel, playerObject.yvel));
        
        window.display();
        
    }

    return 0;
}