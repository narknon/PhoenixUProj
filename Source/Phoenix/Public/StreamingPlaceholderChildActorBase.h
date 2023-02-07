#pragma once
#include "CoreMinimal.h"
#include "EStreamingPlaceholderPriority.h"
#include "StreamingPlaceholderBase.h"
#include "StreamingPlaceholderChildActorBase.generated.h"

class UStreamingPreviewChildActorComponent;

UCLASS(Abstract, Blueprintable)
class AStreamingPlaceholderChildActorBase : public AStreamingPlaceholderBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStreamingPlaceholderPriority StreamingPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSpawn;
    
protected:
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, TextExportTransient, Transient, meta=(AllowPrivateAccess=true))
    UStreamingPreviewChildActorComponent* ChildActorComponent;
    
public:
    AStreamingPlaceholderChildActorBase();
};

