#pragma once
#include "CoreMinimal.h"
#include "EEnemy_AttackLocSource.h"
#include "Enemy_MoveStopData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_MoveStopData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AttackLocSource AttackLocSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHeadingChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistanceChange;
    
    PHOENIX_API FEnemy_MoveStopData();
};

