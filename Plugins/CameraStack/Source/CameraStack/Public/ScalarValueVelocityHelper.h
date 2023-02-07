#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ScalarValueVelocity.h"
#include "ScalarValueVelocityHelper.generated.h"

UCLASS(Abstract, Blueprintable)
class UScalarValueVelocityHelper : public UObject {
    GENERATED_BODY()
public:
    UScalarValueVelocityHelper();
    UFUNCTION(BlueprintCallable)
    static void Update(UPARAM(Ref) FScalarValueVelocity& Data, const float& Value, const float& DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    static FScalarValueVelocity Inverse(const FScalarValueVelocity& Data);
    
    UFUNCTION(BlueprintCallable)
    static void Get(const FScalarValueVelocity& Data, float& OutValue, float& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void Activate(UPARAM(Ref) FScalarValueVelocity& Data, float Value, float Velocity);
    
};

