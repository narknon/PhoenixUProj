#pragma once
#include "CoreMinimal.h"
#include "Enemy_TargetPriority.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TargetPriority {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetSubTypeID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PriorityMult;
    
    PHOENIX_API FEnemy_TargetPriority();
};

