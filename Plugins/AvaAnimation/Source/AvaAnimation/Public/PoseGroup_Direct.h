#pragma once
#include "CoreMinimal.h"
#include "PoseGroupProvider.h"
#include "PoseGroup_Direct.generated.h"

class UPoseGroup;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UPoseGroup_Direct : public UPoseGroupProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPoseGroup* PoseGroup;
    
    UPoseGroup_Direct();
};

