#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LinkActor.h"
#include "LinkStripActor.generated.h"

UCLASS(Blueprintable)
class ODYSSEYRUNTIME_API ALinkStripActor : public ALinkActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LinkStartPos2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LinkEndPos2;
    
public:
    ALinkStripActor(const FObjectInitializer& ObjectInitializer);
};

