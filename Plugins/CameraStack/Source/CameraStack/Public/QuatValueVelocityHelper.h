#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "QuatValueVelocity.h"
#include "QuatValueVelocityHelper.generated.h"

UCLASS(Abstract, Blueprintable)
class UQuatValueVelocityHelper : public UObject {
    GENERATED_BODY()
public:
    UQuatValueVelocityHelper();
    UFUNCTION(BlueprintCallable)
    static void Update(UPARAM(Ref) FQuatValueVelocity& Data, const FRotator& Value, const float& DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    static FQuatValueVelocity Inverse(const FQuatValueVelocity& Data);
    
    UFUNCTION(BlueprintCallable)
    static void Get(const FQuatValueVelocity& Data, FRotator& OutValue, FVector& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void Activate(UPARAM(Ref) FQuatValueVelocity& Data, FRotator Value, FVector Velocity);
    
};

