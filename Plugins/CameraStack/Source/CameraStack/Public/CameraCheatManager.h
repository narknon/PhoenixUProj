#pragma once
#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "CameraCheatManager.generated.h"

UCLASS(Blueprintable)
class CAMERASTACK_API UCameraCheatManager : public UCheatManager {
    GENERATED_BODY()
public:
    UCameraCheatManager();
};

