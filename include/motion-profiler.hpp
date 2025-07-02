#pragma once

#include <string>
#include <vector>
#include "types.hpp"

extern const float MAX_VELOCITY;
extern const float MAX_ACCEL;
extern const float TRACK_WIDTH;
extern const float RAMSETE_B;
extern const float RAMSETE_ZETA;
extern const float DT;

extern const float in_to_m;

// Forward‐declare the conversion routine you already have in your code:
//   It takes a spline’s control points and a list of (x,y,velocity) keyframes,
//   and returns a vector of (time, scalar-velocity) keyframes.
// Your original code presumably implemented this as:
//   std::vector<KeyframeVelocities> convertToTFrame(
//       const std::vector<Point>& controlPts,
//       const std::vector<KeyframeVelocitiesXandY>& initList
//   );
std::vector<KeyframeVelocities>
convertToTFrame(
    const std::vector<Point>&,
    const std::vector<KeyframeVelocitiesXandY>&
);

// Exactly the same signature as before.  Internally, this will:
//  1) call convertToTFrame(…) if useKeyFrames==true,
//  2) build a TrapezoidalProfile,
//  3) print its open-loop poses & velocities,
//  4) run a RAMSETE follower over that path,
//  5) print the closed-loop poses & velocities.
//
// Example usage remains unchanged:
//   printVels(controlPoints, keyFrameVelocityList, false);
std::vector<std::vector<VelocityLayout>> printVels(
    const std::vector<std::vector<Point>>& controlPoints,
    const std::vector<std::vector<KeyframeVelocitiesXandY>>& keyFrameVelocityInitList,
    bool useKeyFrames
);
