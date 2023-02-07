#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OdcPathSpec.h"
#include "PathSpecInterface.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UPathSpecInterface : public UInterface {
    GENERATED_BODY()
};

class IPathSpecInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION()
    virtual FOdcPathSpec GetPathSpec() const PURE_VIRTUAL(GetPathSpec, return FOdcPathSpec{};);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    int32 GetLinkUsageFlags() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    int32 GetBlockageFlags() const;
    
};

