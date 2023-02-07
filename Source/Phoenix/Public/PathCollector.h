#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PathCollectorPath.h"
#include "PathCollector.generated.h"

UCLASS(Blueprintable)
class UPathCollector : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPathCollectorPath> ClosestPaths;
    
    UPathCollector();
};

