#pragma once
#include "CoreMinimal.h"
#include "StreamingPlaceholderChildActorBase.h"
#include "StreamingPlaceholderLockState.h"
#include "StreamingPlaceholderUnlocked.generated.h"

class AActor;

UCLASS(Blueprintable)
class AStreamingPlaceholderUnlocked : public AStreamingPlaceholderChildActorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStreamingPlaceholderLockState> States;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> DefaultActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSwapWhenLockChanges;
    
    AStreamingPlaceholderUnlocked(const FObjectInitializer& ObjectInitializer);
};

