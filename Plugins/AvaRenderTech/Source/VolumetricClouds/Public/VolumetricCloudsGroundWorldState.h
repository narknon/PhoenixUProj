#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VolumetricCloudsGroundShadowsState.h"
#include "VolumetricCloudsGroundWorldState.generated.h"

class UTexture2DAlias;

UCLASS(Blueprintable, Transient)
class UVolumetricCloudsGroundWorldState : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FVolumetricCloudsGroundShadowsState> ShadowedLights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture2DAlias* ShadowAlias;
    
public:
    UVolumetricCloudsGroundWorldState();
};

