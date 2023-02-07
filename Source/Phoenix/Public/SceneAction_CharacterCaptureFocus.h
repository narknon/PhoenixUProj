#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_CharacterCaptureFocus.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CharacterCaptureFocus : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCaptureFocusOnActionStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReleaseFocusOnActionEnd;
    
    USceneAction_CharacterCaptureFocus();
};

