#include "NPC_OptimizationSettings.h"

FNPC_OptimizationSettings::FNPC_OptimizationSettings() {
    this->NonCAnimationTickDist = 0.00f;
    this->CAnimationTickDist = 0.00f;
    this->NonCShutdownDist = 0.00f;
    this->CShutdownMinDist = 0.00f;
    this->CShutdownDist = 0.00f;
    this->NonCRenderedShutdown = 0.00f;
    this->CNotRenderedShutdownNear = 0.00f;
    this->CNotRenderedShutdownFar = 0.00f;
    this->ShutdownMaxDist = 0.00f;
    this->RenderMaxDist = 0.00f;
}

