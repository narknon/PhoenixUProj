#pragma once
#include "CoreMinimal.h"
#include "Interfaces/Interface_PostProcessVolume.h"
#include "Engine/Scene.h"
#include "SceneActionState_WeatherSequenceLightingBase.h"
#include "SceneActionState_WeatherSequenceLightingPostProcessing.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceLightingPostProcessing : public USceneActionState_WeatherSequenceLightingBase/*, public IInterface_PostProcessVolume*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPostProcessSettings CachedPostProcessSettings;
    
    USceneActionState_WeatherSequenceLightingPostProcessing();
    
    // Fix for true pure virtual functions not being implemented
};

