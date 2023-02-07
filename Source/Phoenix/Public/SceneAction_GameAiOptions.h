#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "EStandardManagedPriority.h"
#include "SceneAction_GameAiOptions.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_GameAiOptions : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideAreCharactersInSceneTargetableByAi;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAreCharactersInSceneTargetableByAi;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandardManagedPriority TargetableByAiPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverrideAreNpcsSuspended;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuspendNpcs;
    
    USceneAction_GameAiOptions();
};

