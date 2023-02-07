#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveLinearColor.h"
#include "SceneAction_AnimateProperty.h"
#include "SceneAction_AnimateColorProperty.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_AnimateColorProperty : public USceneAction_AnimateProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveLinearColor Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DefaultValue;
    
    USceneAction_AnimateColorProperty();
};

