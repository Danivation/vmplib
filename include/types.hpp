#pragma once
struct Point {
    float x, y;
};

struct Pose {
    float x, y, theta;
};

struct Velocities {
    float linear, angular;
};

struct VelocityLayout {
    float linear, angular, time;
};

struct VelocityPoseLayout {
    VelocityLayout velocity;
    Pose pose;
};

struct KeyframeVelocities {
    float velocity, time;
};

struct KeyframeVelocitiesXandY {
    float x, y, velocity;
};
