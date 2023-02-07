#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Fonts/SlateFontInfo.h"
#include "EDebugPanelControlID.h"
#include "DebugPanelComponent.generated.h"

class UDebugPanel;
class UWorld;

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DEBUGPANEL_API UDebugPanelComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> IntVariables;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDebugPanel* Panel;
    
public:
    UDebugPanelComponent();
    UFUNCTION(BlueprintCallable)
    void ShowPanel(bool Show);
    
    UFUNCTION(BlueprintCallable)
    bool SetVisible(EDebugPanelControlID controlID, bool Visible);
    
    UFUNCTION(BlueprintCallable)
    bool SetupShadow(EDebugPanelControlID controlID, FVector2D ShadowOffset, FLinearColor shadowColor);
    
    UFUNCTION(BlueprintCallable)
    bool SetTextAndColor(EDebugPanelControlID controlID, const FString& Text, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    bool SetText(EDebugPanelControlID controlID, const FString& Text);
    
    UFUNCTION(BlueprintCallable)
    bool SetFont(EDebugPanelControlID controlID, FSlateFontInfo Font);
    
    UFUNCTION(BlueprintCallable)
    bool SetColor(EDebugPanelControlID controlID, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool PanelVisible() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsMultilineText(EDebugPanelControlID controlID);
    
    UFUNCTION(BlueprintCallable)
    void HidePanel();
    
    UFUNCTION(BlueprintCallable)
    bool EnableMultilineText(EDebugPanelControlID controlID, int32 lineLimit);
    
    UFUNCTION(BlueprintCallable)
    bool DisableMultilineText(EDebugPanelControlID controlID);
    
    UFUNCTION(BlueprintCallable)
    bool CreateUnique(UWorld* onlyForWorld);
    
    UFUNCTION(BlueprintCallable)
    bool CreateShared(FName ID, UWorld* onlyForWorld);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool Created() const;
    
    UFUNCTION(BlueprintCallable)
    bool ClearText(EDebugPanelControlID controlID);
    
    UFUNCTION(BlueprintCallable)
    bool ClearScrollingText();
    
    UFUNCTION(BlueprintCallable)
    bool AppendTextLine(const FString& Text);
    
};

