#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "AblAbilityTaskScratchPad.h"
#include "AblBranchTaskScratchPad.generated.h"

class UAblAbilityContext;


UCLASS(Blueprintable, NonTransient)
class ABLECORE_API UAblBranchTaskScratchPad : public UAblAbilityTaskScratchPad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FKey> CachedKeys;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEventReceived;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEventExists;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bCanEverPassConditions;
    
    UAblBranchTaskScratchPad();
    UFUNCTION(BlueprintCallable)
    void OnAnimationPlayed(float InCurrentTime, const UAnimationAsset* InAnimationAsset, const UAblAbilityContext* Context);
    
};

