#pragma once
#include "CoreMinimal.h"
#include "EasingFunction.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_ObjectFade.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_ObjectFade : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEasingFunction FadeCurve;
    
    USceneAction_ObjectFade();
};

