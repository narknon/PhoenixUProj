#pragma once
#include "CoreMinimal.h"
#include "AblAbilityNetworkContext.generated.h"

class AActor;
class UAblAbility;
class UAblAbilityComponent;

USTRUCT(BlueprintType)
struct ABLECORE_API FAblAbilityNetworkContext {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAblAbility> m_Ability;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAblAbilityComponent> m_AbilityComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> m_Owner;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> m_Instigator;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> m_TargetActors;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 m_CurrentStacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_TimeStamp;
    
public:
    FAblAbilityNetworkContext();
};

