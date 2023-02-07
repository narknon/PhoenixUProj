#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigStageContainer.generated.h"

class ISceneParameterInterface;
class USceneParameterInterface;
class USceneRigStageParameterBlock;
class UWorld;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStageContainer : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TScriptInterface<ISceneParameterInterface> SceneParameterInterface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigStageParameterBlock* StageParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* StageWorld;
    
    USceneRigStageContainer();
};

