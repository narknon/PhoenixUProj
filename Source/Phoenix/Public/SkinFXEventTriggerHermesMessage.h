#pragma once
#include "CoreMinimal.h"
#include "ESkinFXDelegateEvent.h"
#include "SkinFXEventTriggerHermesMessage.generated.h"

class USkinFXComponent;

USTRUCT(BlueprintType)
struct FSkinFXEventTriggerHermesMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkinFXComponent* SkinFXComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SkinFXEffectName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXDelegateEvent SkinFXEvent;
    
    PHOENIX_API FSkinFXEventTriggerHermesMessage();
};

