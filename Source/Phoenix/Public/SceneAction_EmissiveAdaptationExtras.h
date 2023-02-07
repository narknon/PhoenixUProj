#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtras.h"
#include "SceneAction_EmissiveAdaptationBase.h"
#include "SceneAction_EmissiveAdaptationExtras.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_EmissiveAdaptationExtras : public USceneAction_EmissiveAdaptationBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtras EmissiveAdaptationExtras;
    
    USceneAction_EmissiveAdaptationExtras();
};

