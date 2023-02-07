#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "QualifierTask.h"
#include "CopyOptionActorChildLocationToBlackboardQualifierTask.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class BTUTILITYAI_API UCopyOptionActorChildLocationToBlackboardQualifierTask : public UQualifierTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector OutputLocationKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ChildName;
    
    UCopyOptionActorChildLocationToBlackboardQualifierTask();
};

