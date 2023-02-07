#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveLinearColor.h"
#include "SkinFXColorPreview.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXColorPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NonTransactional, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor PreviewCurve;
    
    SKINFX_API FSkinFXColorPreview();
};

