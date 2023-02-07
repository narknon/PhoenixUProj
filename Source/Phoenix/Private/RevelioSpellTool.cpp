#include "RevelioSpellTool.h"

class AActor;

void ARevelioSpellTool::RevealHiddenActor(AActor* InActor) {
}

float ARevelioSpellTool::GetHiddenObjectRange() const {
    return 0.0f;
}

float ARevelioSpellTool::GetFieldGuideHotspotRange() const {
    return 0.0f;
}

float ARevelioSpellTool::GetCurrentOuterRadius() const {
    return 0.0f;
}

float ARevelioSpellTool::GetCurrentInnerRadius() const {
    return 0.0f;
}

void ARevelioSpellTool::BeginRevealFade() {
}

ARevelioSpellTool::ARevelioSpellTool() {
    this->FadeTime = 1.00f;
    this->MaxRevealsPerFrame = 5;
    this->bRevealHiddenOnCastOnly = true;
    this->StandardRange = 3000.00f;
    this->StandardRadiusPercentAtTime = NULL;
    this->HogwartsRange = 3000.00f;
    this->HogwartsRadiusPercentAtTime = NULL;
    this->OverlandRange = 8000.00f;
    this->OverlandRadiusPercentAtTime = NULL;
    this->BroomRange = 16000.00f;
    this->BroomFieldGuideHotspotRange = 64000.00f;
    this->BroomRadiusPercentAtTime = NULL;
    this->HiddenObjectRange = 1000.00f;
    this->IntroHiddenObjectRange = 500.00f;
    this->BaseRangeScale = 0.65f;
    this->ShowOccludedParameter = TEXT("ShowOccluded");
    this->CurrentRadius = 0.00f;
    this->CurrentInnerRadius = 0.00f;
    this->IgnoreActorArray.AddDefaulted(1000);
    this->HotspotArray.AddDefaulted(100);
}

