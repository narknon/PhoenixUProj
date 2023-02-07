#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "QualifierTask.h"
#include "CopyOptionActorToBlackboardQualifierTask.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UCopyOptionActorToBlackboardQualifierTask : public UQualifierTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector OutputActorKey;
    
    UCopyOptionActorToBlackboardQualifierTask();
};

