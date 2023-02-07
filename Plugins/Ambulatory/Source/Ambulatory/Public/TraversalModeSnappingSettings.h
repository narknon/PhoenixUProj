#pragma once
#include "CoreMinimal.h"
#include "TraversalModeSnappingSettings.generated.h"

USTRUCT(BlueprintType)
struct AMBULATORY_API FTraversalModeSnappingSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHorizontalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHorizontalDistanceNoInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTimeToLedge;
    
    FTraversalModeSnappingSettings();
};

