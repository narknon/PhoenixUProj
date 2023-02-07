#pragma once
#include "CoreMinimal.h"
#include "ERagdollSensoryRangeValueEnum.generated.h"

UENUM(BlueprintType)
enum class ERagdollSensoryRangeValueEnum : uint8 {
    RSRVE_HeightAboveGround,
    RSRVE_Velocity,
    RSRVE_HorizontalVelocity,
    RSRVE_VerticalVelocity,
    RSRVE_TotalTimeRagdolling,
    RSRVE_TimeOnGround,
    RSRVE_TimeInAir,
    RSRVE_TimeHovering,
    RSRVE_TimeGetupObstructed,
    RSRVE_TimeInCurBehavior,
    RSRVE_TimeDead,
    RSRVE_TimeToImminentCollision,
    RSRVE_TimeInCurAudioBehavior,
    RSRVE_LastNavmeshSeperation,
    RSRVE_MAX UMETA(Hidden),
};

