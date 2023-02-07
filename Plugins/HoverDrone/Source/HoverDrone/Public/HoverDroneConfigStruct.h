#pragma once
#include "CoreMinimal.h"
#include "HoverDroneConfigStruct.generated.h"

USTRUCT(BlueprintType)
struct FHoverDroneConfigStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TestString;
    
    HOVERDRONE_API FHoverDroneConfigStruct();
};

