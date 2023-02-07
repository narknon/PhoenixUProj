#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NotificationWidget.generated.h"

class UImage;
class UPhoenixTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class UNotificationWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Subheader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* Header;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ItemName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ImageId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemCount;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LifeTime;
    
public:
    UNotificationWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ToggleCountVisibility(bool IsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsInventoryFullNotification(bool IsInventoryFull);
    
    UFUNCTION(BlueprintCallable)
    void InitDetails(const FString& NewItemName, FName NewVariation, const FString& DisplayName, bool bIsHeaderTranslatable, int32 NewItemCount, const FString& NewIconName, bool bSpecialCollection);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IncrementCount(int32 Amount);
    
};

