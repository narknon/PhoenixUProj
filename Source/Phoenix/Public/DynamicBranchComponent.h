#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DynamicBranchBeginAbilityDelegate.h"
#include "EEnemy_Ability.h"
#include "DynamicBranchComponent.generated.h"

class UAblAbilityComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDynamicBranchComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SupportedAbilities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartImmediateBranchIfBranchTaskNotActive;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicBranchBeginAbility BeginAbilityDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* AbilityComponent;
    
public:
    UDynamicBranchComponent();
    UFUNCTION(BlueprintCallable)
    void StartDynamicBranch(EEnemy_Ability InAbility, EEnemy_Ability InNextAbility, bool bStartImmediate);
    
    UFUNCTION(BlueprintCallable)
    void SetAbilitySupported(EEnemy_Ability InAbility);
    
    UFUNCTION(BlueprintCallable)
    void SetAbilityActive(EEnemy_Ability InAbility, bool bActive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAbilitySupported(EEnemy_Ability InAbility) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAbilityActive(EEnemy_Ability InAbility) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EEnemy_Ability GetActiveAbility() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearAbilitySupported(EEnemy_Ability InAbility);
    
};

