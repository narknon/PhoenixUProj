#pragma once
#include "CoreMinimal.h"
#include "IKDriver.h"
#include "IKDriver_AnimationDrivenData.h"
#include "IKDriver_AnimationDriven.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UIKDriver_AnimationDriven : public UIKDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIKDriver_AnimationDrivenData> EffectorDefinitions;
    
    UIKDriver_AnimationDriven();
};

