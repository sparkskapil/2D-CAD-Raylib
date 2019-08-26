#include "View.h"

int main(void)
{
    View view;
    view.Setup();
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
       view.Draw();
    }
    
    return 0;
}