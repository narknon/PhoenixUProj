#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AvaMotionWarpingSyncPoint.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FAvaMotionWarpingSyncPoint {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuat Rotation;
    
public:
    FAvaMotionWarpingSyncPoint();
};

