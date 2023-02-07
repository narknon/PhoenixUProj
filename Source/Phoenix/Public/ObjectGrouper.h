#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectGrouper.generated.h"

UCLASS(Blueprintable)
class AObjectGrouper : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Objects;
    
    AObjectGrouper();
};

