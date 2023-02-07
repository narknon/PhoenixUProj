#pragma once
#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "AssetWidget.generated.h"

class UBlueprint;
class UObject;

UCLASS(Blueprintable)
class UAssetWidget : public UWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Delegate;
    
    UAssetWidget();
    UFUNCTION(BlueprintCallable)
    static UObject* SpawnObject(UObject* ObjectToSpawn);
    
    UFUNCTION(BlueprintCallable)
    static void ShowAssetsInContentBrowser(UPARAM(Ref) TArray<UObject*>& InAssets);
    
    UFUNCTION(BlueprintCallable)
    static void ShowAssetInContentBrowser(UObject* Asset);
    
    UFUNCTION(BlueprintCallable)
    void SetAsset(UObject* InAsset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UObject* GetSelectedAssetInContentBrowser(UClass* ObjectClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UClass* GetGeneratedClassFromBlueprint(UBlueprint* Blueprint);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetAsset();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UBlueprint* CastToBlueprint(UObject* Object);
    
};

