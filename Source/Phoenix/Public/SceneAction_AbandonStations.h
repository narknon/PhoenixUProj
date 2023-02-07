#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_AbandonStations.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AbandonStations : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAbortPerformTasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopAndWait;
    
    USceneAction_AbandonStations();
};

