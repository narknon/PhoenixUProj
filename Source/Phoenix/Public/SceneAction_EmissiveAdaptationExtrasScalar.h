#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtraScalarName.h"
#include "SceneAction_EmissiveAdaptationExtrasSingleBase.h"
#include "SceneAction_EmissiveAdaptationExtrasScalar.generated.h"

class UCurveFloat;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_EmissiveAdaptationExtrasScalar : public USceneAction_EmissiveAdaptationExtrasSingleBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtraScalarName ScalarName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ScalarCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScalarValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCurve;
    
    USceneAction_EmissiveAdaptationExtrasScalar();
};

