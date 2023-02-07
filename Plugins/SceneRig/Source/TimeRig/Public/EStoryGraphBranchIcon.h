#pragma once
#include "CoreMinimal.h"
#include "EStoryGraphBranchIcon.generated.h"

UENUM()
enum class EStoryGraphBranchIcon : int32 {
    None,
    Info,
    InfoHub,
    Straight,
    Special,
    BackTo,
    Exit,
    MainMission,
    SideMission,
    Assignment,
    Conversation,
    Vendor,
};

