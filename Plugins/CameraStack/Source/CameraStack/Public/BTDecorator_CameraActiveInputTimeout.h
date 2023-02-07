#pragma once
#include "CoreMinimal.h"
#include "BTDecorator_CameraInputTimeout.h"
#include "BTDecorator_CameraActiveInputTimeout.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_CameraActiveInputTimeout : public UBTDecorator_CameraInputTimeout {
    GENERATED_BODY()
public:
    UBTDecorator_CameraActiveInputTimeout();
};

