#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "RotatorValueVelocity.h"
#include "RotatorValueVelocityHelper.generated.h"

UCLASS(Abstract, Blueprintable)
class URotatorValueVelocityHelper : public UObject {
    GENERATED_BODY()
public:
    URotatorValueVelocityHelper();
    UFUNCTION(BlueprintCallable)
    static void Update(UPARAM(Ref) FRotatorValueVelocity& Data, const FRotator& Value, const float& DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    static FRotatorValueVelocity Inverse(const FRotatorValueVelocity& Data);
    
    UFUNCTION(BlueprintCallable)
    static void Get(const FRotatorValueVelocity& Data, FRotator& OutValue, FRotator& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void Activate(UPARAM(Ref) FRotatorValueVelocity& Data, FRotator Value, FRotator Velocity);
    
};

