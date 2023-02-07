#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "AlphaBlend.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EEvaluatorRootMotion -FallbackName=EEvaluatorRootMotion
#include "EAnimBlendTickStyle.h"
#include "EEvaluatorRootMotion.h"
#include "AblAbilityContext.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityBaseScratchPad;
class UAblAbilityChannelingScratchPad;
class UAblAbilityComponent;
class UAblAbilityEventScratchPad;
class UAblAbilityTaskScratchPad;

UCLASS(Blueprintable)
class ABLECORE_API UAblAbilityContext : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAblAbility* m_Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* m_AbilityComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 m_StackCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float m_CurrentTime;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> m_Owner;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> m_Instigator;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> m_TargetActors;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint32, UAblAbilityTaskScratchPad*> m_TaskScratchPadMap;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint32, UAblAbilityEventScratchPad*> m_EventScratchPadMap;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint32, UAblAbilityChannelingScratchPad*> m_ChannelingScratchPadMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform m_AsyncQueryTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_TransitionBlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAlphaBlend m_TransitionBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityBaseScratchPad* AbilityScratchPad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> m_UseSourceRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEvaluatorRootMotion::Type> m_UseDestRootMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EAnimBlendTickStyle m_BlendTickStyle;
    
public:
    UAblAbilityContext();
    UFUNCTION(BlueprintCallable)
    void SetStackCount(int32 Stack);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetTargetActors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetSelfActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAblAbilityComponent* GetSelfAbilityComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetOwner() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInstigator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentTimeRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentStackCount() const;
    
};

