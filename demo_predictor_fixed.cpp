#include "raylib.h"

int main()
{
    InitWindow(1280, 720, "ping pinfong");// Initialize window and context
    InitAudioDevice(); // Initialize audio device and context
    SetTargetFPS(60);// Set target FPS (maximum) can slow the ball if you want

    //=================================================
    // SOUNDS
    //=================================================
    // Loadig the given sound effects
    Sound hitSound   = LoadSound("dry-fart.mp3");
    Sound wallSound  = LoadSound("wal.mp3");
    Sound scoreSound = LoadSound("score.mp3");
    Sound winSound   = LoadSound("win.mp3");
    
    //=================================================
    // MUSIC
    //=================================================
    // Loading the given music tracks from local files
    Music bg1 = LoadMusicStream("bg.mp3");
    Music bg2 = LoadMusicStream("bg2.mp3");
    Music bg3 = LoadMusicStream("bg3.mp3");
    Music bg4 = LoadMusicStream("bg4.mp3");
    Music bg5 = LoadMusicStream("bg5.mp3");

    int selectedMusic = 1; // Variable to keep track of the selected music track its a boolean variable to check if the music is enabled or not
    bool musicEnabled = true; // Variable to keep track of whether music is enabled or not
    bool soundEnabled = true; // Variable to keep track of whether sound effects are enabled or not

    SetMusicVolume(bg1, 0.5f); // Set volume for music (1.0 is max level) we made it 0.5f to make it not too loud
    SetMusicVolume(bg2, 0.5f);
    SetMusicVolume(bg3, 0.5f);
    SetMusicVolume(bg4, 0.5f);
    SetMusicVolume(bg5, 0.5f);
    PlayMusicStream(bg1);

    //=================================================
    // SCREEN
    //=================================================

    int screenWidth  = GetScreenWidth(); // Get current screen width
    int screenHeight = GetScreenHeight(); // Get current screen height

    //=================================================
    // GAME STATE
    //=================================================

    int paddleWidth  = 20; // Width of the paddles
    int paddleHeight = 120; // Height of the paddles
    int paddleSpeed  = 8; //   Speed of the paddles

    int leftPaddleX  = 20; // X position of the left paddle
    int leftPaddleY  = screenHeight / 2 - paddleHeight / 2; // Y position of the left paddle

    int rightPaddleX = screenWidth - paddleWidth - 20; // X position of the right paddle
    int rightPaddleY = screenHeight / 2 - paddleHeight / 2; // Y position of the right paddle

    int ballRadius = 10; // Radius of the ball
    int ballX      = screenWidth / 2; // X position of the ball
    int ballY      = screenHeight / 2; // Y position of the ball
    int ballSpeedX = 6; // Speed of the ball in the X direction
    int ballSpeedY = 6; // Speed of the ball in the Y direction

    int leftScore  = 0; //
    int rightScore = 0;
    int winningScore = 0;

    bool gameStarted  = false; // Variable to keep track of whether the game has started or not
    bool gameOver     = false; // Variable to keep track of whether the game is over or not
    bool paused       = false; // Variable to keep track of whether the game is paused or not
    bool showSettings = false;
 // Variable to keep track of whether the settings menu is being shown or not



    const char* winnerText = "WINNER WINNER CHICKEN DINNER"; // Variable to keep track of the winner text to display when the game is over

    //=================================================
    // BUTTONS
    //=================================================

    Rectangle play5Button    = { screenWidth / 2.0f - 100, 220, 200, 60 }; 
    // Variable to keep track of the play button for 5 points game
    Rectangle play10Button   = { screenWidth / 2.0f - 100, 310, 200, 60 };
    // Variable to keep track of the play button for 10 points game
    Rectangle play15Button   = { screenWidth / 2.0f - 100, 400, 200, 60 };
    // Variable to keep track of the play button for 15 points game
    Rectangle settingsButton = { screenWidth / 2.0f - 100, 490, 200, 60 };
    // Variable to keep track of the settings button

    Rectangle bg1Button      = { 500, 170, 280, 50 };
    // Variable to keep track of the background button 1
    Rectangle bg2Button      = { 500, 240, 280, 50 };
    // Variable to keep track of the background button 2
    Rectangle bg3Button      = { 500, 310, 280, 50 };
    // Variable to keep track of the background button 3
    Rectangle bg4Button      = { 500, 380, 280, 50 };
    // Variable to keep track of the background button 4
    Rectangle bg5Button      = { 500, 450, 280, 50 };
    // Variable to keep track of the background button 5
    Rectangle musicOffButton = { 500, 520, 280, 50 };
    // Variable to keep track of the music off button
    Rectangle soundButton    = { 500, 590, 280, 50 };
    // Variable to keep track of the sound button
    Rectangle backButton     = { 500, 660, 280, 50 };
 // Variable to keep track of the back button

    Rectangle playAgainButton = { screenWidth / 2.0f - 150, 380, 300, 60 };
    // Variable to keep track of the play again button shown on the game over screen
    Rectangle menuButton      = { screenWidth / 2.0f - 150, 460, 300, 60 };
    // Variable to keep track of the main menu button shown on the game over screen

    //=================================================
    // MAIN LOOP
    //=================================================

    while (!WindowShouldClose())
    {
        // Update all music streams every frame
        UpdateMusicStream(bg1);
        UpdateMusicStream(bg2);
        UpdateMusicStream(bg3);
        UpdateMusicStream(bg4);
        UpdateMusicStream(bg5);

        Vector2 mouse = GetMousePosition(); // Get the current mouse position

        //==========================================
        // INPUT: MAIN MENU
        //==========================================

        if (!gameStarted && !gameOver && !showSettings) 
        // If the game has not started, is not over, and the settings menu is not being shown
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            //If the left mouse button is pressed
            {
                if (CheckCollisionPointRec(mouse, play5Button)) // If the mouse is over the play button for 5 points game

                {
                    winningScore = 5;
                    gameStarted  = true;
                }
                if (CheckCollisionPointRec(mouse, play10Button)) // If the mouse is over the play button for 10 points game
                {
                    winningScore = 10;
                    gameStarted  = true;
                }
                if (CheckCollisionPointRec(mouse, play15Button)) // If the mouse is over the play button for 15 points game
                {
                    winningScore = 15;
                    gameStarted  = true;
                }
                if (CheckCollisionPointRec(mouse, settingsButton) // If the mouse is over the settings button
                )
                {
                    showSettings = true;
                }
            }
        }

        //==========================================
        // INPUT: SETTINGS
        //==========================================

        else if (showSettings)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) // If the left mouse button is pressed
            {
                if (CheckCollisionPointRec(mouse, bg1Button)) // If the mouse is over the background button 1
                {
                    StopMusicStream(bg2); StopMusicStream(bg3); StopMusicStream(bg4);
                    PlayMusicStream(bg1);
                    selectedMusic = 1;
                    musicEnabled  = true;
                }
                if (CheckCollisionPointRec(mouse, bg2Button))
                {
                    StopMusicStream(bg1); StopMusicStream(bg3); StopMusicStream(bg4);
                    PlayMusicStream(bg2);
                    selectedMusic = 2;
                    musicEnabled  = true;
                }
                if (CheckCollisionPointRec(mouse, bg3Button))
                {
                    StopMusicStream(bg1); StopMusicStream(bg2); StopMusicStream(bg4);
                    PlayMusicStream(bg3);
                    selectedMusic = 3;
                    musicEnabled  = true;
                }
                if (CheckCollisionPointRec(mouse, bg4Button))
                {
                    StopMusicStream(bg1); StopMusicStream(bg2); StopMusicStream(bg3);
                    PlayMusicStream(bg4);
                    selectedMusic = 4;
                    musicEnabled  = true;
                }

                if (CheckCollisionPointRec(mouse, bg5Button))
                {
                    StopMusicStream(bg1); StopMusicStream(bg2); StopMusicStream(bg3), StopMusicStream(bg4);
                    PlayMusicStream(bg5);
                    selectedMusic = 5;
                    musicEnabled  = true;
                }
                if (CheckCollisionPointRec(mouse, musicOffButton))
                {
                    StopMusicStream(bg1); StopMusicStream(bg2);
                    StopMusicStream(bg3); StopMusicStream(bg4);
                    StopMusicStream(bg5);
                    musicEnabled = false;
                }
                if (CheckCollisionPointRec(mouse, soundButton))
                {
                    soundEnabled = !soundEnabled;
                }
                if (CheckCollisionPointRec(mouse, backButton))
                {
                    showSettings = false;
                    if (musicEnabled)
                    {
                        switch (selectedMusic)
                        {
                            case 1: PlayMusicStream(bg1); break;
                            case 2: PlayMusicStream(bg2); break;
                            case 3: PlayMusicStream(bg3); break;
                            case 4: PlayMusicStream(bg4); break;
                            case 5: PlayMusicStream(bg5); break;
                        }
                    }
                }
            }
        }

        //==========================================
        // INPUT: GAME OVER BUTTONS
        //==========================================

        else if (gameOver)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (CheckCollisionPointRec(mouse, playAgainButton)) // If the mouse is over the play again button
                {
                    leftScore  = 0;
                    rightScore = 0;

                    leftPaddleY  = screenHeight / 2 - paddleHeight / 2;
                    rightPaddleY = screenHeight / 2 - paddleHeight / 2;

                    ballX      = screenWidth / 2;
                    ballY      = screenHeight / 2;
                    ballSpeedX = 6;
                    ballSpeedY = 6;

                    winnerText   = "Winner Winner Chicken Dinner";
                    gameStarted  = true;
                    gameOver     = false;
                    paused       = false;

                    if (musicEnabled) // If music is enabled, play the selected music track
                    {
                        switch (selectedMusic) // Play the selected music track
                        {
                            case 1: PlayMusicStream(bg1); break;
                            case 2: PlayMusicStream(bg2); break;
                            case 3: PlayMusicStream(bg3); break;
                            case 4: PlayMusicStream(bg4); break;
                            case 5: PlayMusicStream(bg5); break;    
                        }
                    }
                }

                if (CheckCollisionPointRec(mouse, menuButton))
                {
                    leftScore    = 0;
                    rightScore   = 0;

                    leftPaddleY  = screenHeight / 2 - paddleHeight / 2;
                    rightPaddleY = screenHeight / 2 - paddleHeight / 2;

                    ballX        = screenWidth / 2;
                    ballY        = screenHeight / 2;
                    ballSpeedX   = 6;
                    ballSpeedY   = 6;
                    winningScore = 0;
                    winnerText   = "Winner Winner Chicken Dinner";

                    gameStarted  = false;
                    gameOver     = false;
                    paused       = false;
                    showSettings = false;
                }
            }
        }

        //==========================================
        // INPUT + LOGIC: GAME
        //==========================================

        else if (gameStarted)
        {
            if (IsKeyPressed(KEY_ESCAPE))
                paused = !paused;

            if (!paused)
            {
                //------------------------------------
                // PADDLE MOVEMENT
                //------------------------------------

                if (IsKeyDown(KEY_W))      leftPaddleY  -= paddleSpeed; //  Move the left paddle up when the W key is pressed
                if (IsKeyDown(KEY_S))      leftPaddleY  += paddleSpeed; // Move the left paddle down when the S key is pressed
                if (IsKeyDown(KEY_UP))     rightPaddleY -= paddleSpeed;     // Move the right paddle up when the UP arrow key is pressed
                if (IsKeyDown(KEY_DOWN))   rightPaddleY += paddleSpeed;         // Move the right paddle down when the DOWN arrow key is pressed

                if (leftPaddleY  < 0)                      leftPaddleY  = 0; // Prevent the left paddle from going above the top of the screen
                if (leftPaddleY  > screenHeight-paddleHeight) leftPaddleY  = screenHeight - paddleHeight;
                if (rightPaddleY < 0)                      rightPaddleY = 0; // Prevent the right paddle from going above the top of the screen
                if (rightPaddleY > screenHeight-paddleHeight) rightPaddleY = screenHeight - paddleHeight;

                //------------------------------------
                // MOVE BALL
                //------------------------------------

                ballX += ballSpeedX; // Move the ball in the X direction based on its speed
                ballY += ballSpeedY; // Move the ball in the Y direction based on its speed

                //------------------------------------
                // WALL COLLISION
                //------------------------------------

                if (ballY - ballRadius <= 0) // If the ball hits the top wall
                {
                    ballY = ballRadius; // Move the ball to the top of the screen
                    ballSpeedY = -ballSpeedY; // Reverse the ball's Y direction
                    if (soundEnabled) PlaySound(wallSound); 
                }
                if (ballY + ballRadius >= screenHeight) // If the ball hits the bottom wall
                {
                    ballY = screenHeight - ballRadius; // Move the ball to the bottom of the screen
                    ballSpeedY = -ballSpeedY; // Reverse the ball's Y direction
                    if (soundEnabled) PlaySound(wallSound);
                }

                //------------------------------------
                // COLLISION SHAPES
                //------------------------------------

                Rectangle leftPaddle  = { (float)leftPaddleX,  (float)leftPaddleY,  (float)paddleWidth, (float)paddleHeight }; 
                // Create a rectangle for the left paddle
                Rectangle rightPaddle = { (float)rightPaddleX, (float)rightPaddleY, (float)paddleWidth, (float)paddleHeight };
                // Create a rectangle for the right paddle
                Vector2   ballCenter  = { (float)ballX, (float)ballY };
                //  Create a vector for the center of the ball

                //------------------------------------
                // LEFT PADDLE HIT
                //------------------------------------

                if (CheckCollisionCircleRec(ballCenter, ballRadius, leftPaddle))
                // If the ball collides with the left paddle
                {
                    ballX = leftPaddleX + paddleWidth + ballRadius; // Move the ball to the right of the left paddle
                    ballSpeedX = -ballSpeedX; // Reverse the ball's X direction
                    if (soundEnabled) PlaySound(hitSound);
                    if (ballSpeedX > 0) ballSpeedX++; else ballSpeedX--; // Increase the ball's speed in the X direction
                    if (ballSpeedY > 0) ballSpeedY++; else ballSpeedY--; // Increase the ball's speed in the Y direction
                }

                //------------------------------------
                // RIGHT PADDLE HIT
                //------------------------------------

                if (CheckCollisionCircleRec(ballCenter, ballRadius, rightPaddle))
                // If the ball collides with the right paddle
                {
                    ballX = rightPaddleX - ballRadius; // Move the ball to the left of the right paddle
                    ballSpeedX = -ballSpeedX; // Reverse the ball's X direction
                    if (soundEnabled) PlaySound(hitSound);
                    if (ballSpeedX > 0) ballSpeedX++; else ballSpeedX--; // Increase the ball's speed in the X direction
                    if (ballSpeedY > 0) ballSpeedY++; else ballSpeedY--; // Increase the ball's speed in the Y direction
                }

                //------------------------------------
                // SCORING
                //------------------------------------

                if (ballX + ballRadius < 0) // If the ball goes off the left side of the screen
                {
                    rightScore++;
                    if (soundEnabled) PlaySound(scoreSound);
                    ballX = screenWidth / 2;
                    ballY = screenHeight / 2;
                    ballSpeedX = 6;
                    ballSpeedY = 6;
                }

                if (ballX - ballRadius > screenWidth) // If the ball goes off the right side of the screen
                {
                    leftScore++;
                    if (soundEnabled) PlaySound(scoreSound);
                    ballX = screenWidth / 2;
                    ballY = screenHeight / 2;
                    ballSpeedX = -6;
                    ballSpeedY = 6;
                }

                //------------------------------------
                // WIN CHECK
                //------------------------------------

                if (leftScore >= winningScore)
                {
                    winnerText = "LEFT PLAYER WINS!";
                    if (soundEnabled) PlaySound(winSound);
                    gameStarted = false;
                    gameOver    = true;
                    paused      = false;
                }

                if (rightScore >= winningScore)
                {
                    winnerText = "RIGHT PLAYER WINS!";
                    if (soundEnabled) PlaySound(winSound);
                    gameStarted = false;
                    gameOver    = true;
                    paused      = false;
                }
            }
        }

        //=================================================
        // DRAWING
        //=================================================

        BeginDrawing();

        //--------------------------------------------------
        // DRAW: MAIN MENU
        //--------------------------------------------------

        if (!gameStarted && !gameOver && !showSettings)
        {
            ClearBackground(DARKGREEN);

            DrawText("PONG", screenWidth / 2 - 90, 60, 70, WHITE);
            DrawText("Choose Winning Score", screenWidth / 2 - 170, 150, 30, WHITE);

            Color play5Color    = CheckCollisionPointRec(mouse, play5Button)    ? GRAY : DARKGRAY;
            Color play10Color   = CheckCollisionPointRec(mouse, play10Button)   ? GRAY : DARKGRAY;
            Color play15Color   = CheckCollisionPointRec(mouse, play15Button)   ? GRAY : DARKGRAY;
            Color settingsColor = CheckCollisionPointRec(mouse, settingsButton) ? BLUE : DARKBLUE;

            DrawRectangleRec(play5Button,    play5Color);
            DrawRectangleRec(play10Button,   play10Color);
            DrawRectangleRec(play15Button,   play15Color);
            DrawRectangleRec(settingsButton, settingsColor);

            DrawRectangleLinesEx(play5Button,    3, WHITE);
            DrawRectangleLinesEx(play10Button,   3, WHITE);
            DrawRectangleLinesEx(play15Button,   3, WHITE);
            DrawRectangleLinesEx(settingsButton, 3, WHITE);

            DrawText("PLAY TO 5",  play5Button.x  + 30, play5Button.y  + 15, 30, WHITE);
            DrawText("PLAY TO 10", play10Button.x + 20, play10Button.y + 15, 30, WHITE);
            DrawText("PLAY TO 15", play15Button.x + 20, play15Button.y + 15, 30, WHITE);
            DrawText("SETTINGS",   settingsButton.x + 28, settingsButton.y + 15, 30, WHITE);
        }

        //--------------------------------------------------
        // DRAW: SETTINGS
        //--------------------------------------------------

        else if (showSettings)
        {
            ClearBackground(DARKGRAY);

            Color bg1Color      = (selectedMusic == 1 && musicEnabled) ? GREEN : DARKBLUE;
            Color bg2Color      = (selectedMusic == 2 && musicEnabled) ? GREEN : DARKBLUE;
            Color bg3Color      = (selectedMusic == 3 && musicEnabled) ? GREEN : DARKBLUE;
            Color bg4Color      = (selectedMusic == 4 && musicEnabled) ? GREEN : DARKBLUE;
            Color bg5Color      = (selectedMusic == 5 && musicEnabled) ? GREEN : DARKBLUE;
            Color musicOffColor = musicEnabled ? MAROON : RED;
            Color soundColor    = soundEnabled ? GREEN  : RED;

            DrawRectangleRec(bg1Button,      bg1Color);
            DrawRectangleRec(bg2Button,      bg2Color);
            DrawRectangleRec(bg3Button,      bg3Color);
            DrawRectangleRec(bg4Button,      bg4Color);
            DrawRectangleRec(bg5Button,      bg5Color);
         //   DrawRectangleRec(bg5Button,      bg5Color);
            DrawRectangleRec(musicOffButton, musicOffColor);
            DrawRectangleRec(soundButton,    soundColor);
            DrawRectangleRec(backButton,     GRAY);

            DrawRectangleLinesEx(bg1Button,      2, WHITE);
            DrawRectangleLinesEx(bg2Button,      2, WHITE);
            DrawRectangleLinesEx(bg3Button,      2, WHITE);
            DrawRectangleLinesEx(bg4Button,      2, WHITE);
            DrawRectangleLinesEx(bg5Button,      2, WHITE);
            DrawRectangleLinesEx(musicOffButton, 2, WHITE);

            DrawRectangleLinesEx(soundButton,    2, WHITE);
            DrawRectangleLinesEx(backButton,     2, WHITE);

            DrawText("GAME SETTINGS",         screenWidth / 2 - 190, 40, 60, YELLOW);
            DrawLine(350, 120, 930, 120, WHITE);

            DrawText("BACKGROUND MUSIC 1",    bg1Button.x + 15,      bg1Button.y + 12,      25, WHITE);
            DrawText("BACKGROUND MUSIC 2",    bg2Button.x + 15,      bg2Button.y + 12,      25, WHITE);
            DrawText("BACKGROUND MUSIC 3",    bg3Button.x + 15,      bg3Button.y + 12,      25, WHITE);
            DrawText("BACKGROUND MUSIC 4",    bg4Button.x + 15,      bg4Button.y + 12,      25, WHITE);
            DrawText("BACKGROUND MUSIC 5",    bg5Button.x + 15,      bg5Button.y + 12,      25, WHITE);
            DrawText("TURN MUSIC OFF",        musicOffButton.x + 40, musicOffButton.y + 12, 25, WHITE);
            DrawText(TextFormat("SOUND EFFECTS : %s", soundEnabled ? "ON" : "OFF"),soundButton.x + 20, soundButton.y + 12, 25, WHITE);
            DrawText("BACK",                  backButton.x + 90,     backButton.y + 12,     30, WHITE);
            DrawText("Click a music button to instantly change the background music.", 320, 685, 20, LIGHTGRAY);
        }

        //--------------------------------------------------
        // DRAW: GAME OVER
        //--------------------------------------------------

        else if (gameOver)
        {
            ClearBackground(BLACK);

            DrawText("GAME OVER", screenWidth / 2 - 180, 70, 70, RED);
            DrawText(winnerText,  screenWidth / 2 - 220, 180, 50, WHITE);
            DrawText(TextFormat("Final Score %d : %d", leftScore, rightScore), screenWidth / 2 - 120, 260, 40, YELLOW);

            DrawRectangleRec(playAgainButton, DARKGREEN);
            DrawRectangleRec(menuButton,      DARKBLUE);
            DrawRectangleLinesEx(playAgainButton, 3, WHITE);
            DrawRectangleLinesEx(menuButton,      3, WHITE);

            DrawText("PLAY AGAIN", playAgainButton.x + 20, playAgainButton.y + 18, 30, WHITE);
            DrawText("MAIN MENU",  menuButton.x + 18,      menuButton.y + 18,      30, WHITE);
        }

        //--------------------------------------------------
        // DRAW: GAME
        //--------------------------------------------------

        else
        {
            ClearBackground(GREEN);

            DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
            DrawLine(0, 0, screenWidth, 0, WHITE);
            DrawLine(0, screenHeight - 1, screenWidth, screenHeight - 1, WHITE);

            DrawRectangle(leftPaddleX,  leftPaddleY,  paddleWidth, paddleHeight, WHITE);
            DrawRectangle(rightPaddleX, rightPaddleY, paddleWidth, paddleHeight, WHITE);
            DrawCircle(ballX, ballY, ballRadius, BLUE);

            DrawText(TextFormat("%d", leftScore),  screenWidth / 4,     20, 50, WHITE);
            DrawText(TextFormat("%d", rightScore), screenWidth * 3 / 4, 20, 50, WHITE);
            DrawText(TextFormat("Playing to %d", winningScore), screenWidth / 2 - 90, 20, 25, YELLOW);

            if (paused)
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.6f));
                DrawText("PAUSED",              screenWidth / 2 - 120, screenHeight / 2 - 50, 60, WHITE);
                DrawText("Press ESC to Resume", screenWidth / 2 - 180, screenHeight / 2 + 20, 30, YELLOW);
            }
        }

        EndDrawing();
    }

    //=================================================
    // CLEANUP
    //=================================================

    StopMusicStream(bg1);
    StopMusicStream(bg2);
    StopMusicStream(bg3);
    StopMusicStream(bg4);
    StopMusicStream(bg5);

    UnloadMusicStream(bg1);
    UnloadMusicStream(bg2);
    UnloadMusicStream(bg3);
    UnloadMusicStream(bg4);
    UnloadMusicStream(bg5);

    UnloadSound(hitSound);
    UnloadSound(wallSound);
    UnloadSound(scoreSound);
    UnloadSound(winSound);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}