#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "EnemyAIBehaviorTreeDataTable.generated.h"

class UBehaviorTree;

USTRUCT(BlueprintType)
struct FEnemyAIBehaviorTreeDataTable : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBehaviorTree* BehaviorTreePtr;
    
    PHOENIX_API FEnemyAIBehaviorTreeDataTable();
};

