#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LerpVolumesInterpolantPCs.h"
#include "LerpVolumesUnitDirection.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesUnitDirection : public FLerpVolumesInterpolantPCs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Value;
    
    LERPVOLUMES_API FLerpVolumesUnitDirection();
};

