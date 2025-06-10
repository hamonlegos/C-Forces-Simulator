#include <raylib.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "ball gravity sim");

    Vector2 ballpos = {400.f, 400.f};
    int mass = 40;
    Vector2 tforces = {};
    float time;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {

        time += 1 / 60;

        BeginDrawing();
            DrawCircleV(ballpos, 35.f, GREEN);
            ClearBackground(DARKGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}