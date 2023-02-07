#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorCore.h"
#include "CameraStackBehaviorCore_SceneRig.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorCore_SceneRig : public UCameraStackBehaviorCore {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCounteractAccumulatedRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainArmOrigin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlignArmWithAccumulatedRotation;
    
    UCameraStackBehaviorCore_SceneRig();
};

