#include "raylib.h"

#define WIDTH 858
#define HEIGHT 525

Rectangle player1 = {
        .width = 30,
        .height = 100,
        .x = 0 + 20,
        .y = (HEIGHT/2.0f) - 100/2.0f,
};

Rectangle player2 = {
        .width = 30,
        .height = 100,
        .x = (WIDTH - 30) - 20,
        .y = (HEIGHT/2.0f) - 100/2.0f,
};

void game(void);
void movement();

float DELTATIME = 0;
int main()
{

        InitWindow(WIDTH, HEIGHT, "pong!");
        SetTargetFPS(30);

        while (!WindowShouldClose())
        {
                DELTATIME = GetFrameTime();
                ClearBackground(BLACK);
                BeginDrawing();
                game();
                EndDrawing();
        }
        CloseWindow();
        return 0;
}

void game(void)
{
        DrawRectangleRec(player1, WHITE);
        DrawRectangleRec(player2, ORANGE);
        movement();
}

void movement()
{
        int x1 = (int) IsKeyDown(KEY_W) - (int) IsKeyDown(KEY_S);
        int x2 = (int) IsKeyDown(KEY_UP) - (int) IsKeyDown(KEY_DOWN);

        if (x1 > 0)
                player1.y -= 200 * DELTATIME;

        if (x1 < 0)
                player1.y +=  200 * DELTATIME;

        if (x2 > 0)
                player2.y -= 200 * DELTATIME;

        if (x2 < 0)
                player2.y +=  200 * DELTATIME;
}
