#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapFXItem.h"
#include "MapFXManager.generated.h"

class UMapFX;
class UMapFXChain;

UCLASS(Blueprintable)
class UMapFXManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapFXItem> FXList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapFX*> FXActiveList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapFXChain*> FXChainActiveList;
    
public:
    UMapFXManager();
private:
    UFUNCTION(BlueprintCallable)
    void FXComplete(UMapFX* MapFX);
    
    UFUNCTION(BlueprintCallable)
    void FXChainComplete(UMapFXChain* MapFXChain);
    
};

