#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BaseArchitectTransition.h"
#include "BaseArchitectState.generated.h"

class UBaseArchitectAsset;

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UBaseArchitectState : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBaseArchitectAsset* StateAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBaseArchitectTransition> TransitionsTo;
    
    UBaseArchitectState();
};

