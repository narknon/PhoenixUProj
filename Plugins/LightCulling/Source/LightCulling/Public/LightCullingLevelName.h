#pragma once
#include "CoreMinimal.h"
#include "LightCullingLevelName.generated.h"

USTRUCT(BlueprintType)
struct FLightCullingLevelName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    LIGHTCULLING_API FLightCullingLevelName();
};

