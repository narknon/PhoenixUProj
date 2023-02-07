#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LerpVolumesInterpolantPCs.h"
#include "LerpVolumesColor.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesColor : public FLerpVolumesInterpolantPCs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    LERPVOLUMES_API FLerpVolumesColor();
};

