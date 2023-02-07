#pragma once
#include "CoreMinimal.h"
#include "TimeRigOutputSymbol.h"
#include "ESceneAction_PlaySceneRigInitializeType.h"
#include "SceneRigActionBase.h"
#include "SceneAction_PlaySceneRig.generated.h"

class USceneRigProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_PlaySceneRig : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigProvider* SceneRigProvider;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneAction_PlaySceneRigInitializeType Initialize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol Started;
    
    USceneAction_PlaySceneRig();
};

