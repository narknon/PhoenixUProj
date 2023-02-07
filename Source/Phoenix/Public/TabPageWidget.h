#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "AutosaveRequestedDelegate.h"
#include "ChangeTabRequestedDelegate.h"
#include "ExitMenuRequestedDelegate.h"
#include "LegendInputHeldChangedDelegate.h"
#include "LegendItemData.h"
#include "MenuReadLegendRequestedDelegate.h"
#include "NewButtonLegendRequestedDelegate.h"
#include "PhoenixUserWidget.h"
#include "TabPageWidget.generated.h"

class ULegendItem;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UTabPageWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Destination;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ParallaxRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLegendItemData> MenuLegend;
    
    UPROPERTY(BlueprintReadWrite, DuplicateTransient, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPhoenixUserWidget* TabParentWidget;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAutosaveRequested OnAutosaveRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMenuReadLegendRequested OnMenuReadLegendRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNewButtonLegendRequested OnNewLegendRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChangeTabRequested OnNewTabRequested;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLegendInputHeldChanged OnLegendInputHeldChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExitMenuRequested OnExitMenuRequested;
    
    UTabPageWidget();
    UFUNCTION(BlueprintCallable)
    void SetTabParentWidget(UPhoenixUserWidget* InTabParentWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLegendItemHoldEnd(ULegendItem* LegendItem, bool HoldWasCompleted);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void LeaveFromPage();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool HandleInput(FKey Input);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GoToPage(const TArray<FString>& DestinationStack);
    
};

