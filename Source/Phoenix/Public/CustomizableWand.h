#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsyncWandTexLoadedCallbackDelegate.h"
#include "CustomizableWand.generated.h"

class UTexture;

UCLASS(Blueprintable)
class PHOENIX_API ACustomizableWand : public AActor {
    GENERATED_BODY()
public:
    ACustomizableWand(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    bool AsyncLoadTexture(const TSoftObjectPtr<UTexture> SoftTexturePtr, const FName TexParam, const FAsyncWandTexLoadedCallback& Callback);
    
};

