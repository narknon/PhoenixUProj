#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackBehaviorBlend.h"
#include "CameraStackBehaviorAddTargetOffset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAddTargetOffset : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTargetLocalSpace;
    
    UCameraStackBehaviorAddTargetOffset();
};

