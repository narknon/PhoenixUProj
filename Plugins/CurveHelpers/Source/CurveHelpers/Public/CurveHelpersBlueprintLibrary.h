#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Curves/RealCurve.h"
#include "Curves/CurveFloat.h"
#include "BlueprintCurveKey.h"
#include "CurveHelpersBlueprintLibrary.generated.h"

class AActor;
class UCurveFloat;
class USplineComponent;

UCLASS(Blueprintable)
class CURVEHELPERS_API UCurveHelpersBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UCurveHelpersBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static void ShiftCurve(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    static void SetSplineHasBeenEdited(USplineComponent* Spline, bool bEdited);
    
    UFUNCTION(BlueprintCallable)
    static void SetExternalCurve(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, UCurveFloat* ExternalCurve, bool bCopyToInternal);
    
    UFUNCTION(BlueprintCallable)
    static void SetCurveKeys(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, const TArray<FBlueprintCurveKey>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void SetCurveDefaultValue(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, float DefaultValue);
    
    UFUNCTION(BlueprintCallable)
    static void ScaleCurve(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, float ScaleOrigin, float ScaleFactor);
    
    UFUNCTION(BlueprintCallable)
    static void RunConstructionScripts(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void ResetCurve(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveRedundantCurveKeys(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, float Tolerance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MakeLinearCurveKey(float Time, float Value, FBlueprintCurveKey& Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MakeCurveKeysTriplet(TArray<FBlueprintCurveKey>& Keys, float StartTime, float StartValue, float MidTime, float MidValue, float EndTime, float EndValue, bool bLinear);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MakeCurveKeysSimple(TArray<FBlueprintCurveKey>& Keys, float StartTime, float StartValue, float EndTime, float EndValue, bool bLinear);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MakeCurveKey(float Time, float Value, FBlueprintCurveKey& Key, TEnumAsByte<ERichCurveInterpMode> InterpMode, float ArriveTangent, const float LeaveTangent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void IsUsingExternalCurve(const FRuntimeFloatCurve& RuntimeFloatCurve, bool& bExternalCurve);
    
    UFUNCTION(BlueprintCallable)
    static void InsertCurveKeys(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, const TArray<FBlueprintCurveKey>& Keys);
    
    UFUNCTION(BlueprintCallable)
    static void InsertCurveKey(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, const FBlueprintCurveKey& Key);
    
    UFUNCTION(BlueprintCallable)
    static void GetSplineHasBeenEdited(USplineComponent* Spline, bool& bEdited);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetExternalCurve(const FRuntimeFloatCurve& RuntimeFloatCurve, UCurveFloat*& ExternalCurve);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurveValueRange(const FRuntimeFloatCurve& RuntimeFloatCurve, float& MinValue, float& MaxValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurveTimeRange(const FRuntimeFloatCurve& RuntimeFloatCurve, float& MinTime, float& MaxTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurveKeyTimeValue(const FRuntimeFloatCurve& RuntimeFloatCurve, int32 KeyIndex, float& Time, float& Value, bool& bInRange);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurveKeys(const FRuntimeFloatCurve& RuntimeFloatCurve, TArray<FBlueprintCurveKey>& Keys, int32& KeyCount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurveKeyCount(const FRuntimeFloatCurve& RuntimeFloatCurve, int32& KeyCount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurveKey(const FRuntimeFloatCurve& RuntimeFloatCurve, int32 KeyIndex, FBlueprintCurveKey& Key, bool& bInRange);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetCurveDefaultValue(const FRuntimeFloatCurve& RuntimeFloatCurve, float& DefaultValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void EvalCurve(const FRuntimeFloatCurve& RuntimeFloatCurve, float Time, float& Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void CurveKeyIndexInRange(const FRuntimeFloatCurve& RuntimeFloatCurve, int32 KeyIndex, bool& bInRange);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void CurveHasAnyData(const FRuntimeFloatCurve& RuntimeFloatCurve, bool& bHasAnyData);
    
    UFUNCTION(BlueprintCallable)
    static void ConvertExternalCurve(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve);
    
    UFUNCTION(BlueprintCallable)
    static void CloneCurve(const FRuntimeFloatCurve& SourceRuntimeFloatCurve, FRuntimeFloatCurve& NewRuntimeFloatCurve);
    
    UFUNCTION(BlueprintCallable)
    static void ClearCurveDefaultValue(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve);
    
    UFUNCTION(BlueprintCallable)
    static void AutoSetCurveTangents(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, float Tension);
    
    UFUNCTION(BlueprintCallable)
    static void AppendCurveKey(UPARAM(Ref) FRuntimeFloatCurve& RuntimeFloatCurve, const FBlueprintCurveKey& Key);
    
};

