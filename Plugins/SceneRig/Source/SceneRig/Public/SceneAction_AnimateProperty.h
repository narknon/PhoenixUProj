#pragma once
#include "CoreMinimal.h"
#include "AnimateProperty_PropertyName.h"
#include "ESceneAction_AnimateCurves_BlendMode.h"
#include "ESceneAction_AnimateCurves_FillMode.h"
#include "SceneAction_AnimateCurves.h"
#include "SceneRigObjectActionBase_ComponentName.h"
#include "SceneAction_AnimateProperty.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_AnimateProperty : public USceneAction_AnimateCurves {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigObjectActionBase_ComponentName ComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimateProperty_PropertyName PropertyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneAction_AnimateCurves_BlendMode BlendMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneAction_AnimateCurves_FillMode FillMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LoopCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepStateOnCompletion;
    
    USceneAction_AnimateProperty();
};

