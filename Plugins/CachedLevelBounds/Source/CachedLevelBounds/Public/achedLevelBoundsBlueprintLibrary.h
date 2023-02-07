#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EGameFriendlyLevelNameFormat.h"
#include "ELevelBoundsBestHeuristic.h"
#include "InsideOfLevel.h"
#include "LevelBoundsSources.h"
#include "achedLevelBoundsBlueprintLibrary.generated.h"

class UObject;

UCLASS(Blueprintable)
class CACHEDLEVELBOUNDS_API UachedLevelBoundsBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UachedLevelBoundsBlueprintLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void UncachedTotalWorldBounds(UObject* WorldContextObject, FLevelBoundsSources LevelBoundsSources, FBox& WorldBounds);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void TotalWorldBounds(UObject* WorldContextObject, FLevelBoundsSources LevelBoundsSources, bool bRefresh, FBox& WorldBounds);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetInsideOfLevelsSummary(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, FString& SummaryInsideList, int32 MaxLevelsToShow, const FString& Separator, EGameFriendlyLevelNameFormat LevelNameFormat, bool bRemoveIgnoredLevels);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetInsideOfLevelsList(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, TArray<FInsideOfLevel>& InsideOfLevelList);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetInsideOfLevels(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, FString& InsideList, const FString& Separator, EGameFriendlyLevelNameFormat LevelNameFormat, bool bRemoveIgnoredLevels);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetInsideOfLevel(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, FInsideOfLevel& InsideOfLevel);
    
};

