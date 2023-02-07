#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PreLoadAssetInterface.h"
#include "ArchitectGameInstance.generated.h"

class UArchitectGameInstance;
class UInteractionArchitectAsset;
class UObjectArchitectMonolithicAsset;
class UPreLoadArchitectMonolithicAsset;

UCLASS(Blueprintable, NonTransient)
class ANIMATIONARCHITECTRUNTIME_API UArchitectGameInstance : public UGameInstance, public IPreLoadAssetInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UInteractionArchitectAsset*> HardInteractionArchitectAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectArchitectMonolithicAsset* MonolithicObjectArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPreLoadArchitectMonolithicAsset* PreloadMonolithicArchitectAsset;
    
public:
    UArchitectGameInstance();
    UFUNCTION(BlueprintCallable)
    static UArchitectGameInstance* GetArchitectGameInstance();
    
    
    // Fix for true pure virtual functions not being implemented
};

