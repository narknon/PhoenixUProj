#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BeaconableObject.generated.h"

UINTERFACE(Blueprintable)
class UBeaconableObject : public UInterface {
    GENERATED_BODY()
};

class IBeaconableObject : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FName GetUniqueBeaconId();
    
};

