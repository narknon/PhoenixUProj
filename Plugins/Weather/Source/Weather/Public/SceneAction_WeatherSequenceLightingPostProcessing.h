#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "BlendDomain.h"
#include "SceneAction_WeatherSequenceLightingPostProcessingBase.h"
#include "SceneAction_WeatherSequenceLightingPostProcessing.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceLightingPostProcessing : public USceneAction_WeatherSequenceLightingPostProcessingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    USceneAction_WeatherSequenceLightingPostProcessing();
};

