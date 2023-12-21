#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if(argc != 4) {
    printf("Format: main $length$ $initial_angle_in_deg$ $initial_angular_vel_in_deg_s^-1$\n");
    return 1;
  }

  InitWindow(1280, 720, "Simple pendulum sim");

  SetTargetFPS(144);

  double l = atof(argv[1]);
  double theta = (atof(argv[2])*PI)/180.f;
  double theta_dot = (atof(argv[3])*PI)/180.f;

  while (!WindowShouldClose()) {
    double dt = GetFrameTime()/2;

    double w = GetScreenWidth();
    double h = GetScreenHeight();

    double theta2dot = (- 9.8 / l) * sinf(theta);

    theta_dot += theta2dot*dt;
    theta += theta_dot*dt;

    Vector2 origin = {w/2, 0};

    Vector2 end = {l * sinf(theta), l * cosf(theta)};
    end.x *= 1000.f;
    end.y *= 1000.f;
    end.x += origin.x;
    end.y += origin.y;

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawLineV(origin, end, BLACK);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
