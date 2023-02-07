#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VCSlot.h"
#include "VirtualContainer.generated.h"

UCLASS(Blueprintable)
class UVirtualContainer : public UObject {
    GENERATED_BODY()
public:
    UVirtualContainer();
    UFUNCTION(BlueprintCallable)
    bool IsFinite(const FString& ContainerID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FVCSlot> GetContents(const FString& ContainerID);
    
};

