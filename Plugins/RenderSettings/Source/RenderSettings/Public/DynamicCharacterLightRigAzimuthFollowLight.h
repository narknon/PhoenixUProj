#pragma once
#include "CoreMinimal.h"
#include "DynamicCharacterLightRigAzimuthFollowLight.generated.h"

USTRUCT(BlueprintType)
struct FDynamicCharacterLightRigAzimuthFollowLight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AzimuthOffset;
    
    RENDERSETTINGS_API FDynamicCharacterLightRigAzimuthFollowLight();
};

