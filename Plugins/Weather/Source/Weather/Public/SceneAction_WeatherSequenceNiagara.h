#pragma once
#include "CoreMinimal.h"
#include "SceneAction_WeatherSequence.h"
#include "SceneAction_WeatherSequenceNiagara.generated.h"

class UNiagaraSystem;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceNiagara : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> NiagaraSystemAsset;
    
    USceneAction_WeatherSequenceNiagara();
};

