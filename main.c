#include <raylib.h>
#include <stdio.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "ball gravity sim");

    Vector2 ballpos = {400.f, 400.f};
    int mass = 4;
    Vector2 gforce = {mass*9.8f, mass*9.8f};
    Vector2 pullforce = {};
    Vector2 tforces = {};
    float time = 0.f;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {

        tforces.y += gforce.y + pullforce.y;
        tforces.y += gforce.x + pullforce.x;

        if (ballpos.y >= screenHeight - 35.f || ballpos.y <= 35.f) {
            ballpos.y -= 2.f;
            tforces.y *= -1.f * 0.80f;
        }

        if (ballpos.x >= screenWidth - 35.f || ballpos.x <= 35.f) {
            ballpos.x -= 2.f;
            tforces.x *= -1.f * 0.80f;
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 pos = GetMousePosition();
        }

        ballpos.y += tforces.y / 60.f;

        BeginDrawing();
            DrawCircleV(ballpos, 35.f, GREEN);
            ClearBackground(DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}