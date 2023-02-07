#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "PhysicalResponseObjectInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UPhysicalResponseObjectInterface : public UInterface {
    GENERATED_BODY()
};

class IPhysicalResponseObjectInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectPhysicalResponseImpact(float ImpactIntensity, const FName SpellName, const FName ResponseConfigName, const FVector& ImpactLocation);
    
};

