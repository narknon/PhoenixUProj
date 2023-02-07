#pragma once
#include "CoreMinimal.h"
#include "DynamicBucketGroupStackEntry.h"
#include "DynamicBucketGroupStack.generated.h"

USTRUCT(BlueprintType)
struct FDynamicBucketGroupStack {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDynamicBucketGroupStackEntry> Stack;
    
public:
    TICKSEQUENCER_API FDynamicBucketGroupStack();
};

