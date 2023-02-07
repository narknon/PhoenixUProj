#include "BlueprintHelper.h"
#include "Templates/SubclassOf.h"

class AActor;
class ALandscapeProxy;
class UCameraComponent;
class UCurveFloat;
class UDataTable;
class ULevel;
class ULevelStreaming;
class UObject;
class USceneComponent;
class UStaticMesh;
class UWorld;

TArray<FString> UBlueprintHelper::SortStrings(TArray<FString> Strings) {
    return TArray<FString>();
}

TArray<FName> UBlueprintHelper::SortNames(TArray<FName> Names) {
    return TArray<FName>();
}

TArray<int32> UBlueprintHelper::SortInts(TArray<int32> Ints) {
    return TArray<int32>();
}

bool UBlueprintHelper::SkipCriticalLoad() {
    return false;
}

bool UBlueprintHelper::SetSceneComponentMobility(USceneComponent* SceneComp, TEnumAsByte<EComponentMobility::Type> NewMobility) {
    return false;
}

UClass* UBlueprintHelper::ResolveSoftClassReference(TSoftClassPtr<UObject> Class) {
    return NULL;
}

void UBlueprintHelper::RemoveDataTableRow(UDataTable* Table, FName RowName) {
}

TArray<FLandscapeRoadData> UBlueprintHelper::RecursiveGetLandscapeRoadsDataFromProxy(ALandscapeProxy* Prxy) {
    return TArray<FLandscapeRoadData>();
}

TArray<FLandscapeRoadData> UBlueprintHelper::RecursiveGetLandscapeRoadsData() {
    return TArray<FLandscapeRoadData>();
}

bool UBlueprintHelper::PositionCameraToFitActor(UCameraComponent* Camera, AActor* Actor, TArray<FString> OnlyTheseComponents, float Padding, float AspectRatio) {
    return false;
}

void UBlueprintHelper::LoadSyncronousStaticMesh(TSoftObjectPtr<UStaticMesh> UnloadedMesh, UStaticMesh*& LoadedMesh) {
}

void UBlueprintHelper::LoadSyncronousActorClass(TSoftClassPtr<AActor> UnloadedClass, TSubclassOf<AActor>& LoadedClass) {
}

bool UBlueprintHelper::IsPointOnCamera(const UObject* WorldContextObject, FVector Point, float MarginPercent, int32 PlayerIndex) {
    return false;
}

void UBlueprintHelper::IsPlayerCharacter(AActor* Actor, EIsPlayer& Branches) {
}

bool UBlueprintHelper::IsObjectInGameWorld(UObject* Object) {
    return false;
}

TArray<FString> UBlueprintHelper::GetWorldOptions(const UObject* WorldContextObject) {
    return TArray<FString>();
}

UWorld* UBlueprintHelper::GetWorldFromLevelScriptable(ULevel* InLevel) {
    return NULL;
}

UWorld* UBlueprintHelper::GetWorldFromLevel(ULevel* InLevel) {
    return NULL;
}

ULevel* UBlueprintHelper::GetPersistentLevel(const UObject* WorldContextObject) {
    return NULL;
}

ULevel* UBlueprintHelper::GetLoadedLevelFromStreamingLevel(ULevelStreaming* InStreamingLevel) {
    return NULL;
}

FString UBlueprintHelper::GetLevelName(ULevel* InLevel) {
    return TEXT("");
}

ULevel* UBlueprintHelper::GetLevelFromActorScriptable(AActor* InActor) {
    return NULL;
}

ULevel* UBlueprintHelper::GetLevelFromActor(AActor* InActor) {
    return NULL;
}

ULevel* UBlueprintHelper::GetCurrentLevel(const UObject* WorldContextObject) {
    return NULL;
}

bool UBlueprintHelper::GetCameraPositionToFitActor(AActor* Actor, FVector CameraDir, float HorizontalFieldOfView, float AspectRatio, FVector& OutCameraPos, FVector& OutTargetPos, TArray<FString> OnlyTheseComponents, float Padding) {
    return false;
}

void UBlueprintHelper::GetActorBounds(AActor* Actor, FVector& Origin, FVector& BoxExtent) {
}

FBox UBlueprintHelper::GetActorBoundingBox(AActor* Actor) {
    return FBox{};
}

FBox UBlueprintHelper::GetAccurateActorBounds(AActor* Actor, TArray<FString> OnlyTheseComponents) {
    return FBox{};
}

bool UBlueprintHelper::ForceUnloadLevels() {
    return false;
}

bool UBlueprintHelper::ForceSimpleLevels() {
    return false;
}

bool UBlueprintHelper::ForceLoadMaps() {
    return false;
}

bool UBlueprintHelper::ForceFullLevels() {
    return false;
}

bool UBlueprintHelper::FloatCurve_FindTimeFromValue(UCurveFloat* CurveFloat, float InValue, float& OutValue) {
    return false;
}

ULevelStreaming* UBlueprintHelper::FindLevelStreamingForLevel(ULevel* InLevel) {
    return NULL;
}

float UBlueprintHelper::EvaluateFloatCurve(const FInterpCurveFloat& InterpFloatCurve, float Pos, float DefaultValue) {
    return 0.0f;
}

bool UBlueprintHelper::DisplayMapName() {
    return false;
}

FInterpCurveFloat UBlueprintHelper::CreateFloatCurve(TArray<float> Values) {
    return FInterpCurveFloat{};
}

void UBlueprintHelper::CompareAgainstHashKey(const FString& S, const int32 Key, ETwoBranches& Branches) {
}

UBlueprintHelper::UBlueprintHelper() {
}

