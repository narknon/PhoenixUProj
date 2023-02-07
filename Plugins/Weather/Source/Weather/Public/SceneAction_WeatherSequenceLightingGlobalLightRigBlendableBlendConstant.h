#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceLightingGlobalLightRigBlendable.h"
#include "SceneAction_WeatherSequenceLightingGlobalLightRigBlendableBlendConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingGlobalLightRigBlendableBlendConstant : public USceneAction_WeatherSequenceLightingGlobalLightRigBlendable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    USceneAction_WeatherSequenceLightingGlobalLightRigBlendableBlendConstant();
};

