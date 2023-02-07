#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "Curves/CurveFloat.h"
#include "AnimMetaDataNPCStrafe.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UAnimMetaDataNPCStrafe : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve BlendInputToHipRotationCurve;
    
    UAnimMetaDataNPCStrafe();
};

