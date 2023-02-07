#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_CameraBase.generated.h"

UCLASS(Abstract, Blueprintable)
class UBTService_CameraBase : public UBTService {
    GENERATED_BODY()
public:
    UBTService_CameraBase();
};

