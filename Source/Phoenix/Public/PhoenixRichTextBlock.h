#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Styling/SlateBrush.h"
#include "Components/RichTextBlock.h"
#include "Components/Widget.h"
#include "PhoenixRichTextBlock.generated.h"

class UFont;
class UTexture2D;

UCLASS(Blueprintable)
class PHOENIX_API UPhoenixRichTextBlock : public URichTextBlock {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocalizationKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Translatable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ScaleFontSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceDisplayGamepadGraphics;
    
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
    TArray<UTexture2D*> ReferencedTextures;
    
public:
    UPhoenixRichTextBlock();
    UFUNCTION(BlueprintCallable)
    void SetTextKey(const FString& Key);
    
    UFUNCTION(BlueprintCallable)
    void SetPhoenixText(const FString& InText);
    
private:
    UFUNCTION(BlueprintCallable)
    FString ReplaceInputActions(const FString& KeyText);
    
    UFUNCTION(BlueprintCallable)
    bool PreValidateLocalizationKey(const FString& RequestedKey);
    
    UFUNCTION(BlueprintCallable)
    void FontLoadCallback(UFont* Font);
    
};

