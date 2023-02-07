#pragma once
#include "CoreMinimal.h"
#include "ELoadingScreenLocation.h"
#include "PhoenixUserWidget.h"
#include "Loadingcreen.generated.h"

class UImage;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class ULoadingcreen : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* LoadingImage;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> Tips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BackgroundID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> DebugBackgroundIDs;
    
public:
    ULoadingcreen();
    UFUNCTION(BlueprintCallable)
    void SetTextureByName(const FString& Name);
    
    UFUNCTION(BlueprintCallable)
    void SetTexture(UTexture2D* Texture);
    
    UFUNCTION(BlueprintCallable)
    void PickBackgroundID(const ELoadingScreenLocation DestinationLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDisplayNextTip(const FString& TipKey);
    
    UFUNCTION(BlueprintCallable)
    void GenerateTipList(const ELoadingScreenLocation DestinationLocation);
    
    UFUNCTION(BlueprintCallable)
    void DisplayPrevTip();
    
    UFUNCTION(BlueprintCallable)
    void DisplayNextTip();
    
};

