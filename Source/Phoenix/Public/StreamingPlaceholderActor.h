#pragma once
#include "CoreMinimal.h"
#include "StreamingPlaceholderChildActorBase.h"
#include "StreamingPlaceholderActor.generated.h"

class AActor;

UCLASS(Blueprintable)
class AStreamingPlaceholderActor : public AStreamingPlaceholderChildActorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorToSpawn;
    
    AStreamingPlaceholderActor(const FObjectInitializer& ObjectInitializer);
};

