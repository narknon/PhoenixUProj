#pragma once
#include "CoreMinimal.h"
#include "RuntimeCurveVector2D.h"
#include "Vector2DProvider.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeCurveVector2D -FallbackName=RuntimeCurveVector2D
#include "Vector2D_Curve.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UVector2D_Curve : public UVector2DProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveVector2D Curve;
    
    UVector2D_Curve();
};

