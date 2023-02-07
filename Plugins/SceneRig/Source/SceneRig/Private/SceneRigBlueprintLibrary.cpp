#include "SceneRigBlueprintLibrary.h"

class ULevelSequence;
class UObject;
class USceneRig;
class USceneRigStageParameterBlock;

void USceneRigBlueprintLibrary::SetWorldContext(FSceneRigParameters& InParameter, UObject* WorldContext) {
}

void USceneRigBlueprintLibrary::SetStageParameters(FSceneRigParameters& InParameter, USceneRigStageParameterBlock* StageParameterBlock) {
}

void USceneRigBlueprintLibrary::RebindSequencePossessableReferences(UObject* WorldContextObject, ULevelSequence* Sequence) {
}

bool USceneRigBlueprintLibrary::PlayCinematicFromPath(UObject* WorldContextObject, const FString& InSceneRigPath, FName LevelNameToReturnToWhenFinished, FName DefaultLevelName) {
    return false;
}

bool USceneRigBlueprintLibrary::PlayCinematic(UObject* InWorldContextObject, TSoftObjectPtr<USceneRig> InSceneRig, FName InLevelNameToReturnToWhenFinished, FName DefaultLevelName) {
    return false;
}

void USceneRigBlueprintLibrary::AssignTransformParameter(FSceneRigParameters& InParameter, const FString& ParameterName, const FTransform& InValue) {
}

void USceneRigBlueprintLibrary::AssignStringParameter(FSceneRigParameters& InParameter, const FString& ParameterName, const FString& InValue) {
}

void USceneRigBlueprintLibrary::AssignObjectParameter(FSceneRigParameters& InParameter, const FString& ParameterName, UObject* InValue) {
}

void USceneRigBlueprintLibrary::AssignIntParameter(FSceneRigParameters& InParameter, const FString& ParameterName, int32 InValue) {
}

void USceneRigBlueprintLibrary::AssignFloatParameter(FSceneRigParameters& InParameter, const FString& ParameterName, float InValue) {
}

void USceneRigBlueprintLibrary::AssignBoolParameter(FSceneRigParameters& InParameter, const FString& ParameterName, bool InValue) {
}

USceneRigBlueprintLibrary::USceneRigBlueprintLibrary() {
}

