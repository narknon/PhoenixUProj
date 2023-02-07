#pragma once
#include "CoreMinimal.h"
#include "AmbientProxyActorReference.generated.h"

class USceneRigProxyActor;

USTRUCT(BlueprintType)
struct FAmbientProxyActorReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USceneRigProxyActor> ProxyActor;
    
    SCENERIG_API FAmbientProxyActorReference();
};

