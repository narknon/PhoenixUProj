#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EGameEvent_Intensity.h"
#include "MultiFX.h"
#include "RPGTriggerEffect_Base.h"
#include "RPGTriggerEffect_BroadcastAIEvent.generated.h"

class AActor;
class UMultiFX2_Base;

UCLASS(Blueprintable, EditInlineNew)
class URPGTriggerEffect_BroadcastAIEvent : public URPGTriggerEffect_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer EventTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameEvent_Intensity EventIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFX TriggerFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> TriggerFX2;
    
public:
    URPGTriggerEffect_BroadcastAIEvent();
};

