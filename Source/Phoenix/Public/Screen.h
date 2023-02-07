#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "EUMGInputAction.h"
#include "EUMGInputAxis.h"
#include "EUIPopupPriority.h"
#include "EUIScreenType.h"
#include "PhoenixUserWidget.h"
#include "Screen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UScreen : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUIScreenType ScreenType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUIPopupPriority PopupPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldShowCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldHideCursorOnRemove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D CursorPositionOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HandleBackButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMouseLockMode MouseLockMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoAcquireUMGFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EUMGInputAction> IgnoredFocusInputActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EUMGInputAxis> IgnoredFocusInputAxis;
    
    UScreen();
    UFUNCTION(BlueprintCallable)
    void ScreenUnregisterAllUMGInputAxis();
    
    UFUNCTION(BlueprintCallable)
    void ScreenUnregisterAllUMGInputActions(EInputEvent InputEvent);
    
    UFUNCTION(BlueprintCallable)
    void ScreenRegisterAllUMGInputAxis();
    
    UFUNCTION(BlueprintCallable)
    void ScreenRegisterAllUMGInputActions(EInputEvent InputEvent);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnScreenOutroComplete(UPhoenixUserWidget* PhoenixWidget, int32 OutroType);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInputEnabled() const;
    
    UFUNCTION(BlueprintCallable)
    static int32 GetZOrderOffsetForScreenType(EUIScreenType InScreenType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GatherMastermindExtraScreenStrings(TArray<FString>& outExtraScreenStrings);
    
    UFUNCTION(BlueprintCallable)
    void CloseScreenWithOutro();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClassLoaded();
    
};

