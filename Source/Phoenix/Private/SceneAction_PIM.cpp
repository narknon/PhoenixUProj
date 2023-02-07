#include "SceneAction_PIM.h"

USceneAction_PIM::USceneAction_PIM() {
    this->PIMType = EPIMTypes::PressAccept;
    this->bHasFailureTimeout = true;
    this->FailureTimeout = 0.00f;
    this->JoystickSuccessTime = 0.00f;
    this->AnimationRotationRate = 1.00f;
    this->SuccessDecayRate = 0.00f;
    this->bPlayVOHint = false;
    this->HintDelay = 5.00f;
    this->DelayAfterCompletion = 0.00f;
    this->bMapPIMProgressToParameter = false;
    this->DisplayModifierFirst = true;
    this->FeedBackAnimType = EFeedbackAnim::ANIM_PULSE;
    this->HorizontalAlignment = HAlign_Center;
    this->VerticalAlignment = VAlign_Bottom;
    this->TelescopeInFocusDistance = 0.00f;
    this->TelescopeBlurryDistance = 0.00f;
    this->TelescopeInFocusWindow = 0.00f;
    this->TelescopeFullTravelTime = 0.00f;
    this->PIMFX = NULL;
    this->EndPIMFX = NULL;
}

