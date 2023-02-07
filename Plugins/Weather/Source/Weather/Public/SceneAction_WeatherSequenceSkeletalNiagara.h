#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersPrimFilter.h"
#include "NiagaraSystemSpawnMultiSkeletalInfo.h"
#include "SceneAction_WeatherSequenceNiagara.h"
#include "SceneAction_WeatherSequenceSkeletalNiagara.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceSkeletalNiagara : public USceneAction_WeatherSequenceNiagara {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraSystemSpawnMultiSkeletalInfo SpawnInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersPrimFilter Filter;
    
    USceneAction_WeatherSequenceSkeletalNiagara();
};

