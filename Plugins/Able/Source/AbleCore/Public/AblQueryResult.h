#pragma once
#include "CoreMinimal.h"
#include "AblQueryResult.generated.h"

class AActor;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct ABLECORE_API FAblQueryResult {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> PrimitiveComponent;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Actor;
    
    FAblQueryResult();
};

