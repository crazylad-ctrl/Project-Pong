#include "raylib.h"

int main()
{
    //Create a window that is 1280×720 and name it 'Pong'
    InitWindow(1280, 720, "Pong");

    //this redraws the screen 60 times every second.
    SetTargetFPS(60);

    //it would really be better to use GetScreenWidth and GetScreenHeight instead of hardcoding the values but this is just a simple example

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    int paddleWidth = 20;
    int paddleHeight = 120;
    int paddleSpeed = 8;

    int leftPaddleX = 20;
    int leftPaddleY = screenHeight / 2 - paddleHeight / 2;

    int rightPaddleX = screenWidth - paddleWidth - 20;
    int rightPaddleY = screenHeight / 2 - paddleHeight / 2;

    int ballRadius = 10;
    int ballX = screenWidth / 2;
    int ballY = screenHeight / 2;

    int ballSpeedX = 6;
    int ballSpeedY = 6;

    //this is the main game loop, it will keep running until the user closes the window
    while (!WindowShouldClose())
    {
        //left paddle controls
        if (IsKeyDown(KEY_W))
        {
            leftPaddleY -= paddleSpeed;
        }

        if (IsKeyDown(KEY_S))
        {
            leftPaddleY += paddleSpeed;
        }

        // Right paddle controls
        if (IsKeyDown(KEY_UP))
        {
            rightPaddleY -= paddleSpeed;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            rightPaddleY += paddleSpeed;
        }

        // Keep left paddle inside the board
        if (leftPaddleY < 0)
        {
            leftPaddleY = 0;
        }

        if (leftPaddleY > screenHeight - paddleHeight)
        {
            leftPaddleY = screenHeight - paddleHeight;
        }

        // Keep right paddle inside the board
        if (rightPaddleY < 0)
        {
            rightPaddleY = 0;
        }

        if (rightPaddleY > screenHeight - paddleHeight)
        {
            rightPaddleY = screenHeight - paddleHeight;
        }

        // Move the ball
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        // Bounce off the top wall
        if (ballY - ballRadius <= 0)
        {
            ballY = ballRadius;
            ballSpeedY = -ballSpeedY;
        }

        // Bounce off the bottom wall
        if (ballY + ballRadius >= screenHeight)
        {
            ballY = screenHeight - ballRadius;
            ballSpeedY = -ballSpeedY;
        }

        //this makes our canvas green
        BeginDrawing();

        ClearBackground(GREEN);

        // this is just making us draw a centre line
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

        // Draw top boundary
        DrawLine(0, 0, screenWidth, 0, WHITE);

        // Draw bottom boundary
        DrawLine(0, screenHeight - 1, screenWidth, screenHeight - 1, WHITE);

        // Draw left paddle
        DrawRectangle(leftPaddleX, leftPaddleY, paddleWidth, paddleHeight, WHITE);

        // Draw right paddle
        DrawRectangle(rightPaddleX, rightPaddleY, paddleWidth, paddleHeight, WHITE);

        // Draw ball
        DrawCircle(ballX, ballY, ballRadius, BLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}