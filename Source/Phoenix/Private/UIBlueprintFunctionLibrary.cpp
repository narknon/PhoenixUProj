#include "UIBlueprintFunctionLibrary.h"
#include "Templates/SubclassOf.h"

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

bool UUIBlueprintFunctionLibrary::WorldToViewport(FVector WorldPos, FVector2D& o_Point, bool LockToViewableSpace) {
    return false;
}

FString UUIBlueprintFunctionLibrary::UnicodeFilter(const FString& InputStr) {
    return TEXT("");
}

void UUIBlueprintFunctionLibrary::SwitchToGamePadControlScheme(FName ControlSchemeName) {
}

void UUIBlueprintFunctionLibrary::ShowOutlines(APlayerController* PC) {
}

void UUIBlueprintFunctionLibrary::ShowInspectableWithCallback(const FString& InspectableID, const FAsyncInspectableScreenLoadCallback& Callback) {
}

void UUIBlueprintFunctionLibrary::ShowInspectable(const FString& InspectableID) {
}

bool UUIBlueprintFunctionLibrary::SetInventoryIconOverride(const FString& ItemId, FName Variation, FString& OutDisplayName, FString& OutIconName, bool& OutIsNameTranslatable) {
    return false;
}

bool UUIBlueprintFunctionLibrary::RunningWithEpicGamesStore() {
    return false;
}

void UUIBlueprintFunctionLibrary::RotateMenuActors(float AxisValue, float rotateSpeedMultiplier, TArray<AActor*> Actors) {
}

void UUIBlueprintFunctionLibrary::RevertToDefaultInputMappings() {
}

void UUIBlueprintFunctionLibrary::RestartApplication() {
}

int32 UUIBlueprintFunctionLibrary::PlayOwlMailDialog(UObject* WorldContextObj, const FString& MailID) {
    return 0;
}

bool UUIBlueprintFunctionLibrary::NotEqual_MenuReaderVoiceMenuReaderVoice(const FMenuReaderVoice& arg1, const FMenuReaderVoice& arg2) {
    return false;
}

FVector2D UUIBlueprintFunctionLibrary::MeasureStringLength(const FString& TextString, FSlateFontInfo FontInfo) {
    return FVector2D{};
}

void UUIBlueprintFunctionLibrary::LogIntroMessage(UObject* WorldContextObject, FText Message) {
}

FString UUIBlueprintFunctionLibrary::KeyToString(FKey Key) {
    return TEXT("");
}

bool UUIBlueprintFunctionLibrary::IsSteamRunningOnSteamDeck() {
    return false;
}

bool UUIBlueprintFunctionLibrary::IsSteamInBigPictureMode() {
    return false;
}

bool UUIBlueprintFunctionLibrary::IsSpellOrToolBlacklisted(const FString& ItemName) {
    return false;
}

bool UUIBlueprintFunctionLibrary::IsPCPlatform(bool bIsSteamDeckAlsoPC) {
    return false;
}

bool UUIBlueprintFunctionLibrary::IsGameInForeground() {
    return false;
}

bool UUIBlueprintFunctionLibrary::IsBeastMeshReady(AActor* Actor) {
    return false;
}

bool UUIBlueprintFunctionLibrary::IconExistsInTable(const FString& IconTextureName) {
    return false;
}

void UUIBlueprintFunctionLibrary::HideOutlines(APlayerController* PC) {
}

void UUIBlueprintFunctionLibrary::GotoScreenFromCode(const UObject* WorldContextObject, UUserWidget* OldScreenReference, TSubclassOf<UUserWidget> NewScreenClass) {
}

UUserWidget* UUIBlueprintFunctionLibrary::GetWidgetParentOfClass(UWidget* ChildWidget, TSubclassOf<UUserWidget> WidgetClass) {
    return NULL;
}

FText UUIBlueprintFunctionLibrary::GetTimespanTextWithMilliseconds(FTimespan Timespan) {
    return FText::GetEmpty();
}

bool UUIBlueprintFunctionLibrary::GetTimeSinceLastSave(FTimespan& OutTimespan) {
    return false;
}

int32 UUIBlueprintFunctionLibrary::GetSalonChangeCost() {
    return 0;
}

float UUIBlueprintFunctionLibrary::GetPotionDuration(const FName& PotionName) {
    return 0.0f;
}

FTransform UUIBlueprintFunctionLibrary::GetPlayerSpawnLocation(AController* PlayerController) {
    return FTransform{};
}

