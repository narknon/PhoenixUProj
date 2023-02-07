#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EUMGInputAction.h"
#include "ETutorialTransparency.h"
#include "LegendItemData.h"
#include "Screen.h"
#include "TutorialScreen.generated.h"

class UMediaSource;

UCLASS(Blueprintable, EditInlineNew)
class UTutorialScreen : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TutorialName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TutorialAlias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TutorialStep;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETutorialTransparency TransparencyType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EUMGInputAction, bool> CompletionButtons;
    
public:
    UTutorialScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialVideoReady(const UMediaSource* MediaSource);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialVideoIsLoading(const bool IsLoading);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialTitle(const FString& TitleString, const bool IsTranslatable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialLegendItems(const TArray<FLegendItemData>& LegendItems);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialImageName(const FString& ImageString);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialExpiryTimerProgress(const float Progress);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialCompletionAction(const EUMGInputAction InputAction, const bool bMustHold);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialBody(const FString& BodyString, bool IsTranslatable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSetTutorialPosition(FVector2D Position, FVector2D Alignment);
    
};

