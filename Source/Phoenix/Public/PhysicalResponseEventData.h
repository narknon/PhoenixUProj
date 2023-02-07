#pragma once
#include "CoreMinimal.h"
#include "PhysicalResponseEventData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FPhysicalResponseEventData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* OwningActor;
    
    PHOENIX_API FPhysicalResponseEventData();
};

