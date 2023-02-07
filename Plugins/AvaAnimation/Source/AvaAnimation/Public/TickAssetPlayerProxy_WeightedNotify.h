#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifyQueue.h"
#include "TickAssetPlayerProxy_WeightedNotify.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FTickAssetPlayerProxy_WeightedNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimNotifyEventReference> NotifyReferences;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NotifyWeight;
    
    FTickAssetPlayerProxy_WeightedNotify();
};

