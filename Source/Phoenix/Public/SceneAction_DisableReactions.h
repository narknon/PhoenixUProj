#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "EStandardManagedPriority.h"
#include "ECharacterShutdownPriority.h"
#include "SceneAction_DisableReactions.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_DisableReactions : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandardManagedPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECharacterShutdownPriority PriorityNew;
    
    USceneAction_DisableReactions();
};

