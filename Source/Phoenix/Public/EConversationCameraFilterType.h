#pragma once
#include "CoreMinimal.h"
#include "EConversationCameraFilterType.generated.h"

UENUM(BlueprintType)
enum class EConversationCameraFilterType : uint8 {
    Disable,
    FirstConversationCameraShot,
    LastConversationCameraShot,
    EndingCameraShotWithChoices,
    EndingCameraShotBeforeEmbedded,
    CameraShotDuringPause,
    AllCameraShots,
};

