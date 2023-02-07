#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsMask.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsMask {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 Mask;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsMask();
};

