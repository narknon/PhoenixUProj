#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsMask.h"
#include "GlobalLightGroupsMaskLock.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsMaskLock {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMask LockedOnMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsMask LockedOffMask;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsMaskLock();
};

