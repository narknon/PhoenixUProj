#include "MinimapManager.h"


void UMinimapManager::UnrevealMiniMapInternal() {
}


void UMinimapManager::UnrevealMiniMap(bool InstantIntro, bool ForceUnreveal, bool fromHUD) {
}




void UMinimapManager::SwitchToPlayerPawn() {
}

void UMinimapManager::SwitchToHoverdronePawn(APawn* HoverPawn) {
}

void UMinimapManager::Shutdown() {
}



void UMinimapManager::ShowMiniMap(bool Enable) {
}




void UMinimapManager::SetMiniMapWidgetSize(FVector2D Size) {
}

void UMinimapManager::SetMiniMapSize(float Size, float ZoomTime) {
}

void UMinimapManager::SetMiniMapLevel(EMiniMapLevels::Type LevelType, bool hideCurrentMap, bool ShowMap, bool LoadNavMesh, bool AllowMiniMapReveal) {
}

void UMinimapManager::SetLockMiniMapReveal(bool pLockMiniMapReveal) {
}

void UMinimapManager::SetIsDroneMap(bool pIsDroneMap) {
}


void UMinimapManager::SetIntrusionAlertOn(bool pIntrusionAlertOn) {
}

void UMinimapManager::SetInTentTransition(bool pInTentTransition) {
}

void UMinimapManager::SanctuarySetHubUnlock(const FString& NameOfUnlock) {
}

void UMinimapManager::RevealMiniMapInternalTents() {
}

void UMinimapManager::RevealMiniMapInternal() {
}

void UMinimapManager::RevealMiniMapInstantInternal() {
}


void UMinimapManager::RevealMiniMap(bool InstantIntro, bool fromHUD) {
}

void UMinimapManager::RemoveIntrusionArea(AActor* IntrusionActor) {
}


void UMinimapManager::QuickFadeOutMinimap() {
}


void UMinimapManager::QuickFadeInMinimap() {
}


bool UMinimapManager::IsParentHoverDrone() {
    return false;
}

void UMinimapManager::IconTextureCallback(UTexture2D* Texture, UObject* Param) {
}

void UMinimapManager::HoverdroneToggleMinimap(bool bShowMiniMap) {
}

void UMinimapManager::HandlePlayerAndMapRotation() {
}

void UMinimapManager::HandleMapRotation() {
}

UMinimapTutorial* UMinimapManager::GetTutorialMiniMap() {
    return NULL;
}

UMinimapTents* UMinimapManager::GetTentsMiniMap() {
    return NULL;
}

UMinimapSanctuary* UMinimapManager::GetSanctuaryMiniMap() {
    return NULL;
}

UMinimapOverland* UMinimapManager::GetOverlandMiniMap() {
    return NULL;
}

bool UMinimapManager::GetMiniMapVisibility() {
    return false;
}

float UMinimapManager::GetMiniMapSize() {
    return 0.0f;
}

UMapSubSystem* UMinimapManager::GetMapSubsytem() {
    return NULL;
}

bool UMinimapManager::GetIsDroneMap() {
    return false;
}

bool UMinimapManager::GetIntrusionAlertOn() {
    return false;
}

bool UMinimapManager::GetInTentTransition() {
    return false;
}

UMinimapHogwarts* UMinimapManager::GetHogwartsMiniMap() {
    return NULL;
}

UMinimapHogsmeade* UMinimapManager::GetHogsmeadeMiniMap() {
    return NULL;
}

UMinimapDungeon* UMinimapManager::GetDungeonMiniMap() {
    return NULL;
}

bool UMinimapManager::GetAreIntrusionAreasActive() {
    return false;
}

UMinimapBase* UMinimapManager::GetActiveMiniMap() {
    return NULL;
}

UMinimapBase* UMinimapManager::FindMapByName(const FString& MapName) {
    return NULL;
}



/*void UMinimapManager::BeginPlay() {
}

void UMinimapManager::BeginDestroy() {
}*/

void UMinimapManager::AddMiniMap(UMinimapBase* pMiniMapbase) {
}

void UMinimapManager::AddIntrusionArea(AActor* IntrusionActor) {
}

UMinimapManager::UMinimapManager() {
    this->MaskedIconContainer = NULL;
    this->UnmaskedIconContainer = NULL;
    this->FadeCircle = NULL;
    this->SharedMinimapData = NULL;
    this->IconRange1Arrow = 1000.00f;
    this->IconRange2Arrow = 2000.00f;
    this->IconRange3Arrow = 3000.00f;
    this->IntrusionBlitter = NULL;
    this->IntrusionTexture = NULL;
    this->IntrusionFXActor = NULL;
    this->IconClass = NULL;
    this->IconRenderWidgetClass = NULL;
    this->IconRenderWidgetPulseMaterial = NULL;
    this->IconRenderWidgetGlowMaterial = NULL;
    this->IconRenderWidgetSimpleMaterial = NULL;
    this->IconRenderWidgetPathMaterial = NULL;
    this->IconRenderAreaBeaconMaterial = NULL;
    this->MinimapWidgetClass = NULL;
    this->PlayerPawn = NULL;
    this->PrevPawn = NULL;
    this->PlayerController = NULL;
    this->ActiveMiniMap = NULL;
    this->OverlandMiniMap = NULL;
    this->HogwartsMiniMap = NULL;
    this->HogsmeadeMiniMap = NULL;
    this->DungeonMiniMap = NULL;
    this->TutorialMiniMap = NULL;
    this->SanctuaryMiniMap = NULL;
    this->TentsMiniMap = NULL;
    this->FadingOutMap = NULL;
    this->FadingInMap = NULL;
    this->MiniMapVisible = false;
    this->MinimapCamRotation = 0.00f;
    this->MiniMapPlayerRotation = 0.00f;
    this->PathMaterial = NULL;
    this->PathMaterialDynamic = NULL;
    this->PathImage = NULL;
    this->PathIconList = NULL;
}

