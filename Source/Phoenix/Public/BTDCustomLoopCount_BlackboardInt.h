#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTDCustomLoopCount.h"
#include "BTDCustomLoopCount_BlackboardInt.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBTDCustomLoopCount_BlackboardInt : public UBTDCustomLoopCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector BlackboardKey;
    
    UBTDCustomLoopCount_BlackboardInt();
};

