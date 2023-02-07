#pragma once
#include "CoreMinimal.h"
#include "Enemy_TargetPriority.h"
#include "Enemy_TargetSelectionData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TargetSelectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetSelectionScoreSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemy_TargetPriority> TargetPriorityList;
    
    PHOENIX_API FEnemy_TargetSelectionData();
};

