#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AblReactionsList.h"
#include "QueueReactionParams.h"
#include "ReactionDataDelegateDelegate.h"
#include "ReactionParamsDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "AblReactionComponent.generated.h"

class UAblAbilityComponent;
class UAblAbilityContext;
class UAblReactionAbility;
class UAblReactionData;
class UAnimationArchitectComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABLECORE_API UAblReactionComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReactionParamsDelegate OnReactionReceived;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReactionDataDelegate OnReactionQueued;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReactionDataDelegate OnReactionFinished;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAblAbilityComponent* AbleAbilityComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAnimationArchitectComponent* AnimationArchitectComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FAblReactionsList> QueuedReactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FAblReactionsList> RunningReactions;
    
public:
    UAblReactionComponent();
    UFUNCTION(BlueprintCallable)
    UAblReactionData* QueueReaction(const FQueueReactionParams& ReactionParams);
    
    UFUNCTION(BlueprintCallable)
    UAblReactionData* QueueGivenReactionAbility(TSubclassOf<UAblReactionAbility> ReactionAbility, const FQueueReactionParams& ReactionParams);
    
    UFUNCTION(BlueprintCallable)
    UAblReactionData* QueueGivenReactionAbilities(TArray<TSubclassOf<UAblReactionAbility>> ReactionAbilities, const FQueueReactionParams& ReactionParams);
    
    UFUNCTION(BlueprintCallable)
    static FQueueReactionParams MakeReactionParamsFromReactionData(const UAblReactionData* ReactionData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyReactionRunning() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleReactionAbilityStart(const UAblAbilityContext* Context);
    
    UFUNCTION(BlueprintCallable)
    void HandleReactionAbilityInterrupt(const UAblAbilityContext* Context);
    
    UFUNCTION(BlueprintCallable)
    void HandleReactionAbilityEnd(const UAblAbilityContext* Context);
    
    UFUNCTION(BlueprintCallable)
    void HandleReactionAbilityBranch(const UAblAbilityContext* CurrentContext, const UAblAbilityContext* NextContext);
    
public:
    UFUNCTION(BlueprintCallable)
    void EnableReactions();
    
    UFUNCTION(BlueprintCallable)
    void DisableReactions();
    
};

