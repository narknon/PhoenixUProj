#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionBase.h"
#include "SkyStateSmoothInOut.h"
#include "SceneAction_SkyState.generated.h"

class USkyStateOverride;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_SkyState : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyStateOverride* SkyStateOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkyStateSmoothInOut SmoothInOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreviewOnly;
    
    USceneAction_SkyState();
};

