#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_BoneUnscaled.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_BoneUnscaled : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UTransform_BoneUnscaled();
};

