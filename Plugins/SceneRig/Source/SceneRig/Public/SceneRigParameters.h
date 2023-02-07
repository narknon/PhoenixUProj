#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameters.generated.h"

class UObject;
class USceneRigParameter;
class USceneRigStageParameterBlock;
class UTimeRig_StoryGraph;
class UTimeRig_StoryGraphNode;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FString, USceneRigParameter*> Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneRigStageParameterBlock* StageParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* WorldContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig_StoryGraph* StoryGraph;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig_StoryGraphNode* StoryNode;
    
    FSceneRigParameters();
};

