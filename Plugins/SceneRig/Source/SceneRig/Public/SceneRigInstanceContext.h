#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_ComponentOwnerInterface.h"
#include "AnimationArchitect_TagProviderInterface.h"
#include "AnimDebugInfo.h"
#include "ProviderStateHost.h"
#include "SpawnedActorHost.h"
#include "IMovieScenePlaybackClient.h"
#include "TimeRigInstanceContext.h"
#include "SceneParameterChangeRequest.h"
#include "SceneRigParameters.h"
#include "SceneRigInstanceContext.generated.h"

class ULevelStreaming;
class UObject;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigInstanceContext : public UTimeRigInstanceContext/*, public IMovieScenePlaybackClient, public IAnimationArchitect_TagProviderInterface, public IAnimationArchitect_ComponentOwnerInterface, public IAnimDebugInfo, public ISpawnedActorHost, public IProviderStateHost*/ {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UObject*, UObject*> ProviderStateMap;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelStreaming*> StreamingLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameters Parameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneParameterChangeRequest> ParameterChangeRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UObject*> BoundObjects;
    
    USceneRigInstanceContext();
    
    // Fix for true pure virtual functions not being implemented
};

