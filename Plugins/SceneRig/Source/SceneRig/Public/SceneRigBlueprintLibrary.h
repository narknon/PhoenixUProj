#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SceneRigParameters.h"
#include "SceneRigBlueprintLibrary.generated.h"

class ULevelSequence;
class UObject;
class USceneRig;
class USceneRigStageParameterBlock;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USceneRigBlueprintLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static void SetWorldContext(UPARAM(Ref) FSceneRigParameters& InParameter, UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static void SetStageParameters(UPARAM(Ref) FSceneRigParameters& InParameter, USceneRigStageParameterBlock* StageParameterBlock);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RebindSequencePossessableReferences(UObject* WorldContextObject, ULevelSequence* Sequence);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool PlayCinematicFromPath(UObject* WorldContextObject, const FString& InSceneRigPath, FName LevelNameToReturnToWhenFinished, FName DefaultLevelName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="InWorldContextObject"))
    static bool PlayCinematic(UObject* InWorldContextObject, TSoftObjectPtr<USceneRig> InSceneRig, FName InLevelNameToReturnToWhenFinished, FName DefaultLevelName);
    
    UFUNCTION(BlueprintCallable)
    static void AssignTransformParameter(UPARAM(Ref) FSceneRigParameters& InParameter, const FString& ParameterName, const FTransform& InValue);
    
    UFUNCTION(BlueprintCallable)
    static void AssignStringParameter(UPARAM(Ref) FSceneRigParameters& InParameter, const FString& ParameterName, const FString& InValue);
    
    UFUNCTION(BlueprintCallable)
    static void AssignObjectParameter(UPARAM(Ref) FSceneRigParameters& InParameter, const FString& ParameterName, UObject* InValue);
    
    UFUNCTION(BlueprintCallable)
    static void AssignIntParameter(UPARAM(Ref) FSceneRigParameters& InParameter, const FString& ParameterName, int32 InValue);
    
    UFUNCTION(BlueprintCallable)
    static void AssignFloatParameter(UPARAM(Ref) FSceneRigParameters& InParameter, const FString& ParameterName, float InValue);
    
    UFUNCTION(BlueprintCallable)
    static void AssignBoolParameter(UPARAM(Ref) FSceneRigParameters& InParameter, const FString& ParameterName, bool InValue);
    
};

