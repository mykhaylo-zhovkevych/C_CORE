#include <raylib.h>
#include <math.h>

#define WIDTH 900
#define HEIGHT 600

#define BRANCH_COLOR RAYWHITE
#define STARTING_THICKNESS 20
#define BRANCH_OFF_ANGLE 20*DEG2RAD
#define GENERATION_LIMIT 20

void DrawBranch(float x, float y, float length, float angle, float thickness) 
{
    if (length <= 1) 
    {
        return;
    }

    Vector2 start = { x, y };

    // new x,y with angle offset
    float x_end = x + sinf(angle) * length;
    float y_end = y - cosf(angle) * length;
    Vector2 end = { x_end, y_end };

    DrawLineEx(start, end, thickness, RED);    

    float new_length = length * 0.7f;
    float new_right_angle = angle + BRANCH_OFF_ANGLE;
    float new_left_angle = angle - BRANCH_OFF_ANGLE;
    float new_thickness = thickness * 0.7f;
    DrawBranch(x_end, y_end, new_length, new_right_angle, new_thickness);
    DrawBranch(x_end, y_end, new_length, new_left_angle, new_thickness);

}

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Fractal Canopy");

    SetTargetFPS(1);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawBranch(WIDTH / 2, HEIGHT-20, 150, 0, 20);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}