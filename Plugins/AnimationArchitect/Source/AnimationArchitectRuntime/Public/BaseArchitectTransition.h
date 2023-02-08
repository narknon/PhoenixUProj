#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectTransition.generated.h"


class UBaseArchitectState;

USTRUCT(BlueprintType)
struct ANIMATIONARCHITECTRUNTIME_API FBaseArchitectTransition {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UBaseArchitectState> EndState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* TransitionAnim;
    
    FBaseArchitectTransition();
};

