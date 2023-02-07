#pragma once
#include "CoreMinimal.h"
#include "StreamingPlaceholderChildActorBase.h"
#include "TransfigurationPlaceholderFrontend.generated.h"

class AActor;

UCLASS(Blueprintable)
class ATransfigurationPlaceholderFrontend : public AStreamingPlaceholderChildActorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IdentifyingName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> DefaultActorToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OnlySpawnIfKeyPresent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OnlySpawnIfKeyNotPresent;
    
    ATransfigurationPlaceholderFrontend();
};

