#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MountViewDistanceLimiter.generated.h"

class UCameraHeightWithCullingRenderSettingsComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMountViewDistanceLimiter : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraHeightWithCullingRenderSettingsComponent* CameraHeightRenderSettingsComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFogOnOffValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FogOnOffInterpSpeed;
    
public:
    UMountViewDistanceLimiter();
};

