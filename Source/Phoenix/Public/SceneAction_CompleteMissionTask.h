#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "MissionName.h"
#include "SceneAction_CompleteMissionTask.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CompleteMissionTask : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMissionName Mission;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString missionStepNickname;
    
    USceneAction_CompleteMissionTask();
};

