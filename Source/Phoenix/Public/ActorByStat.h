#pragma once
#include "CoreMinimal.h"
#include "ActorByStat.generated.h"

class UActorProvider;

USTRUCT(BlueprintType)
struct FActorByStat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StatValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    PHOENIX_API FActorByStat();
};

