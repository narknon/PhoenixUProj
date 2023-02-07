#pragma once
#include "CoreMinimal.h"
#include "BlendDomain.h"
#include "SceneAction_WeatherSequenceLightingBase.h"
#include "SceneAction_WeatherSequenceLightingGlobalLightRigBlendable.generated.h"

class UGlobalLightingBlendable;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingGlobalLightRigBlendable : public USceneAction_WeatherSequenceLightingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendable* GlobalLightingBlendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PostSequenceLifetime;
    
    USceneAction_WeatherSequenceLightingGlobalLightRigBlendable();
};

