#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_MissionPerformTasks.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_MissionPerformTasks : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MissionUID;
    
    UActor_MissionPerformTasks();
};

