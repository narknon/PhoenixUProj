#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SkinFXScalarPreview.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXScalarPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve PreviewCurve;
    
    SKINFX_API FSkinFXScalarPreview();
};

