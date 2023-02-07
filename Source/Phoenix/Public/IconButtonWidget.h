#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ButtonClickDelegateDelegate.h"
#include "ButtonHoverDelegateDelegate.h"
#include "ButtonPressDelegateDelegate.h"
#include "ButtonReleaseDelegateDelegate.h"
#include "ButtonUnhoverDelegateDelegate.h"
#include "EFactsheetItemType.h"
#include "EIconButtonState.h"
#include "EUIAsyncLoadPriority.h"
#include "IconButtonImageLoadedDelegateDelegate.h"
#include "PhoenixUserWidget.h"
#include "IconButtonWidget.generated.h"

class UButton;
class UImage;
class UObject;
class UTexture2D;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class UIconButtonWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IconScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BackgroundIconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EIconButtonState IconButtonState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DataField;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DataField2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Size;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UButton* TheButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* TheImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* hexBack;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonClickDelegate OnIconButtonClick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonHoverDelegate OnIconButtonHover;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonUnhoverDelegate OnIconButtonUnhover;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonPressDelegate OnIconButtonPress;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonReleaseDelegate OnIconButtonRelease;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIconButtonImageLoadedDelegate OnImageLoadComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LastRequestedImageName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LastRequestedMatchSize;
    
public:
    UIconButtonWidget();
    UFUNCTION(BlueprintCallable)
    void TryResolveImage(bool bAsyncLoadIfFail, EUIAsyncLoadPriority OptionalPriority);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SetState(bool IsActive);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsTutorialHighlighted(bool bIsTutorialHighlighted);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIsNew(bool bIsNew);
    
    UFUNCTION(BlueprintCallable)
    void SetImage(const FString& ImageName, bool MatchSize, EUIAsyncLoadPriority OptionalPriority);
    
    UFUNCTION(BlueprintCallable)
    void SetHexBack(const FString& ImageName);
    
    UFUNCTION(BlueprintCallable)
    void SetFactsheetItemType(EFactsheetItemType Type);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonStatus(const FString& StateImage, bool StateImageVisible, const FString& StateHexBack, bool StateEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetButtonState(EIconButtonState NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetButtonSize(FVector2D NewSize);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool SetButtonIcons(const FString& BackgroundImage);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool RemoveExtraContent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSynchronizeProperties();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSelectionChanged(bool selected);
    
    UFUNCTION(BlueprintCallable)
    void OnImageLoaded(UTexture2D* LoadedTexture, UObject* CallbackParam);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HighlightButton(bool isHighlighted);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool HandleNonExistent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool HandleMissing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool HandleEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool HandleDisabled();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EFactsheetItemType> GetFactsheetItemType();
    
    UFUNCTION(BlueprintCallable)
    FString GetFactsheetItemName();
    
    UFUNCTION(BlueprintCallable)
    FString GetFactsheetItemDesc();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UWidget* GetExtraContent();
    
    UFUNCTION(BlueprintCallable)
    void ButtonUnhovered();
    
    UFUNCTION(BlueprintCallable)
    void ButtonReleased();
    
    UFUNCTION(BlueprintCallable)
    void ButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    void ButtonHovered();
    
    UFUNCTION(BlueprintCallable)
    void ButtonClicked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool AddExtraContent(UWidget* NewContent);
    
};

