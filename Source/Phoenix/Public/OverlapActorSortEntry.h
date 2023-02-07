#pragma once
#include "CoreMinimal.h"
#include "OverlapActorSortEntry.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FOverlapActorSortEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* OverlapActor;
    
    PHOENIX_API FOverlapActorSortEntry();
};

