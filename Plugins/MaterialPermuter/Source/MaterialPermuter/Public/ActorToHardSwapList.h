#pragma once
#include "CoreMinimal.h"
#include "ActorToHardSwap.h"
#include "ActorToHardSwapList.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FActorToHardSwapList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActorToHardSwap> Actors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Processed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Swapped;
    
    FActorToHardSwapList();
};

