#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LerpVolumesInterpolantPCs.h"
#include "LerpVolumesVector.generated.h"

USTRUCT(BlueprintType)
struct FLerpVolumesVector : public FLerpVolumesInterpolantPCs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Value;
    
    LERPVOLUMES_API FLerpVolumesVector();
};

