#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation.h"
#include "CogGroupEvaluation_Height.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class COGNITION_API UCogGroupEvaluation_Height : public UCogGroupEvaluation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearHeightUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearHeightDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarHeightUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FarHeightDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdjustCenterHeightByCameraDirection;
    
    UCogGroupEvaluation_Height();
};

