#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "Construction_Interface.generated.h"

UINTERFACE(Blueprintable)
class UConstruction_Interface : public UInterface {
    GENERATED_BODY()
};

class IConstruction_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Construct(const FTransform& Transform);
    
};

