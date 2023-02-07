#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "WindVolumeInterface.h"
#include "SceneActionState_WeatherLocalWind.generated.h"

UCLASS(Blueprintable)
class USceneActionState_WeatherLocalWind : public USceneRigActionState, public IWindVolumeInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Now;
    
    USceneActionState_WeatherLocalWind();
    
    // Fix for true pure virtual functions not being implemented
};

