#pragma once
#include "CoreMinimal.h"
#include "ConjuredHistoryItem.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FConjuredHistoryItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Actors;
    
    PHOENIX_API FConjuredHistoryItem();
};

