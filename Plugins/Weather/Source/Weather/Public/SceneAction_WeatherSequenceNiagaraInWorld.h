#pragma once
#include "CoreMinimal.h"
#include "NiagaraSystemSpawnInfo.h"
#include "SceneAction_WeatherSequenceNiagara.h"
#include "SceneAction_WeatherSequenceNiagaraInWorld.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceNiagaraInWorld : public USceneAction_WeatherSequenceNiagara {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* Transform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraSystemSpawnInfo SpawnInfo;
    
    USceneAction_WeatherSequenceNiagaraInWorld();
};

