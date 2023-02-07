#pragma once
#include "CoreMinimal.h"
#include "NiagaraSystemSpawnAttachedPointInfo.h"
#include "SceneAction_WeatherSequenceNiagara.h"
#include "SceneAction_WeatherSequenceNiagaraAttached.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceNiagaraAttached : public USceneAction_WeatherSequenceNiagara {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraSystemSpawnAttachedPointInfo SpawnInfo;
    
    USceneAction_WeatherSequenceNiagaraAttached();
};

