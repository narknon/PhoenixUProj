#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "AblReactionData.generated.h"

class AActor;
class UActorComponent;

UCLASS(Blueprintable, Transient)
class ABLECORE_API UAblReactionData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer MunitionTags;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UActorComponent> ReactionEffectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDestroyEffectComponentOnReactionEnd;
    
    UAblReactionData();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPassive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInstigator();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetChannelName() const;
    
};

