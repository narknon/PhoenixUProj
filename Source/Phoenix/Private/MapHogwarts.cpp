#include "MapHogwarts.h"
#include "Templates/SubclassOf.h"

class AActor;
class UHogwartsMapScreen;
class UObject;
class UTexture2D;
class UWorld;

void UMapHogwarts::WayPointCallbackHogwarts(UTexture2D* Texture, UObject* Param) {
}

void UMapHogwarts::UnregisterMarkupActor(AActor* Actor) {
}


void UMapHogwarts::ShowPortraitTravel(const TMap<FString, FVector>& Locations) {
}

void UMapHogwarts::SetZoomType(EMapZoomTypes::Type ZoomType) {
}

void UMapHogwarts::SetUseNewIcons(bool pUseNewIcons) {
}

void UMapHogwarts::RegisterMarkupActor(AActor* Actor) {
}

void UMapHogwarts::OverlandMapZoom(float Val) {
}

void UMapHogwarts::OnStartPathing(const UObject* i_caller, uint32 BeaconHandle) {
}

void UMapHogwarts::OnSaveGameLoaded() {
}


void UMapHogwarts::OnMapItemSelected(FString& ItemString, int32 ItemIndex, bool WasCanceled) {
}

void UMapHogwarts::OnCameraBlendComplete() {
}

bool UMapHogwarts::IsBannerActive() {
    return false;
}

bool UMapHogwarts::InHogwartsLocation(FVector Location) {
    return false;
}

bool UMapHogwarts::InHogwarts() {
    return false;
}

void UMapHogwarts::HandleMapLocationChanged(const UObject* Caller, const FString& CurrentMapLocationName) {
}


TEnumAsByte<EMapZoomTypes::Type> UMapHogwarts::GetZoomType(float Zoom) {
    return EMapZoomTypes::MAP_TOOL_TIP_TYPE_INVALID;
}

bool UMapHogwarts::GetUseNewIcons() {
    return false;
}

TArray<FName> UMapHogwarts::GetMissionsForThisRegion() {
    return TArray<FName>();
}

FVector UMapHogwarts::GetMapTransform() {
    return FVector{};
}

UHogwartsMapScreen* UMapHogwarts::GetMapScreenWidget() {
    return NULL;
}

FString UMapHogwarts::GetMapLocationName() {
    return TEXT("");
}

void UMapHogwarts::GetAllActorsWithTag(UWorld* World, FName Tag, TArray<AActor*>& Actors) {
}

void UMapHogwarts::GetAllActorsOfClass(UWorld* World, TSubclassOf<AActor> ActorClass, TArray<AActor*>& Actors) {
}

void UMapHogwarts::CheckLoadedProperly() {
}

void UMapHogwarts::ChangeTier() {
}

float UMapHogwarts::CalulatePathDistance(TArray<FVector> InPathPoints) {
    return 0.0f;
}

void UMapHogwarts::ActivateFastTravelByIcon() {
}

void UMapHogwarts::ActivateFastTravel(const FString& LocationID, FVector FastTravelDestination) {
}

void UMapHogwarts::ActivateBanner(bool ACTIVE) {
}

UMapHogwarts::UMapHogwarts() {
    this->bDebugPathHelper = false;
    this->RegionHoverOverAlpha = 0.10f;
    this->PathDynamicMaterial = NULL;
    this->StartCamera = NULL;
    this->CurrentCamera = NULL;
    this->ShowDebugMapPath = false;
    this->ShowPathDebug = false;
    this->ShowZoneBanner = true;
    this->MapIconTier3ScaleFactor = 0.75f;
    this->MapIconTier4ScaleFactor = 0.75f;
    this->DefaultIconScale = 30.00f;
}

