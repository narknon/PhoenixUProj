#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Odc_BP.generated.h"

UCLASS(Blueprintable)
class ODYSSEYRUNTIME_API UOdc_BP : public UObject {
    GENERATED_BODY()
public:
    UOdc_BP();
    UFUNCTION(BlueprintCallable)
    static bool GetNavmeshPoint(const int32 Layer, const FVector& InLoc, float InRadius, float InUpDist, float InDownDist, FVector& OutLoc);
    
};

