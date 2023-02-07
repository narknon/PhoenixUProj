#pragma once
#include "CoreMinimal.h"
#include "EAimAtAxisType.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_AimAt.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_AimAt : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* AimTarget;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EAimAtAxisType AimAxis;
    
    USceneAction_AimAt();
};

