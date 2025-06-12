#include <raylib.h>
#include <stdio.h>
#include <math.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "ball gravity sim");

    Vector2 ballpos = {400.f, 400.f};
    int mass = 4; //kg
    Vector2 gforce = {0.f, mass*9.8f};
    Vector2 pullforce = {};
    Vector2 tforces = {};
    Vector2 mousepos = {};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        DrawFPS(0,0);

        if (ballpos.y > screenHeight - 35.f) {
            ballpos.y = screenHeight - 35.f;
            tforces.y *= -1.f * 0.60f;
        }
        if (ballpos.x > screenWidth - 35.f) {
            ballpos.x = screenWidth - 35.f;
            tforces.x *= -1.f * 0.60f;
        }
        if (ballpos.y < 35.f) {
            ballpos.y = 35.f;
            tforces.y *= -1.f * 0.60f;
        }
        if (ballpos.x < 35.f) {
            ballpos.x = 35.f;
            tforces.x *= -1.f * 0.60f;
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            mousepos = GetMousePosition();
            float dist = sqrt(pow((ballpos.x - mousepos.x),2) +pow((ballpos.y - mousepos.y),2)) * 0.2f;
            DrawLine(ballpos.x, ballpos.y, mousepos.x, mousepos.y, RED);

            if (ballpos.x > mousepos.x) {
                tforces.x -= dist;
            } else {
                tforces.x += dist;
            }

            if (ballpos.y > mousepos.y) {
                tforces.y -= dist;
            } else {
                tforces.y += dist;
            }
            
            DrawLineV(ballpos,tforces, BLUE);

        }

        tforces.y += gforce.y;
        tforces.x += gforce.x;

        ballpos.y += tforces.y / 60.f;
        ballpos.x += tforces.x / 60.f;

        BeginDrawing();
            DrawLine(ballpos.x, ballpos.y, ballpos.x, screenHeight, WHITE);
            DrawCircleV(ballpos, 35.f, GREEN);
            ClearBackground(DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}