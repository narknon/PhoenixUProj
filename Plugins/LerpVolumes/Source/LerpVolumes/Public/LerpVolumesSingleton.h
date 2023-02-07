#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ELerpVolumesGetTagValueMode.h"
#include "ELerpVolumesInterpolantType.h"
#include "LerpVolumeInterface.h"
#include "LerpVolumesInterpolants.h"
#include "LerpVolumesInterpolantsEvaluator.h"
#include "LerpVolumesSingleton.generated.h"

class ULerpVolumeFinalInterpolant;
class ULerpVolumeInterpolant;
class UObject;

UCLASS(Blueprintable, NotPlaceable, Transient)
class LERPVOLUMES_API ALerpVolumesSingleton : public AActor, public ILerpVolumeInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<ULerpVolumeInterpolant*> Interpolants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<ULerpVolumeFinalInterpolant*> FinalInterpolants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLerpVolumesInterpolants InterpolantDefaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLerpVolumesInterpolantsEvaluator CurrentState;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLerpVolumesInterpolantsEvaluator LocalState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector LastLocalStatePosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bLastLocalStateValid;
    
public:
    ALerpVolumesSingleton();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesSetWorldVectorDefault(UObject* WorldContextObject, FName VariableName, FVector VariableValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesSetWorldUnitDirectionDefault(UObject* WorldContextObject, FName VariableName, FVector VariableValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesSetWorldTagDefaultName(UObject* WorldContextObject, FName VariableName, FName VariableValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesSetWorldTagDefault(UObject* WorldContextObject, FName VariableName, const FString& VariableValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesSetWorldScalarDefault(UObject* WorldContextObject, FName VariableName, float VariableValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesSetWorldIntegerDefault(UObject* WorldContextObject, FName VariableName, int32 VariableValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesSetWorldColorDefault(UObject* WorldContextObject, FName VariableName, FLinearColor VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesIsWorldVector(UObject* WorldContextObject, FName VariableName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesIsWorldUnitDirection(UObject* WorldContextObject, FName VariableName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesIsWorldTag(UObject* WorldContextObject, FName VariableName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesIsWorldScalar(UObject* WorldContextObject, FName VariableName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesIsWorldInteger(UObject* WorldContextObject, FName VariableName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesIsWorldColor(UObject* WorldContextObject, FName VariableName, bool& bExists);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetWorldVector(UObject* WorldContextObject, FName VariableName, FVector& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetWorldUnitDirection(UObject* WorldContextObject, FName VariableName, FVector& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void LerpVolumesGetWorldType(UObject* WorldContextObject, FName VariableName, ELerpVolumesInterpolantType& VariableType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetWorldTag(UObject* WorldContextObject, FName VariableName, FString& VariableValue, ELerpVolumesGetTagValueMode ValueMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetWorldScalar(UObject* WorldContextObject, FName VariableName, float& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetWorldInteger(UObject* WorldContextObject, FName VariableName, int32& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetWorldColor(UObject* WorldContextObject, FName VariableName, FLinearColor& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetVectorAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FVector& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetUnitDirectionAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FVector& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetTagAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FString& VariableValue, ELerpVolumesGetTagValueMode ValueMode);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetScalarAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, float& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetIntegerAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, int32& VariableValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool LerpVolumesGetColorAtPosition(UObject* WorldContextObject, FVector Position, FName VariableName, FLinearColor& VariableValue);
    
    
    // Fix for true pure virtual functions not being implemented
};

