#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "QualifierTask.h"
#include "CopyOptionActorLocationToBlackboardQualifierTask.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UCopyOptionActorLocationToBlackboardQualifierTask : public UQualifierTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector OutputLocationKey;
    
    UCopyOptionActorLocationToBlackboardQualifierTask();
};

