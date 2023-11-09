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
        int scale;
        int topSide;
        int rightSide;
        int leftSide;
        int bottomSide;
        Sprite image;
        platformClass(int initXpos, int initYpos, Sprite sprite) {
            scale = 3;
            image = sprite;
            image.setPosition(initXpos, initYpos);
            image.setScale(scale, scale);
            leftSide = image.getPosition().x;
            rightSide = image.getPosition().x + (image.getLocalBounds().width * scale);
            topSide = image.getPosition().y;
            bottomSide = image.getPosition().y + (image.getLocalBounds().height * scale);
        }

};
class playerClass{
    
    public:
        float xVel;
        float yVel;
        float xPos;
        float yPos;
        bool playerFaceright;
        bool onGround;
        Sprite image;
        playerClass(Sprite sprite){
            image = sprite;
            playerFaceright = true;
            onGround = false;
            xVel = 0;
            yVel = 0;
            xPos = 0;
            yPos = 0;
            
        }
        void update(bool playerUp, bool playerDown, bool playerLeft, bool playerRight, platformClass platforms) {
            if (playerRight) {
                playerFaceright = true;
                xVel = .5;
            }
            if (playerLeft) {
                playerFaceright = false;
                xVel = -.5;
            }
            if (playerUp) {
                yVel = -.5;
            }
            if (playerDown) {
                yVel = .5;
            }
            if (!(playerRight || playerLeft)) {

                xVel = 0;
            }
            if (!(playerUp || playerDown)) {

                yVel = 0;
            }
            if (onGround == true) {
                yVel = 0;
            }
            //xPos += xVel;
            //yPos += yVel;
            collide(platforms);
        }
        void collide(platformClass platforms) {
            if (image.getPosition().x > platforms.leftSide) {
                image.setPosition(Vector2f(platforms.leftSide, image.getPosition().y));
            }
        }
            
};

int main()
{
    RenderWindow window(VideoMode(windowWidth, windowHeight), "SFML works!");
    
    bool playerUp = false, playerDown = false, playerLeft = false, playerRight = false;

    Texture platformDefault;
    platformDefault.loadFromFile("C:\\Users\\gueri\\OneDrive\\Programming\\SideScroller-Game\\Data\\Images\\Ground.png");
    Sprite earthSprite1(platformDefault);
    earthSprite1.setTextureRect(IntRect(0, 0, 15, 15));
    
    

    Texture alienTexture;
    alienTexture.loadFromFile("C:\\Users\\gueri\\OneDrive\\Programming\\SideScroller-Game\\Data\\Images\\Alien.png");
    Sprite alienSprite(alienTexture);

    playerClass playerObject(alienSprite);
    platformClass platformObj(100, 100, earthSprite1);
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

        playerObject.update(playerUp, playerDown, playerLeft, playerRight, platformObj);

        

        window.clear();

        window.draw(alienSprite);
        window.draw(platformObj.image);
        alienSprite.move(Vector2f(playerObject.xVel, playerObject.yVel));
        
        window.display();
        
    }

    return 0;
}