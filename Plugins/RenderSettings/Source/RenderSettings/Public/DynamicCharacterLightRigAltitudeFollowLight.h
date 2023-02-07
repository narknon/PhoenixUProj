#pragma once
#include "CoreMinimal.h"
#include "DynamicCharacterLightRigAltitudeFollowLight.generated.h"

USTRUCT(BlueprintType)
struct FDynamicCharacterLightRigAltitudeFollowLight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AltitudeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinAltitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAltitude;
    
    RENDERSETTINGS_API FDynamicCharacterLightRigAltitudeFollowLight();
};

