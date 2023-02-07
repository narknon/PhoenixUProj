#pragma once
#include "CoreMinimal.h"
#include "AblReactionComponent.h"
#include "GameplayTagContainer.h"
#include "EStandardManagedPriority.h"
#include "ECharacterShutdownPriority.h"
#include "NpcReactionComboEndDelegateDelegate.h"
#include "NpcReactionComboStartDelegateDelegate.h"
#include "NPC_ReactionComponent.generated.h"

class UAblReactionComponentConfig;
class UAblReactionData;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UNPC_ReactionComponent : public UAblReactionComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNpcReactionComboStartDelegate OnComboStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNpcReactionComboEndDelegate OnComboEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAblReactionComponentConfig* Config;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, float> ReactionDurationOverrides;
    
public:
    UNPC_ReactionComponent();
    UFUNCTION(BlueprintCallable)
    void StartSettingReactionsEnabledValue(bool bValue, ECharacterShutdownPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingReactionsEnabledFromAlliesValue(bool bValue, EStandardManagedPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    static bool IsFullBodyReactionQueuedOrRunning(UAblReactionComponent* ReactionComponent);
    
    UFUNCTION(BlueprintCallable)
    void HandleReactionFinished(UAblReactionData* ReactionData, UAblReactionComponent* ReactionComponent);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingReactionsEnabledValue(ECharacterShutdownPriority Priority, UObject* InInstigator);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingReactionsEnabledFromAlliesValue(UObject* InInstigator);
    
};

