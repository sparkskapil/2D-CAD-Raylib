#include "View.h"
const int screenWidth = 1024;
const int screenHeight = 600;

    
void View::Setup()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "RayLib Example");
    
    camera = { 0 };
    camera.target = (Vector2){ 0, 0 };
    //camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    ClearBackground(DARKGRAY);
}


void View::Draw()
{    
    BeginDrawing();
    
    // Camera zoom controls
    camera.target= GetMousePosition();
    camera.zoom += ((float)GetMouseWheelMove()*0.05f);
    if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    else if (camera.zoom < 0.1f) camera.zoom = 0.1f;
    
    BeginMode2D(camera);
    if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
    { 
        auto mousePosition = GetMousePosition();
        DrawCircle(mousePosition.x,mousePosition.y, 2*1/camera.zoom, RED);
        //DrawRectangle(mousePosition.x, mousePosition.y, screenWidth, 5, RED);
    }
    EndMode2D();
    EndDrawing();
}

View::~View()
{
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
}