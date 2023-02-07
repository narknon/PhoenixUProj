#pragma once
#include "CoreMinimal.h"
#include "ObjectProvider.h"
#include "PoseGroupProvider.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UPoseGroupProvider : public UObjectProvider {
    GENERATED_BODY()
public:
    UPoseGroupProvider();
};

