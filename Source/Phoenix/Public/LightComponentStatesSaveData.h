#pragma once
#include "CoreMinimal.h"
#include "LightComponentStatesSaveData.generated.h"

class ULightComponentStateData;

USTRUCT(BlueprintType)
struct FLightComponentStatesSaveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ULightComponentStateData*> Data;
    
    PHOENIX_API FLightComponentStatesSaveData();
};

