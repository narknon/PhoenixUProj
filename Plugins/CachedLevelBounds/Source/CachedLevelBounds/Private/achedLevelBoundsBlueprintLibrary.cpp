#include "achedLevelBoundsBlueprintLibrary.h"

class UObject;

void UachedLevelBoundsBlueprintLibrary::UncachedTotalWorldBounds(UObject* WorldContextObject, FLevelBoundsSources LevelBoundsSources, FBox& WorldBounds) {
}

void UachedLevelBoundsBlueprintLibrary::TotalWorldBounds(UObject* WorldContextObject, FLevelBoundsSources LevelBoundsSources, bool bRefresh, FBox& WorldBounds) {
}

void UachedLevelBoundsBlueprintLibrary::GetInsideOfLevelsSummary(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, FString& SummaryInsideList, int32 MaxLevelsToShow, const FString& Separator, EGameFriendlyLevelNameFormat LevelNameFormat, bool bRemoveIgnoredLevels) {
}

void UachedLevelBoundsBlueprintLibrary::GetInsideOfLevelsList(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, TArray<FInsideOfLevel>& InsideOfLevelList) {
}

void UachedLevelBoundsBlueprintLibrary::GetInsideOfLevels(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, FString& InsideList, const FString& Separator, EGameFriendlyLevelNameFormat LevelNameFormat, bool bRemoveIgnoredLevels) {
}

void UachedLevelBoundsBlueprintLibrary::GetInsideOfLevel(UObject* WorldContextObject, FVector Position, ELevelBoundsBestHeuristic BestHeuristic, FLevelBoundsSources LevelBoundsSources, FInsideOfLevel& InsideOfLevel) {
}

UachedLevelBoundsBlueprintLibrary::UachedLevelBoundsBlueprintLibrary() {
}

