#pragma once
#include "CoreMinimal.h"
#include "IKPoseFixupDefinition.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_IKPoseFixup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneAction_IKPoseFixup : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIKPoseFixupDefinition Definition;
    
    USceneAction_IKPoseFixup();
};

