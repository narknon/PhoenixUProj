#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "Fonts/SlateFontInfo.h"
#include "AsyncInspectableScreenLoadCallbackDelegate.h"
#include "AsyncScreenLoadCallbackDelegate.h"
#include "AsyncUIFontLoadCallbackDelegate.h"
#include "AsyncUITextureLoadCallbackDelegate.h"
#include "EUIAsyncLoadPriority.h"
#include "MenuReaderVoice.h"
#include "Templates/SubclassOf.h"
#include "UIBlueprintFunctionLibrary.generated.h"

class AActor;
class AController;
class ANPC_Character;
class APlayerController;
class UImage;
class UObject;
class UPanelWidget;
class UTexture2D;
class UUserWidget;
class UWidget;

UCLASS(Blueprintable)
class UUIBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UUIBlueprintFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static bool WorldToViewport(FVector WorldPos, FVector2D& o_Point, bool LockToViewableSpace);
    
    UFUNCTION(BlueprintCallable)
    static FString UnicodeFilter(const FString& InputStr);
    
    UFUNCTION(BlueprintCallable)
    static void SwitchToGamePadControlScheme(FName ControlSchemeName);
    
    UFUNCTION(BlueprintCallable)
    static void ShowOutlines(APlayerController* PC);
    
    UFUNCTION(BlueprintCallable)
    static void ShowInspectableWithCallback(const FString& InspectableID, const FAsyncInspectableScreenLoadCallback& Callback);
    
    UFUNCTION(BlueprintCallable)
    static void ShowInspectable(const FString& InspectableID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SetInventoryIconOverride(const FString& ItemId, FName Variation, FString& OutDisplayName, FString& OutIconName, bool& OutIsNameTranslatable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool RunningWithEpicGamesStore();
    
    UFUNCTION(BlueprintCallable)
    static void RotateMenuActors(float AxisValue, float rotateSpeedMultiplier, TArray<AActor*> Actors);
    
    UFUNCTION(BlueprintCallable)
    static void RevertToDefaultInputMappings();
    
    UFUNCTION(BlueprintCallable)
    static void RestartApplication();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObj"))
    static int32 PlayOwlMailDialog(UObject* WorldContextObj, const FString& MailID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool NotEqual_MenuReaderVoiceMenuReaderVoice(const FMenuReaderVoice& arg1, const FMenuReaderVoice& arg2);
    
    UFUNCTION(BlueprintCallable)
    FVector2D MeasureStringLength(const FString& TextString, FSlateFontInfo FontInfo);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LogIntroMessage(UObject* WorldContextObject, FText Message);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString KeyToString(FKey Key);
    
    UFUNCTION(BlueprintCallable)
    static bool IsSteamRunningOnSteamDeck();
    
    UFUNCTION(BlueprintCallable)
    static bool IsSteamInBigPictureMode();
    
    UFUNCTION(BlueprintCallable)
    static bool IsSpellOrToolBlacklisted(const FString& ItemName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsPCPlatform(bool bIsSteamDeckAlsoPC);
    
    UFUNCTION(BlueprintCallable)
    static bool IsGameInForeground();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsBeastMeshReady(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IconExistsInTable(const FString& IconTextureName);
    
    UFUNCTION(BlueprintCallable)
    static void HideOutlines(APlayerController* PC);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GotoScreenFromCode(const UObject* WorldContextObject, UUserWidget* OldScreenReference, TSubclassOf<UUserWidget> NewScreenClass);
    
    UFUNCTION(BlueprintCallable)
    static UUserWidget* GetWidgetParentOfClass(UWidget* ChildWidget, TSubclassOf<UUserWidget> WidgetClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetTimespanTextWithMilliseconds(FTimespan Timespan);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetTimeSinceLastSave(FTimespan& OutTimespan);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetSalonChangeCost();
    
    UFUNCTION(BlueprintCallable)
    static float GetPotionDuration(const FName& PotionName);
    
    UFUNCTION(BlueprintCallable)
    static FTransform GetPlayerSpawnLocation(AController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetNPCCharacterDamageNumberOffset(const ANPC_Character* NPCCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText GetLocalizedDateTimeText(const FDateTime& InDateTime);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetHousePoints(const FString& HouseName);
    
    UFUNCTION(BlueprintCallable)
    static float GetGamma();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDisplayedPlayTime(const FString& TotalPlayTimeString, FText& OutText);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetDisplayedMissionIcon(FName MissionID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetCurrentLanguage();
    
    UFUNCTION(BlueprintCallable)
    static FName GetCurrentGamePadControlScheme();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FIntPoint> GetAvailableResolutions();
    
    UFUNCTION(BlueprintCallable)
    static void GetAllPanelChildrenOfWidgetClass(UPanelWidget* PanelWidgetParent, TSubclassOf<UWidget> WidgetClass, TArray<UWidget*>& FoundWidgets);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetActorCalloutComponentOffset(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static float GetAbilityDurationRemaining(AActor* AbilityOwner, const FName& AbilityName);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAbilityActive(const AActor* AbilityOwner, const FName& AbilityName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FText FloatToFractionalText(float Value, int32 Precision);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UTexture2D* FindIconTexture2D(const FString& IconTextureName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EqualEqual_MenuReaderVoiceMenuReaderVoice(const FMenuReaderVoice& arg1, const FMenuReaderVoice& arg2);
    
    UFUNCTION(BlueprintCallable)
    static bool CopyToClipboard(const FString& StringToCopy);
    
    UFUNCTION(BlueprintCallable)
    static bool CanUseHippogriff();
    
    UFUNCTION(BlueprintCallable)
    static bool CanUseGraphorn();
    
    UFUNCTION(BlueprintCallable)
    static bool CanUseBroom(bool bIncludeAvatarState);
    
    UFUNCTION(BlueprintCallable)
    static bool AsyncLoadUITexture(TSoftObjectPtr<UTexture2D> TextureRef, const FAsyncUITextureLoadCallback& Callback, UObject* CallbackParam, EUIAsyncLoadPriority Priority);
    
    UFUNCTION(BlueprintCallable)
    static bool AsyncLoadFont(FSoftObjectPath FontPath, const FAsyncUIFontLoadCallback& AsyncLoadCallback);
    
    UFUNCTION(BlueprintCallable)
    static void AsyncLoadActionSelectionUI();
    
    UFUNCTION(BlueprintCallable)
    static bool AsyncFindIconTexWithCallback(const FString& IconTextureName, const FAsyncUITextureLoadCallback& AsyncLoadCallback, UObject* CallbackParam);
    
    UFUNCTION(BlueprintCallable)
    static bool AsyncFindIconTexture2D(const FString& IconTextureName, UImage* InImage, bool MatchSize, EUIAsyncLoadPriority Priority, bool bIsLoadingScreen);
    
    UFUNCTION(BlueprintCallable)
    static bool AsyncCreateSpellMiniGame(FName GameName, bool UseDefaultCamera, const FAsyncScreenLoadCallback& AsyncLoadCallback);
    
    UFUNCTION(BlueprintCallable)
    static void AddPlayerHousePoints(int32 Points);
    
    UFUNCTION(BlueprintCallable)
    static void AddHousePoints(const FString& HouseName, int32 Points);
    
};

