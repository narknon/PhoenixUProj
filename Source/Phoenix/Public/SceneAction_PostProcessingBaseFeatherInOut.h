#pragma once
#include "CoreMinimal.h"
#include "SceneAction_PostProcessingBase.h"
#include "SceneAction_PostProcessingBaseFeatherInOut.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PostProcessingBaseFeatherInOut : public USceneAction_PostProcessingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeatherInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeatherOutTime;
    
    USceneAction_PostProcessingBaseFeatherInOut();
};

