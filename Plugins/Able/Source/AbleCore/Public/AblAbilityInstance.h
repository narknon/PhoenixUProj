#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblAbilityInstance.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityContext;
class UAblAbilityTask;

UCLASS(Blueprintable, Transient)
class ABLECORE_API UAblAbilityInstance : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 m_CurrentIteration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_AsyncTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_ActiveAsyncTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_FinishedASyncTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_SyncTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_ActiveSyncTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_FinishedSyncTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAblAbility* m_Ability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityContext* m_Context;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> m_AdditionalTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAblAbilityTask*> m_FadingTasks;
    
public:
    UAblAbilityInstance();
};

