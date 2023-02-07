#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RuntimeCurveVector -FallbackName=RuntimeCurveVector
#include "RuntimeCurveVector.h"
#include "SceneAction_AnimateProperty.h"
#include "SceneAction_AnimateVectorProperty.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_AnimateVectorProperty : public USceneAction_AnimateProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeCurveVector Curve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DefaultValue;
    
    USceneAction_AnimateVectorProperty();
};

