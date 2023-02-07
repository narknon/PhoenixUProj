#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineTypes.h"
#include "EIsPlayer.h"
#include "ETwoBranches.h"
#include "LandscapeRoadData.h"
#include "Templates/SubclassOf.h"
#include "BlueprintHelper.generated.h"

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

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UBlueprintHelper : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBlueprintHelper();
    UFUNCTION(BlueprintCallable)
    static TArray<FString> SortStrings(TArray<FString> Strings);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> SortNames(TArray<FName> Names);
    
    UFUNCTION(BlueprintCallable)
    static TArray<int32> SortInts(TArray<int32> Ints);
    
    UFUNCTION(BlueprintCallable)
    static bool SkipCriticalLoad();
    
    UFUNCTION(BlueprintCallable)
    static bool SetSceneComponentMobility(USceneComponent* SceneComp, TEnumAsByte<EComponentMobility::Type> NewMobility);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UClass* ResolveSoftClassReference(TSoftClassPtr<UObject> Class);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveDataTableRow(UDataTable* Table, FName RowName);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLandscapeRoadData> RecursiveGetLandscapeRoadsDataFromProxy(ALandscapeProxy* Prxy);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FLandscapeRoadData> RecursiveGetLandscapeRoadsData();
    
    UFUNCTION(BlueprintCallable)
    static bool PositionCameraToFitActor(UCameraComponent* Camera, AActor* Actor, TArray<FString> OnlyTheseComponents, float Padding, float AspectRatio);
    
    UFUNCTION(BlueprintCallable)
    static void LoadSyncronousStaticMesh(TSoftObjectPtr<UStaticMesh> UnloadedMesh, UStaticMesh*& LoadedMesh);
    
    UFUNCTION(BlueprintCallable)
    static void LoadSyncronousActorClass(TSoftClassPtr<AActor> UnloadedClass, TSubclassOf<AActor>& LoadedClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsPointOnCamera(const UObject* WorldContextObject, FVector Point, float MarginPercent, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    static void IsPlayerCharacter(AActor* Actor, EIsPlayer& Branches);
    
    UFUNCTION(BlueprintCallable)
    static bool IsObjectInGameWorld(UObject* Object);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static TArray<FString> GetWorldOptions(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UWorld* GetWorldFromLevelScriptable(ULevel* InLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UWorld* GetWorldFromLevel(ULevel* InLevel);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ULevel* GetPersistentLevel(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ULevel* GetLoadedLevelFromStreamingLevel(ULevelStreaming* InStreamingLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetLevelName(ULevel* InLevel);
    
    UFUNCTION(BlueprintCallable)
    static ULevel* GetLevelFromActorScriptable(AActor* InActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ULevel* GetLevelFromActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ULevel* GetCurrentLevel(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool GetCameraPositionToFitActor(AActor* Actor, FVector CameraDir, float HorizontalFieldOfView, float AspectRatio, FVector& OutCameraPos, FVector& OutTargetPos, TArray<FString> OnlyTheseComponents, float Padding);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetActorBounds(AActor* Actor, FVector& Origin, FVector& BoxExtent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FBox GetActorBoundingBox(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FBox GetAccurateActorBounds(AActor* Actor, TArray<FString> OnlyTheseComponents);
    
    UFUNCTION(BlueprintCallable)
    static bool ForceUnloadLevels();
    
    UFUNCTION(BlueprintCallable)
    static bool ForceSimpleLevels();
    
    UFUNCTION(BlueprintCallable)
    static bool ForceLoadMaps();
    
    UFUNCTION(BlueprintCallable)
    static bool ForceFullLevels();
    
    UFUNCTION(BlueprintCallable)
    static bool FloatCurve_FindTimeFromValue(UCurveFloat* CurveFloat, float InValue, float& OutValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ULevelStreaming* FindLevelStreamingForLevel(ULevel* InLevel);
    
    UFUNCTION(BlueprintCallable)
    static float EvaluateFloatCurve(const FInterpCurveFloat& InterpFloatCurve, float Pos, float DefaultValue);
    
    UFUNCTION(BlueprintCallable)
    static bool DisplayMapName();
    
    UFUNCTION(BlueprintCallable)
    static FInterpCurveFloat CreateFloatCurve(TArray<float> Values);
    
    UFUNCTION(BlueprintCallable)
    static void CompareAgainstHashKey(const FString& S, const int32 Key, ETwoBranches& Branches);
    
};

