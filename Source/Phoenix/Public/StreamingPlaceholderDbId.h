#pragma once
#include "CoreMinimal.h"
#include "SpawnSelectInfo.h"
#include "StreamingPlaceholderChildActorBase.h"
#include "StreamingPlaceholderDbId.generated.h"

UCLASS(Blueprintable)
class AStreamingPlaceholderDbId : public AStreamingPlaceholderChildActorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnSelectInfo DbIdInfo;
    
    AStreamingPlaceholderDbId();
};

