#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineTypes.h"
#include "NavigationBlueprintLibrary.generated.h"

class AActor;
class UActorComponent;
class UObject;

UCLASS(Blueprintable)
class UNavigationBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UNavigationBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static void UpdateNavigationObstacles(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool TraceWater(UObject* WorldContextObject, const FVector& TraceStart, const FVector& TraceEnd, float Radius, bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore, bool bIgnoreSelf, FHitResult& OutHit);
    
    UFUNCTION(BlueprintCallable)
    static void SwitchDynamicNavigation(AActor* TargetActor, bool bBlock);
    
    UFUNCTION(BlueprintCallable)
    static void SetObjectStateInfoObstacleComponentActive(AActor* TargetActor, bool bActive);
    
    UFUNCTION(BlueprintCallable)
    static void SetCanEverAffectNavigation(UActorComponent* ActorComponent, bool bCanAffectNavigation);
    
    UFUNCTION(BlueprintCallable)
    static void RefreshObjectStateInfoActorObstacles(AActor* TargetActor, bool bForceDynamicSpawnedFlag);
    
};

