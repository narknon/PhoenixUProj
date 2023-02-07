#pragma once
#include "CoreMinimal.h"
#include "ETickSequencerGroup.h"
#include "DynamicBucketGroupStackEntry.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FDynamicBucketGroupStackEntry {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETickSequencerGroup Group;
    
    TICKSEQUENCER_API FDynamicBucketGroupStackEntry();
};

