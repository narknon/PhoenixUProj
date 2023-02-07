#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequenceNiagaraAttached.h"
#include "SceneAction_WeatherSequenceCameraNiagara.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceCameraNiagara : public USceneAction_WeatherSequenceNiagaraAttached {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SetOutdoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetOutdoorsValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHideIndoors;
    
    USceneAction_WeatherSequenceCameraNiagara();
};

