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
    float dist;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        DrawFPS(0,0);

        tforces.y += gforce.y + pullforce.y;
        tforces.x += gforce.x + pullforce.x;

        if (ballpos.y >= screenHeight - 34.f) {
            ballpos.y -= 1.5f;
            tforces.y *= -1.f * 0.60f;
        }
        if (ballpos.x >= screenWidth - 34.f) {
            ballpos.x -= 1.5f;
            tforces.x *= -1.f * 0.60f;
        }
        if (ballpos.y <= 36.f) {
            ballpos.y += 1.5f;
            tforces.y *= -1.f * 0.60f;
        }
        if (ballpos.x <= 36.f) {
            ballpos.x += 1.5f;
            tforces.x *= -1.f * 0.60f;
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            mousepos = GetMousePosition();
            dist = sqrt(pow((ballpos.x - mousepos.x),2) +pow((ballpos.y - mousepos.y),2)) / 2;
            DrawLine(ballpos.x, ballpos.y, mousepos.x, mousepos.y, WHITE);
            printf("%f\n",dist);

            if (ballpos.x > mousepos.x) {
                tforces.x -= dist * 0.4;
            } else {
                tforces.x += dist * 0.4;
            }

            if (ballpos.y > mousepos.y) {
                tforces.y -= dist * 0.4;
            } else {
                tforces.y += dist * 0.4;
            }
        }

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