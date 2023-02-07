#pragma once
#include "CoreMinimal.h"
#include "SceneActionState_WeatherSequence.h"
#include "SceneActionState_WeatherSequenceNiagara.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;

UCLASS(Blueprintable)
class WEATHER_API USceneActionState_WeatherSequenceNiagara : public USceneActionState_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UNiagaraComponent*> NiagaraComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSpawned;
    
    USceneActionState_WeatherSequenceNiagara();
};

