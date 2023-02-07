#pragma once
#include "CoreMinimal.h"
#include "StreamingPlaceholderChildActorBase.h"
#include "StreamingPlaceholderFrontend.generated.h"

class AActor;

UCLASS(Blueprintable)
class AStreamingPlaceholderFrontend : public AStreamingPlaceholderChildActorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FrontendStateKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FrontendStateValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowInEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OnlySpawnIfKeyNotPresent;
    
    AStreamingPlaceholderFrontend();
};

