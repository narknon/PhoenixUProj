#pragma once
#include "CoreMinimal.h"
#include "CachedColovariaComponentInfo.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FCachedColovariaComponentInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PrimitiveComponent;
    
    PHOENIX_API FCachedColovariaComponentInfo();
};

