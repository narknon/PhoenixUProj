#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LerpVolumesPresistentContextDataBase.generated.h"

UCLASS(Abstract, Blueprintable)
class LERPVOLUMES_API ULerpVolumesPresistentContextDataBase : public UObject {
    GENERATED_BODY()
public:
    ULerpVolumesPresistentContextDataBase();
};

