#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "EScheduleEnableDisable.h"
#include "SceneAction_DisableSchedule.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_DisableSchedule : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EScheduleEnableDisable ActionOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EScheduleEnableDisable ActionOnExit;
    
    USceneAction_DisableSchedule();
};

