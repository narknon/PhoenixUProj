#pragma once
#include "CoreMinimal.h"
#include "SceneAction_Adaptation.h"
#include "SceneAction_AdaptationExpression.generated.h"

class UExposureExpressionsExposureValue;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AdaptationExpression : public USceneAction_Adaptation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Affects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* Expression;
    
    USceneAction_AdaptationExpression();
};

