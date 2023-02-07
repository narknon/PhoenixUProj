#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneAction_AnimateProperty.h"
#include "SceneAction_AnimateFloatProperty.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_AnimateFloatProperty : public USceneAction_AnimateProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* CartLocation;
    
    USceneAction_AnimateFloatProperty();
};

