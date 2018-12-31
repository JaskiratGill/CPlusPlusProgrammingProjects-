#include <SFML/Graphics.hpp>
#include <iostream>

#include <tic-tac-toe/playMove.h>

using namespace std;
using namespace sf;


int main() {

    /************************************************************************************************************/
    /* The following variables define the state of the game                                                     */
    /************************************************************************************************************/

    // You should complete the following declarations
    // Make sure to initialize the variables

    // The game board array
    int gameBoard[3][3] = {Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty,Empty};

    // An boolean that represents the turn in the game
    bool turn= true;

    // A boolean to represent if the move is valid
    bool validMove= true;

    // A boolean to represent if the game is over
    bool is_game_over = false;

    // An integer that represents the win code
    int winCode=0;

    /************************************************************************************************************/
    /* Insert code that loads the various images used by the game and creates the sprites                       */
    /* The loading of the X image is shown. Repreat for the rest of the images                                  */
    /************************************************************************************************************/

    // Get the X image
    sf::Texture X_texture;
    if (!X_texture.loadFromFile("X.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite X_sprite(X_texture);
    
    // Get the O image
    sf::Texture O_texture;
    if (!O_texture.loadFromFile("O.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite O_sprite(O_texture);
   

    // Get the blank image
    sf::Texture blank_texture;
    if (!blank_texture.loadFromFile("blank.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite blank_sprite(blank_texture);

    /************************************************************************************************************/
    /* Insert code that creates the window and displays it                                                      */
    /************************************************************************************************************/

    // First, we find the sizes of the images so we can determine the size of the window we must create
    // The images (X, O and Black) are assumed to be square are are all of the same size
    // Thus, we just find the size of one of them

    // The tile size is the size of the images
    const int tileSize = X_texture.getSize().x;

    // The cell borders (thick lines) are rectangles
    // The size of these rectangles is 1/20th of the size of the tile by 3 cell sizes plus 2 barWidth's
    const int barWidth = tileSize/20;
    const int barHeight = boardSize*tileSize + (boardSize-1)*barWidth;

    // The size of the window in pixels can now be calculated
    const int windowSize = boardSize*tileSize + (boardSize-1)*barWidth;

    // Create the main window: it has a title bar and a close button, but is not resizable
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "ECE244 Tic-Tac-Toe", sf::Style::Titlebar | sf::Style::Close);

    // Set the Icon that appears in the task bar when the window is minimized
    // Insert you code here, see the lab handout
    
     sf::Image WindowIcon;
    if(!WindowIcon.loadFromFile("icon.jpg")) {
        return EXIT_FAILURE;
    }
    window.setIcon(WindowIcon.getSize().x,WindowIcon.getSize().y,WindowIcon.getPixelsPtr());

    // Create the horizonal (vertical) borders as rectangles of sizes barWidth and barHeight (berHeight and barWidth)
    // Insert your code here
    //Creating the different lines of separation (borders), 2 horizontal and 2 vertical lines
    sf::RectangleShape HorizontalOne(sf::Vector2f(barHeight, barWidth));
    sf::RectangleShape HorizontalTwo(sf::Vector2f(barHeight, barWidth));
    sf::RectangleShape VerticalOne(sf::Vector2f(barWidth, barHeight));
    sf::RectangleShape VerticalTwo(sf::Vector2f(barWidth, barHeight));
    
    //Creating the lines indicating winning sequence. One vertical, One horizontal , and One diagonal line. 
    
    sf::RectangleShape winLineHorizontal(sf::Vector2f(windowSize, 10));
    sf::RectangleShape winLineVertical(sf::Vector2f(10, windowSize));
    
    int diagonal= (sqrt(pow(windowSize, 2) + pow(windowSize, 2)));
    sf::RectangleShape winLineDiagonal(sf::Vector2f(diagonal, 10));
  

    /************************************************************************************************************/
    /* This is the main event loop of the code                                                                  */
    /************************************************************************************************************/

    // Start the game loop that runs as long as the window is open
    while (window.isOpen()) {
        // The event
        sf::Event event;
      
        // Process the events
        while (window.pollEvent(event)) {

            // This is the handling of the close window event
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }

            // Left mouse button pressed: get the click position and play the move
            // is_game_over is a variable you should define above
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // left mouse button is pressed: get the coordinates in pixels
                // Insert your code to get the coordinates here

                sf::Vector2i localPosition = Mouse::getPosition(window);
                // The Vector2i is a type defined in SFML that defines a
                // two element integer vector (x,y). This is how the
                // elements of the vector are accessed
                int xPosition = localPosition.x;
                int yPosition = localPosition.y;
                
                // Convert the pixel coordinates into game board rows and columns
                // Just divide by tileSize
                // Observe that the x axis is the rows and the y axis is the columns
                // Also make sure that row and column values are valid
                // Insert your code below
                
                int row = (yPosition/tileSize);     
                int col = (xPosition/tileSize);   
                
                // Play the move by calling the playMove function
                // Insert your code below
                
                if ((((row >= 0) && (row <= 2)) && ((col >= 0) && (col <= 2))) && is_game_over== false){
                    
                    playMove(gameBoard, row, col, turn, validMove, is_game_over, winCode);
                    
                }

            }       
   
        }
        


        // Insert code to draw the tiles using the sprites created earlier
        // You must determine the position of each cell on the grid, taking into account the width of
        // the border and then position the sprite there and draw it.
        // Draw the entire board, cell borders included,
        // reflecting any move that has just happened (check the gameBoard array)
        // Further, if the game is over and one player wins, you must create and draw a rectangle of
        // windowSize width and 10 pixels height to indicate the winning marks
        // The fill of this rectangle should be white

        // Insert your code here
        
        //For loop that loop through each element of the board, and if there is a 1, it places picture of X, if 
        //there is a -1, it places picture of Y. If the value of element is zero, it places picture of blank
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (gameBoard[j][i]==0){
                    
                    blank_sprite.setPosition((i*(tileSize)+(i*barWidth)),(j*(tileSize)+(j*barWidth)));
                    window.draw(blank_sprite);
                    
                }
                else if (gameBoard[j][i]==-1){
                   
                    O_sprite.setPosition((i*(tileSize)+(i*barWidth)),(j*(tileSize)+(j*barWidth)));
                     window.draw(O_sprite);
                  
                }
                else if (gameBoard[j][i]==1){
                   
                    X_sprite.setPosition((i*(tileSize)+(i*barWidth)),(j*(tileSize)+(j*barWidth)));
                     window.draw(X_sprite);
                    
                }           


            }
        }
        
        //Position, draw, and color each of the horizontal and vertical separation lines on the board
        
        HorizontalOne.setPosition(0,tileSize);
        window.draw(HorizontalOne);
        HorizontalOne.setFillColor(sf::Color(0,0,0));
        
        HorizontalTwo.setPosition(0,((2*tileSize)+barWidth));
        window.draw(HorizontalTwo);
        HorizontalTwo.setFillColor(sf::Color(0,0,0));
        
        VerticalOne.setPosition(tileSize, 0);
        window.draw(VerticalOne);
        VerticalOne.setFillColor(sf::Color(0,0,0));
        
        VerticalTwo.setPosition(((2*tileSize)+barWidth), 0);
        window.draw(VerticalTwo);
        VerticalTwo.setFillColor(sf::Color(0,0,0));
        
        //Since is_game_over is passed to the function, it will be set to true by the function if there is any winning sequence
        //If is_game_over is true, the winCode is checked and the line representing the winning sequence is drawn
        
        if(is_game_over == true){
            
            if (winCode==1){
                winLineHorizontal.setPosition(0, ((tileSize/2)-barWidth));
                window.draw(winLineHorizontal);
    
            }
            
            else if (winCode==2){
                winLineHorizontal.setPosition(0, (tileSize + (tileSize/2)));
                window.draw(winLineHorizontal);
      
            }
            
            else if (winCode==3){
                winLineHorizontal.setPosition(0, (2*tileSize + (tileSize/2) +barWidth));
                window.draw(winLineHorizontal);
                
            }
           
            else if (winCode==4){
                winLineVertical.setPosition(((tileSize/2)-barWidth), 0);
                window.draw(winLineVertical);
            }
            
            else if (winCode==5){
                winLineVertical.setPosition((tileSize + (tileSize/2)), 0);
                window.draw(winLineVertical);
            }
            
            else if (winCode==6){
                winLineVertical.setPosition((2*tileSize + (tileSize/2) +barWidth), 0);
                window.draw(winLineVertical);
            }
            
            else if (winCode==7){
                winLineDiagonal.setPosition(0, 0);
                winLineDiagonal.setRotation(45);
                window.draw(winLineDiagonal);

            }
            
            else if (winCode==8){
                winLineDiagonal.setPosition(windowSize, 0);
                winLineDiagonal.setRotation(135);
                window.draw(winLineDiagonal);
            } 
            
        }
        
        
        
        // Display to the window
        window.display();
    }

    return EXIT_SUCCESS;
}
