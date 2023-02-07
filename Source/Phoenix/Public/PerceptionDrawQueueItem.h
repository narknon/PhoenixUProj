#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PerceptionDrawQueueItem.generated.h"

class UPerceptionIconData;

UCLASS(Blueprintable)
class UPerceptionDrawQueueItem : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPerceptionIconData* perceptionData;
    
    UPerceptionDrawQueueItem();
};

