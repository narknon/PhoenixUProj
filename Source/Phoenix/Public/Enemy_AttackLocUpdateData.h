#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackLocUpdateData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_AttackLocUpdateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateInterval;
    
    PHOENIX_API FEnemy_AttackLocUpdateData();
};

