#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AssetWidgetInterface.generated.h"

class UObject;

UINTERFACE(Blueprintable, MinimalAPI)
class UAssetWidgetInterface : public UInterface {
    GENERATED_BODY()
};

class IAssetWidgetInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnIsAssetAcceptableForDrop(const UObject* Asset) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnAssetDropped(UObject* Asset);
    
};

