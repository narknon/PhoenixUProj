#pragma once
#include "CoreMinimal.h"
#include "LocationGroup.generated.h"

class AMapLocationActor;

USTRUCT(BlueprintType)
struct FLocationGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<AMapLocationActor*> Locations;
    
    PHOENIX_API FLocationGroup();
};

