#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableInterface.h"
#include "SceneActionState_WeatherSequenceLightingBase.h"
#include "SceneActionState_WeatherSequenceLightingGlobalLightRigBlendable.generated.h"

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceLightingGlobalLightRigBlendable : public USceneActionState_WeatherSequenceLightingBase, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
    USceneActionState_WeatherSequenceLightingGlobalLightRigBlendable();
    
    // Fix for true pure virtual functions not being implemented
};

