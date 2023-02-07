#include "FluidSimParams.h"

FFluidSimParams::FFluidSimParams() {
    this->Enabled = false;
    this->DrawDebugBounds = false;
    this->Optimize = false;
    this->OptimizationThreshold = 0.00f;
    this->ColorCurve = NULL;
    this->ColorCurveScale = 0.00f;
    this->ColorIntensity = 0.00f;
    this->FadeEdges = false;
    this->LocalSpaceBuoyancyGravity = false;
    this->MotionVectorStrength = 0.00f;
    this->VolumeMotion = false;
    this->VelocityDissipation = 0.00f;
    this->SourceDissipation = 0.00f;
    this->Vorticity = 0.00f;
    this->VorticityTrails = 0.00f;
    this->TimeStep = 0.00f;
    this->iterations = 0;
    this->Density = 0.00f;
    this->SlowLighting = false;
    this->EdgeFadeScale = 0.00f;
    this->EdgeFadeBias = 0.00f;
}

