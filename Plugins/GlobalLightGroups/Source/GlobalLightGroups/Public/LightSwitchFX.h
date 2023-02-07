#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "LightSwitchFX.generated.h"

class UAkAudioEvent;
class UNiagaraSystem;
class USceneComponent;

USTRUCT(BlueprintType)
struct FLightSwitchFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* SoundFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USceneComponent> AttachComponent;
    
    GLOBALLIGHTGROUPS_API FLightSwitchFX();
};

