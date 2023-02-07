#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Styling/SlateBrush.h"
#include "Fonts/SlateFontInfo.h"
#include "Components/TextBlock.h"
#include "Components/Widget.h"
#include "PhoenixTextBlock.generated.h"

class UFont;

UCLASS(Blueprintable)
class PHOENIX_API UPhoenixTextBlock : public UTextBlock {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocalizationKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Translatable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ScaleFontSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush TextBackground;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BackgroundBrushColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWidget::FGetSlateBrush TextBackgroundDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle ColorTag;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftObjectPath AsianFontPath;
    
public:
    UPhoenixTextBlock();
    UFUNCTION(BlueprintCallable)
    void SetTextKey(const FString& Key);
    
    UFUNCTION(BlueprintCallable)
    void SetColorTag(FDataTableRowHandle NewColorTag);
    
private:
    UFUNCTION(BlueprintCallable)
    bool PreValidateLocalizationKey(const FString& RequestedKey);
    
public:
    UFUNCTION(BlueprintCallable)
    FString GetPhoenixText();
    
    UFUNCTION(BlueprintCallable)
    FSlateFontInfo GetFontInfo();
    
    UFUNCTION(BlueprintCallable)
    float GetCurrentFontScale();
    
    UFUNCTION(BlueprintCallable)
    FDataTableRowHandle GetColorTag();
    
private:
    UFUNCTION(BlueprintCallable)
    void FontLoadCallback(UFont* LoadedFont);
    
};

