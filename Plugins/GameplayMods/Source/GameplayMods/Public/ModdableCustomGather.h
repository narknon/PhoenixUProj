#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ModdableCustomGather.generated.h"

class UObject;

UINTERFACE(Blueprintable)
class GAMEPLAYMODS_API UModdableCustomGather : public UInterface {
    GENERATED_BODY()
};

class GAMEPLAYMODS_API IModdableCustomGather : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<UObject*> GatherAssociatedModdables();
    
};

