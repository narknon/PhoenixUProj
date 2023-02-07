#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraExposureName.h"
#include "SceneAction_EmissiveAdaptationExtrasSingleBase.h"
#include "SceneAction_EmissiveAdaptationExtrasExposure.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_EmissiveAdaptationExtrasExposure : public USceneAction_EmissiveAdaptationExtrasSingleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraExposureName ExposureName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ExposureCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExposureValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCurve;
    
    USceneAction_EmissiveAdaptationExtrasExposure();
};

