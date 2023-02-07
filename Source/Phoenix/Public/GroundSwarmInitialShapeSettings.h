#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmInitialShapeSettings.generated.h"

USTRUCT(BlueprintType)
struct FGroundSwarmInitialShapeSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RandomConeHalfAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRefreshOnBeginPlay;
    
    PHOENIX_API FGroundSwarmInitialShapeSettings();
};

