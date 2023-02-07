#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorLookAtBase.h"
#include "CameraStackBehaviorLookAt.generated.h"

class UCameraStackSecondaryTargetGetter;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorLookAt : public UCameraStackBehaviorLookAtBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackSecondaryTargetGetter* LookAtTarget;
    
    UCameraStackBehaviorLookAt();
};

