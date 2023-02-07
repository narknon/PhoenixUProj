#pragma once
#include "CoreMinimal.h"
#include "AnimationRequestLayerReference.h"
#include "SceneActionAnimCurve.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_AnimCurves.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_AnimCurves : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationRequestLayerReference Layer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionAnimCurve> Curves;
    
    USceneAction_AnimCurves();
};

