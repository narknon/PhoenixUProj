#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_PoseGroup.generated.h"

class UPoseGroupProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_PoseGroup : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPoseGroupProvider* PoseGroupProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool RegisterWithConversation;
    
    USceneAction_PoseGroup();
};

