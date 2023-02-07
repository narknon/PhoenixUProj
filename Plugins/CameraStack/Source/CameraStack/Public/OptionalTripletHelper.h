#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "OptionalTriplet.h"
#include "OptionalTripletHelper.generated.h"

UCLASS(Abstract, Blueprintable)
class UOptionalTripletHelper : public UObject {
    GENERATED_BODY()
public:
    UOptionalTripletHelper();
protected:
    UFUNCTION(BlueprintCallable)
    static FVector ClampVec(const FVector& InVec, const FOptionalTriplet& InMin, const FOptionalTriplet& InMax);
    
    UFUNCTION(BlueprintCallable)
    static FRotator ClampRot(const FRotator& InRot, const FOptionalTriplet& InMin, const FOptionalTriplet& InMax);
    
};

