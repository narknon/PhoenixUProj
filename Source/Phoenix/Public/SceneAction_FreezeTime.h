#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SceneAction_FreezeTime.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_FreezeTime : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnFreezeAtEnd;
    
    USceneAction_FreezeTime();
};

