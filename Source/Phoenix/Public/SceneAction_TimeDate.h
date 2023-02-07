#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_TimeDate.generated.h"

class UTimeOverrideBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_TimeDate : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimeOverrideBase* TimeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreviewOnly;
    
    USceneAction_TimeDate();
};

