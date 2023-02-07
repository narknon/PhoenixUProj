#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TimeSourceScrubbableControlBase.generated.h"

UCLASS(Abstract, Blueprintable)
class DAYNIGHT_API UTimeSourceScrubbableControlBase : public UDataAsset {
    GENERATED_BODY()
public:
    UTimeSourceScrubbableControlBase();
};

