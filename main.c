//learning matrix transformations in 3D space with raylib 
/*
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

int main(void)
{
    InitWindow(1000, 650, "My First 3D Game");

    SetTargetFPS(60);

    Camera3D camera = {0};
    camera.position = (Vector3){5.0f, 5.0f, 5.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while (!WindowShouldClose())
    {
        static float rotation = 0.0f;
        rotation += 0.5f;
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        rlPushMatrix();

        rlRotatef(rotation, 0, 1, 0);

        DrawCube(
            (Vector3){0, 0, 0},
            2, 2, 2,
            RED);

        DrawCubeWires(
            (Vector3){0, 0, 0},
            2, 2, 2,
            MAROON);

        rlPopMatrix();
        EndMode3D();

        DrawText("MY FIRST 3D WORLD!", 20, 20, 25, DARKGRAY);
        DrawText("Welcome to game development mee :D", 20, 55, 18, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
*/
//now this section is making the camera orbit around the cube 
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

int main(void)
{
    InitWindow(1000, 650, "My First 3D Game");

    SetTargetFPS(60);

    Camera3D camera = {0};
    camera.position = (Vector3){5.0f, 5.0f, 5.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    

    while (!WindowShouldClose())
    {
        static float rotation = 0.0f;
        rotation += 0.5f;
        UpdateCamera(&camera, CAMERA_ORBITAL);
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        rlPushMatrix();

        rlRotatef(rotation, 0, 1, 0);

        DrawCube(
            (Vector3){0, 0, 0},
            2, 2, 2,
            RED);

        DrawCubeWires(
            (Vector3){0, 0, 0},
            2, 2, 2,
            MAROON);

        rlPopMatrix();
        EndMode3D();

        DrawText("MY FIRST 3D WORLD!", 20, 20, 25, DARKGRAY);
        DrawText("Welcome to game development mee :D", 20, 55, 18, GRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}