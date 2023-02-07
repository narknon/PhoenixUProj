#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETargetType.h"
#include "TargetTypeBase.generated.h"

UCLASS(Blueprintable)
class AMBULATORY_API UTargetTypeBase : public UObject {
    GENERATED_BODY()
public:
    UTargetTypeBase();
    UFUNCTION(BlueprintCallable)
    void SetExpirationTime(float InExpirationTime);
    
    UFUNCTION(BlueprintCallable)
    void SetComputedPriority(float InPriority);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<ETargetType::Type> GetTargetType();
    
    UFUNCTION(BlueprintCallable)
    float GetExpirationTime();
    
    UFUNCTION(BlueprintCallable)
    float GetComputedPriority();
    
};