FVector UUIBlueprintFunctionLibrary::GetNPCCharacterDamageNumberOffset(const ANPC_Character* NPCCharacter) {
    return FVector{};
}

FText UUIBlueprintFunctionLibrary::GetLocalizedDateTimeText(const FDateTime& InDateTime) {
    return FText::GetEmpty();
}

int32 UUIBlueprintFunctionLibrary::GetHousePoints(const FString& HouseName) {
    return 0;
}

float UUIBlueprintFunctionLibrary::GetGamma() {
    return 0.0f;
}

bool UUIBlueprintFunctionLibrary::GetDisplayedPlayTime(const FString& TotalPlayTimeString, FText& OutText) {
    return false;
}

FString UUIBlueprintFunctionLibrary::GetDisplayedMissionIcon(FName MissionID) {
    return TEXT("");
}

FString UUIBlueprintFunctionLibrary::GetCurrentLanguage() {
    return TEXT("");
}

FName UUIBlueprintFunctionLibrary::GetCurrentGamePadControlScheme() {
    return NAME_None;
}

TArray<FIntPoint> UUIBlueprintFunctionLibrary::GetAvailableResolutions() {
    return TArray<FIntPoint>();
}

void UUIBlueprintFunctionLibrary::GetAllPanelChildrenOfWidgetClass(UPanelWidget* PanelWidgetParent, TSubclassOf<UWidget> WidgetClass, TArray<UWidget*>& FoundWidgets) {
}

FVector UUIBlueprintFunctionLibrary::GetActorCalloutComponentOffset(AActor* Actor) {
    return FVector{};
}

float UUIBlueprintFunctionLibrary::GetAbilityDurationRemaining(AActor* AbilityOwner, const FName& AbilityName) {
    return 0.0f;
}

bool UUIBlueprintFunctionLibrary::GetAbilityActive(const AActor* AbilityOwner, const FName& AbilityName) {
    return false;
}

FText UUIBlueprintFunctionLibrary::FloatToFractionalText(float Value, int32 Precision) {
    return FText::GetEmpty();
}

UTexture2D* UUIBlueprintFunctionLibrary::FindIconTexture2D(const FString& IconTextureName) {
    return NULL;
}

bool UUIBlueprintFunctionLibrary::EqualEqual_MenuReaderVoiceMenuReaderVoice(const FMenuReaderVoice& arg1, const FMenuReaderVoice& arg2) {
    return false;
}

bool UUIBlueprintFunctionLibrary::CopyToClipboard(const FString& StringToCopy) {
    return false;
}

bool UUIBlueprintFunctionLibrary::CanUseHippogriff() {
    return false;
}

bool UUIBlueprintFunctionLibrary::CanUseGraphorn() {
    return false;
}

bool UUIBlueprintFunctionLibrary::CanUseBroom(bool bIncludeAvatarState) {
    return false;
}

bool UUIBlueprintFunctionLibrary::AsyncLoadUITexture(TSoftObjectPtr<UTexture2D> TextureRef, const FAsyncUITextureLoadCallback& Callback, UObject* CallbackParam, EUIAsyncLoadPriority Priority) {
    return false;
}

bool UUIBlueprintFunctionLibrary::AsyncLoadFont(FSoftObjectPath FontPath, const FAsyncUIFontLoadCallback& AsyncLoadCallback) {
    return false;
}

void UUIBlueprintFunctionLibrary::AsyncLoadActionSelectionUI() {
}

bool UUIBlueprintFunctionLibrary::AsyncFindIconTexWithCallback(const FString& IconTextureName, const FAsyncUITextureLoadCallback& AsyncLoadCallback, UObject* CallbackParam) {
    return false;
}

bool UUIBlueprintFunctionLibrary::AsyncFindIconTexture2D(const FString& IconTextureName, UImage* InImage, bool MatchSize, EUIAsyncLoadPriority Priority, bool bIsLoadingScreen) {
    return false;
}

bool UUIBlueprintFunctionLibrary::AsyncCreateSpellMiniGame(FName GameName, bool UseDefaultCamera, const FAsyncScreenLoadCallback& AsyncLoadCallback) {
    return false;
}

void UUIBlueprintFunctionLibrary::AddPlayerHousePoints(int32 Points) {
}

void UUIBlueprintFunctionLibrary::AddHousePoints(const FString& HouseName, int32 Points) {
}

UUIBlueprintFunctionLibrary::UUIBlueprintFunctionLibrary() {
}

