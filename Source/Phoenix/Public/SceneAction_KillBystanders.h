#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_KillBystanders.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_KillBystanders : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KillPct;
    
    USceneAction_KillBystanders();
};

