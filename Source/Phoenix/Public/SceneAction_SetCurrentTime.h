#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_SetCurrentTime.generated.h"

class USchedulerTimeProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_SetCurrentTime : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USchedulerTimeProvider* SchedulerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Hours;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Minutes;
    
    USceneAction_SetCurrentTime();
};

