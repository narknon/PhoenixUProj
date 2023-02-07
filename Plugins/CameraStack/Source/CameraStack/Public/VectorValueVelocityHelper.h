#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "VectorValueVelocity.h"
#include "VectorValueVelocityHelper.generated.h"

UCLASS(Abstract, Blueprintable)
class UVectorValueVelocityHelper : public UObject {
    GENERATED_BODY()
public:
    UVectorValueVelocityHelper();
    UFUNCTION(BlueprintCallable)
    static void Update(UPARAM(Ref) FVectorValueVelocity& Data, const FVector& Value, const float& DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    static FVectorValueVelocity Inverse(const FVectorValueVelocity& Data);
    
    UFUNCTION(BlueprintCallable)
    static void Get(const FVectorValueVelocity& Data, FVector& OutValue, FVector& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void Activate(UPARAM(Ref) FVectorValueVelocity& Data, FVector Value, FVector Velocity);
    
};

